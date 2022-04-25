#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

//MACROS
int MAX_SPIDERS = 80;
int WIND_CAST_RANGE = 1280;
int CONTROL_CAST_RANGE = 2200;
int SHIELD_CAST_RANGE = 2200;
int WIND_RANGE = 2200;
int BASE_DETECTION_RANGE = 5000;

//UNIT STRUCTS
typedef struct s_unit {
	int id;
	int type;
	int x;
	int y;
	int shield_life;
	int is_controlled;
	int health;
	int vx;
	int vy;
	int near_base;
	int threat_for;

	// All
	int speed;
	int distance_to_base;

	// Hero
	struct s_unit* target;

	// Spider
	struct s_unit* attackers[3];
	int attacker_count;

} t_unit;

//BASE STRUCT
typedef struct s_base {
	int x;
	int y;
	int health;
	int mana;
} t_base;

// GLOBAL VARIABLES
t_unit**  spiders;
int     spidercounter = 0;
t_unit**  heroes;
int     herocounter = 0;
t_unit**  enemies;
int     enemycounter = 0;
t_base*   base;
t_base*   enemy_base;
int turn = 0;

//FUNCTION PROTOTYPES
//      Storage
t_unit* init_unit(int id, int type, int x, int y, int shield_life, int is_controlled, int health, int vx, int vy, int near_base, int threat_for, int distance_to_base);
void init_base(int x, int y, int health, int mana);
void init_enemy_base();
void add_unit(t_unit* unit);
void free_units();

//      Scan
t_unit* scan_entity();
void scan_base(int base_x, int base_y);

//      Debug
void print_spider(int index);
void print_spiders();
void print_hero(int index);
void print_heroes();
void print_enemy(int index);
void print_enemies();

//      Find Targets
void add_target_to_hero(t_unit* target, t_unit* hero);
void remove_target_from_hero(t_unit* hero);
int has_attackers(t_unit* spider);
t_unit* get_closest_spider_to_base(t_base* base);
t_unit* get_closest_spider_to_hero(t_unit* hero);
t_unit* get_enemy_hero();
t_unit* get_enemy_hero_near_base(int max_range);
t_unit* get_closest_spider_attacking_enemy();

//      Distance
int distance(int base_x, int base_y, int unit_x, int unit_y);
int distance_unit_unit(t_unit* unit1, t_unit* unit2);
int distance_unit_base(t_unit* unit, t_base* base);

//      Hero Actions
// MOVEMENT
void move_to_base(t_base* base, char* message);
void move_to(int x, int y, char* message);

// Formations
void spread_formation(t_unit* hero, char* message);

// Patrols
void patrol(t_unit* hero, t_base* base);
void patrol_perimeter(t_unit* hero);
void patrol_enemy_perimeter(t_unit* hero);

// CASTING SPELLS
int cast_wind(t_unit* hero, t_unit* target, int x, int y, char* message);
int cast_shield(t_unit* hero, t_unit* target, char* message);
int cast_control(t_unit* hero, t_unit* target, int x, int y, char* message);
int cast(char* spell, t_unit* hero, t_unit* target, int x, int y, char* message);

//      Roles
void goalkeeper_behavior(t_unit* hero);
void attacker_behavior(t_unit* hero);
void defender_behavior(t_unit* hero);
void collector_behavior(t_unit* hero);

// Control state
int controlled(t_unit* hero);

//FUNCTIONS
// Create a unit
t_unit* init_unit(int id, int type, int x, int y, int shield_life, int is_controlled, int health, int vx, int vy, int near_base, int threat_for, int distance_to_base)
{
	t_unit* unit = malloc(sizeof(t_unit));

	//Given Values
	unit->id = id;
	unit->type = type;
	unit->x = x;
	unit->y = y;
	unit->shield_life = shield_life;
	unit->is_controlled = is_controlled;
	unit->health = health;
	unit->vx = vx;
	unit->vy = vy;
	unit->near_base = near_base;
	unit->threat_for = threat_for;

	// Added values
	// All
	unit->distance_to_base = distance_to_base;

	// Spider
    for(int i = 0; i < 3; i++)
    {
        unit->attackers[i] = NULL;
    }
    unit->attacker_count = 0;

    if(type == 0)
	{
		unit->speed = 400;
	}

	// Hero
    unit->target = NULL;
	if(type == 1 || type == 2)
	{
		unit->speed = 800;
	}

	return unit;
};

// Create the base
void init_base(int x, int y, int health, int mana)
{
	base = malloc(sizeof(t_base));
	base->x = x;
	base->y = y;
	base->health = health;
	base->mana = mana;
}

void init_enemy_base(int health, int mana)
{
	enemy_base = malloc(sizeof(t_base));
	enemy_base->x = 17630 - base->x;
	enemy_base->y = 9000 - base->y;
	enemy_base->health = health;
	enemy_base->mana = mana;
}

// Free all units and heroes
void free_units()
{
	for(int i = 0; i < spidercounter; i++)
	{
		free(spiders[i]);
	}
	for(int i = 0; i < herocounter; i++)
	{
		free(heroes[i]);
	}
	for(int i = 0; i < enemycounter; i++)
	{
		free(enemies[i]);
	}
}

// adds a unit to the proper array.
void add_unit(t_unit* unit)
{
	if(unit->type == 0)
	{
		spiders[spidercounter] = unit;
		spidercounter++;
	}
	else if(unit->type == 1)
	{
		heroes[herocounter] = unit;
		herocounter++;
	}
	else if(unit->type == 2)
	{
		enemies[enemycounter] = unit;
		enemycounter++;
	}
}

// ==================

t_unit* scan_entity()
{
	// Unique identifier
	int id;
	// 0=monster, 1=your hero, 2=opponent hero
	int type;
	// Position of this entity
	int x;
	int y;
	// Ignore for this league; Count down until shield spell fades
	int shield_life;
	// Ignore for this league; Equals 1 when this entity is under a control spell
	int is_controlled;
	// Remaining health of this monster
	int health;
	// Trajectory of this monster
	int vx;
	int vy;
	// 0=monster with no target yet, 1=monster targeting a base
	int near_base;
	// Given this monster's trajectory, is it a threat to 1=your base, 2=your opponent's base, 0=neither
	int threat_for;
	scanf("%d%d%d%d%d%d%d%d%d%d%d", &id, &type, &x, &y, &shield_life, &is_controlled, &health, &vx, &vy, &near_base, &threat_for);

	int distance_to_base = distance(base->x, base->y, x, y);

	return init_unit(id, type, x, y, shield_life, is_controlled, health, vx, vy, near_base, threat_for, distance_to_base);
}

void scan_base(int base_x, int base_y)
{
	// Your base health
	int health;
	// Ignore in the first league; Spend ten mana to cast a spell
	int mana;
	// SCANS FOR BOTH BASES.

	// Base:
	scanf("%d%d", &health, &mana);
	init_base(base_x, base_y, health, mana);

	// Enemy base:
	scanf("%d%d", &health, &mana);
	init_enemy_base(health, mana);
}

// ==================

void print_spiders()
{
	fprintf(stderr, "\nspidercount: %d\n", spidercounter);
	for(int i = 0; i < spidercounter; i++)
	{
		print_spider(i);
	}
	fprintf(stderr, "\n");
}

void print_spider(int index)
{
	t_unit* spider = spiders[index];

	fprintf(stderr, "Spider id: %3d. X: %5d Y: %5d ", spider->id, spider->x, spider->y);
	if(has_attackers(spider) > 0)
	{
		fprintf(stderr, "Spider attacked by: ");
		for(int i = 0; i < 3; i++)
		{
			if(spider->attackers[i] != NULL)
			{
				fprintf(stderr, "%d ", spider->attackers[i]->id);
			}
		}
	}
	fprintf(stderr, "\n");
}

void print_heroes()
{
	for(int i = 0; i < herocounter; i++)
	{
		print_hero(i);
	}
	fprintf(stderr, "\n");
}

void print_hero(int index)
{
	t_unit* hero = heroes[index];
	fprintf(stderr, "Hero id: %1d. X: %5d Y: %5d ", hero->id, hero->x, hero->y);
	if(hero->target != NULL)
	{
		fprintf(stderr, "Hero target: %d", hero->target->id);
	}
	fprintf(stderr, "\n");
}

void print_enemies()
{
	for(int i = 0; i < 3; i++)
	{
		print_enemy(i);
	}
	fprintf(stderr, "\n");
}

void print_enemy(int index)
{
	t_unit* enemy = enemies[index];
    if(enemy == NULL)
        return;
	fprintf(stderr, "Enemy id: %1d. X: %5d Y: %5d ", enemy->id, enemy->x, enemy->y);
	fprintf(stderr, "\n");
}

// ==================

void add_target_to_hero(t_unit* target, t_unit* hero)
{
	if(target == NULL || hero == NULL)
	{
		if(target == NULL)
			fprintf(stderr, "NULL target given to function add_target_to_hero");
		if(hero == NULL)
			fprintf(stderr, "NULL hero given to function add_target_to_hero");
		return ;
	}

	hero->target = target;
	target->attackers[target->attacker_count] = hero;
	target->attacker_count++;
}

void remove_target_from_hero(t_unit* hero)
{
	if(hero == NULL)
	{
		fprintf(stderr, "NULL hero given to function remove_target_from_heroes");
		return ;
	}
	if(hero->target)
	{
		for(int i = 0; i < 3; i++)
		{
			if(hero->target->attackers[i] == hero)
			{
				hero->target->attackers[i] = NULL;
			}
		}
	}
	hero->target = NULL;
}

// return the number of friendly heroes attacking this spider unit.
int has_attackers(t_unit* spider)
{
	if(spider == NULL)
	{
		fprintf(stderr, "NULL spider given to function has_attackers");
		return -1;
	}
	if(spider->type != 0)
	{
		fprintf(stderr, "Non-spider type given to has_attackers");
		return -1;
	}

	int attackers = 0;
	for(int i = 0; i < 3; i++)
	{
		if(spider->attackers[i] != NULL)
		{
			attackers++;
		}
	}
	return attackers;
}

// Gets the closest spider to the base, that isn't already being attacked by another friendly hero.
t_unit* get_closest_spider_to_base(t_base* base)
{
	int distance;
	int closest_distance = 50000;
	t_unit* target = NULL;
	t_unit* spider;

	for(int i = 0; i < spidercounter; i++)
	{
		spider = spiders[i];
		distance = distance_unit_base(spider, base);
		if(distance < closest_distance && has_attackers(spider) == 0)
		{
			target = spider;
			closest_distance = distance;
		}
	}
	return target;
}

// Gets the closest spider to the hero, that isn't already being attacked by another friendly hero.
t_unit* get_closest_spider_to_hero(t_unit* hero)
{
	int distance;
	int closest_distance = 50000;
	t_unit* target = NULL;
	t_unit* spider;

	for(int i = 0; i < spidercounter; i++)
	{
		spider = spiders[i];
		distance = distance_unit_unit(hero, spider);
		if(distance < closest_distance && has_attackers(spider))
		{
			target = spider;
			closest_distance = distance;
		}
	}
	return target;
}

t_unit* get_closest_spider_attacking_enemy()
{
	int distance;
	int closest_distance = 50000;
	t_unit* target = NULL;
	t_unit* spider;

	for(int i = 0; i < spidercounter; i++)
	{
		spider = spiders[i];
		distance = distance_unit_base(spider, enemy_base);
		if(distance < closest_distance)
		{
			target = spider;
			closest_distance = distance;
		}
	}
	return target;
}

t_unit* get_enemy_hero_near_base(int max_range)
{
	t_unit* enemy;
	for(int i = 0; i < 3; i++)
	{
		enemy = enemies[i];
		if(enemy != NULL)
		{
			if(enemy->distance_to_base < max_range)
			{
				return enemy;
			}
		}
	}
	return NULL;
}

// ==================
// DISTANCE
// Calculates the distance between two points.
int distance(int x1, int y1, int x2, int y2)
{
	int distance;
	int dx;
	int dy;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);

	distance = sqrt(dx*dx + dy*dy);
	return distance;
}
int distance_unit_unit(t_unit* unit1, t_unit* unit2)
{
	return distance(unit1->x, unit1->y, unit2->x, unit2->y);
}
int distance_unit_base(t_unit* unit, t_base* base)
{
	return distance(unit->x, unit->y, base->x, base->y);
}

// ==================
// MOVEMENT

void move_to_base(t_base* base, char* message)
{
	int x = base->x;
	int y = base->y;

	if(x == 0)
	{
		x += 3500;
		y += 3500;
	}
	else {
		x -= 3500;
		y -= 3500;
	}

	move_to(x, y, message);
}

void move_to_unit(t_unit* destination, char* message)
{
    move_to(destination->x, destination->y, message);
}

void move_to(int x, int y, char* message)
{
	if(message == NULL)
	{
		printf("MOVE %d %d\n", x, y);
		return;
	}
	printf("MOVE %d %d %s\n", x, y, message);
}

// Formation

void spread_formation(t_unit* hero, char* message)
{
	int x;
	int y;

	//Dirty stuff, fix this dude.
	if(base->x == 0)
	{
		x = 2500 * (hero->id + 1);
		y = 10000 - 2500 * (hero->id + 1);
	}
	else
	{
		x = base->x - 2500 * (hero->id + 1 - 3);
		y = base->y - (10000 - 2500 * (hero->id + 1 - 3));
	}

	move_to(x, y, message);
}

// Patrol

void patrol(t_unit* hero, t_base* base)
{
	(void)hero;
	(void)base;
}

void patrol_perimeter(t_unit* hero)
{
	(void)hero;
}

void patrol_enemy_perimeter(t_unit* hero)
{
	static int last_visited = 0;
	int x1, x2;//, x3;
	int y1, y2;//, y3;
	int x, y;

	if(base->x == 0)
	{
		x1 = enemy_base->x - 7500;
		y1 = enemy_base->y - 2500;

		x2 = enemy_base->x - 5000;
		y2 = enemy_base->y - 5000;
	}
	else
	{
		x1 = enemy_base->x + 7500;
		y1 = enemy_base->y + 2500;

		x2 = enemy_base->x + 5000;
		y2 = enemy_base->y + 5000;

	}
	if(last_visited % 2 == 0)
	{
		x = x1;
		y = y1;
	}
	if(last_visited % 2 == 1)
	{
		x = x2;
		y = y2;
	}

	char *message;
	if(last_visited % 2 == 0)
		message = "0";
	else
		message = "1";

	if(distance(hero->x, hero->y, x, y) == 0)
		last_visited++;
	move_to(x, y, message);
}

// CASTING SPELLS

int cast_wind(t_unit* hero, t_unit* target, int x, int y, char* message)
{
	if(distance_unit_unit(hero, target) >= 1280)
		return 0;

	return cast("WIND", hero, target, x, y, message);
}

int cast_shield(t_unit* hero, t_unit* target, char* message)
{
	if(distance_unit_unit(hero, target) >= 2200)
		return 0;
	if(target->type == 0 && target->threat_for == 1)
		return 0;

	return cast("SHIELD", hero, target, 0, 0, message);
}

int cast_control(t_unit* hero, t_unit* target, int x, int y, char* message)
{
	if(distance_unit_unit(hero, target) >= 2200)
		return 0;

	return cast("CONTROL", hero, target, x, y, message);
}

int cast(char* spell, t_unit* hero, t_unit* target, int x, int y, char* message)
{
    if(base->mana < 10)
        return 0;
    if(target->shield_life > 0)
        return 0;

	if(strcmp(spell, "WIND") == 0)
		return printf("SPELL WIND %d %d %s \n", x, y, message);
	if(strcmp(spell, "SHIELD") == 0)
		return printf("SPELL SHIELD %d %s \n", target->id, message);
	if(strcmp(spell, "CONTROL") == 0)
		return printf("SPELL CONTROL %d %d %d %s \n", target->id, x, y, message);

	return 0;
}
// ==================

int main()
{
	// The corner of the map representing your base
	int base_x;
	int base_y;
	scanf("%d%d", &base_x, &base_y);

	// Always 3
	int heroes_per_player;
	scanf("%d", &heroes_per_player);

	// Initialize global arrays
	spiders = malloc(sizeof(t_unit*) * MAX_SPIDERS);
	heroes = malloc(sizeof(t_unit*) * 3);
	enemies = malloc(sizeof(t_unit*) * 3);

	while (1)
	{
		// Increment turn counter
		turn++;

        // Reset global arrays
        bzero(spiders, sizeof(t_unit*) * MAX_SPIDERS);
        bzero(heroes, sizeof(t_unit*) * 3);
        bzero(enemies, sizeof(t_unit*) * 3);

		// Reset unit counters
		spidercounter = 0;
		herocounter = 0;
		enemycounter = 0;

		// Scan base
		scan_base(base_x, base_y);

		// Scan visible units
		int entity_count;
		scanf("%d", &entity_count);
		for (int i = 0; i < entity_count; i++)
		{
			add_unit(scan_entity());
		}
		// Hero actions
		goalkeeper_behavior(heroes[0]);
		defender_behavior(heroes[1]);
		attacker_behavior(heroes[2]);

		// debug
		print_spiders();
		print_heroes();
		print_enemies();

		free_units();
		free(base);
		free(enemy_base);
	}
	return 0;
}

void attacker_behavior(t_unit* hero)
{
	// if(turn < 100)
	// {
	// 	defender_behavior(hero);
	// 	return ;
	// }

    // t_unit* target = get_closest_spider_to_base(enemy_base);
    // add_target_to_hero(target, hero);

    // if(target == NULL)
    // {
    //     patrol_enemy_perimeter(hero);
    //     return ;
    // }
	// if(distance_unit_unit(hero, target) < 1000)
	// {
	// 	patrol_enemy_perimeter(hero);
	// 	return ;
	// }

	// if(turn > 140)
	// {
	// 	if(base->mana >= 200)
	// 	{
	// 		if(cast_control(hero, target, enemy_base->x, enemy_base->y, ""))
	// 			return ;
	// 	}
	// }
	// if(turn > 175)
	// {
	// 	target = get_closest_spider_attacking_enemy();
	// 	if(target != NULL)
	// 	{
	// 		if(base->mana > 100)
	// 		{
	// 			if(cast_shield(hero, target, ""))
	// 				return ;
	// 		}

	// 	}
	// 	move_to_base(enemy_base, "");
	// 	return;
	// }
	// patrol_enemy_perimeter(hero);
    defender_behavior(hero);
    return ;
}

void goalkeeper_behavior(t_unit* hero)
{
    int AVOID_RANGE = BASE_DETECTION_RANGE + CONTROL_CAST_RANGE;
    t_unit* enemy_hero = get_enemy_hero_near_base(AVOID_RANGE);

    if(!enemy_hero)
    {
        defender_behavior(hero);
        return ;
    }

    fprintf(stderr, "enemy found: %d", enemy_hero->id);

    if(distance_unit_unit(hero, enemy_hero) < CONTROL_CAST_RANGE)
    {
        if(hero->shield_life == 0)
        {
            if(cast_shield(hero, hero, "protec0"))
                return ;
        }
        if(base->mana > 100)
        {
            if(cast_control(hero, enemy_hero, enemy_base->x, enemy_base->y, "Shoo!"))
                return ;
        }
    }

    defender_behavior(hero);
    return ;
}

void defender_behavior(t_unit* hero)
{
    if(controlled(hero))
    {
        return ;
    }

	t_unit* spider;

	spider = get_closest_spider_to_base(base);
	if(spider == NULL)
	{
		spread_formation(hero, "");
		return ;
	}
	add_target_to_hero(spider, hero);

	int hits_to_kill_spider = spider->health / 2;
	int hero_behind_spider = spider->distance_to_base > hero->distance_to_base;
	int dtt = distance_unit_unit(hero, hero->target);
	int turns_to_reach_spider = dtt / hero->speed - 1;
	int turns_to_kill_spider = spider->health / 2;
	int turns_to_reach_base = spider->distance_to_base / spider->speed;
	int turns_to_blow_range = (dtt - 1280) / hero->speed - 1;
	int spider_will_reach_base_before_death = (spider->threat_for == 1 && turns_to_reach_base <= hits_to_kill_spider + 5);

	// if(turns_to_blow_range > turns_to_reach_base)
	// {
	// 	if(cast_control(hero, spider, enemy_base->x, enemy_base->y, "Protec3"))
	// 		return ;
	// 	spread_formation(hero, "We got a runner!");
	// 	return ;
	// }
	if(spider_will_reach_base_before_death)
	{
        int distance_to_hero = distance_unit_unit(spider, hero);
		if(cast_wind(hero, spider, enemy_base->x, enemy_base->y, "YEET"))
			return ;
	}
	if(turn > 90)
	{
		if(base->mana >= 300 && spider->distance_to_base > 4998 && spider->threat_for != 2)
		{
			if(cast_control(hero, spider, enemy_base->x, enemy_base->y, "Go!"))
				return ;
		}
	}

	// Default action
	move_to_unit(spider, "");
	return ;
}

// Will try to herd spiders into a corner, then control them all towards the opponent for one big wave.
// Should only collect spiders with the appropriate vector.
void collector_behavior(t_unit* hero)
{
	// unit* enemy;

	// enemy = get_enemy_hero_in_base();
	// // Enemy spotted.
	// if(enemy != NULL)
	// {
	//     if(turn > 55 && distance_to_enemy(hero, enemy) <= 1280)
	//     {
	//         if(castle->mana >= 50 && hero->shield_life == 0)
	//         {
	//             if(cast_shield(hero, hero))
	//                 return ;
	//         }
	//     }
	// }
	// Default action
	defender_behavior(hero);
    return ;
}

// Chases enemy heroes close to our base to
void chaser_behavior(t_unit* hero)
{
	defender_behavior(hero);
	return ;
}

// void abductor_behavior(t_unit* hero)
// {
//         if(turn < 55 && (enemy->vx > 0 || enemy->vy > 0))
//         {
//             if(distance(hero->x, hero->y, enemy->x, enemy->y) > 1200)
//             {
//                 move_to_target(enemy);
//                 return ;
//             }
//             else
//             {
//                 if(cast_wind(castle->x, castle->y)) return;
//             }
//         }
// }

// Choice of implementation requires a variable for each hero. Fix this?!
int controlled(t_unit* hero)
{
    static int was_controlled1 = 0;
    static int was_controlled2 = 0;
    static int was_controlled3 = 0;

    if(hero->id == 0 || hero->id == 3)
    {
        if(hero->is_controlled)
        {
            was_controlled1++;
        }
        if(was_controlled1)
        {
            return cast_shield(hero, hero, "No.");
        }
    }

    if(hero->id == 1 || hero->id == 4)
    {
        if(hero->is_controlled)
        {
            was_controlled2++;
        }
        if(was_controlled2)
        {
            return cast_shield(hero, hero, "No.");
        }
    }

    if(hero->id == 2 || hero->id == 5)
    {
        if(hero->is_controlled)
        {
            was_controlled3++;
        }
        if(was_controlled3)
        {
            return cast_shield(hero, hero, "No.");
        }
    }

    return 0;
}