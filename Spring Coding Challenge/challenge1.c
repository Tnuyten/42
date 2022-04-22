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

//UNIT STRUCT
typedef struct units {
    //Given values
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

    //Calculated values
    int distance_to_base;
    struct units* target;
    struct units* attackers[3];
    int attacker_count;
} unit;

// typedef struct s_hero {
//     int id;
// } hero;

//BASE STRUCT
typedef struct s_base {
    int x;
    int y;
    int health;
    int mana;
} base;

// GLOBAL VARIABLES
unit**  spiders;
int     spidercounter = 0;
unit**  heroes;
int     herocounter = 0;
unit**  enemies;
int     enemycounter = 0;
base*   castle;
base*   enemy_castle;
int turn = 0;

//FUNCTION PROTOTYPES
//      Storage
unit* init_unit(int id, int type, int x, int y, int shield_life, int is_controlled, int health, int vx, int vy, int near_base, int threat_for, int distance_to_base);
void init_base(int x, int y, int health, int mana);
void free_units();
void free_base();
void init_enemy_base();
void add_unit(unit* entity);

//      Scan
unit* scan_entity(int entity_count);
void scan_base(int base_x, int base_y);

//      Debug
void print_spider(int index);
void print_spiders();
void print_hero(int index);
void print_heroes();
void print_enemy(int index);
void print_enemies();

//      Find Targets
void add_target_to_hero(unit* target, unit* hero);
void remove_target_from_hero(unit* hero);
int has_attackers(unit *spider);
unit* get_closest_spider_to_base();
unit* get_closest_spider_to_hero(unit* hero);
unit* get_enemy_hero();
unit* get_enemy_hero_in_base();
unit* get_closest_attacking_spider_enemy();

//      Algo
int distance(int base_x, int base_y, int unit_x, int unit_y);
int distance_to_target(unit *hero);
int distance_to_enemy(unit* entity, unit* enemy);
int distance_to_enemy_base(unit* entity);

//      Hero Actions
void move_to_base(unit *hero);
void move_to_hero_target(unit* hero);
void move_to_target(unit* target);
void move_to_enemy_base();
void move_to(int x, int y);
int cast_wind(unit* hero, unit* target, int x, int y);
int cast_shield(unit* hero, unit* target);
int cast_control(unit* hero, unit* target, int x, int y);


//      Roles
void attacker_behavior(unit* hero);
void defender_behavior(unit* hero);
void collector_behavior(unit* hero);

//FUNCTIONS
// Create a unit
unit* init_unit(int id, int type, int x, int y, int shield_life, int is_controlled, int health, int vx, int vy, int near_base, int threat_for, int distance_to_base)
{
    unit* entity = malloc(sizeof(unit));

    entity->id = id;
    entity->type = type;
    entity->x = x;
    entity->y = y;
    entity->shield_life = shield_life;
    entity->is_controlled = is_controlled;
    entity->health = health;
    entity->vx = vx;
    entity->vy = vy;
    entity->near_base = near_base;
    entity->threat_for = threat_for;

    entity->distance_to_base = distance_to_base;
    entity->target = NULL;
    for(int i = 0; i < 3; i++)
    {
        entity->attackers[i] = NULL;
    }
    entity->attacker_count = 0;

    return entity;
};

// Create the base
void init_base(int x, int y, int health, int mana)
{
    castle = malloc(sizeof(base));
    castle->x = x;
    castle->y = y;
    castle->health = health;
    castle->mana = mana;
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

// Free the base
void free_base()
{
    free(castle);
}

void init_enemy_base(int health, int mana)
{
    enemy_castle = malloc(sizeof(base));
    enemy_castle->x = 17630 - castle->x;
    enemy_castle->y = 9000 - castle->y;
    enemy_castle->health = health;
    enemy_castle->mana = mana;
}

// adds a unit to the proper array.
void add_unit(unit* entity)
{
    if(entity->type == 0)
    {
        if(spidercounter == MAX_SPIDERS)
        {
            fprintf(stderr, "too many spiders\n");
            return ;
        }
        spiders[spidercounter] = entity;
        spidercounter++;
    }
    else if(entity->type == 1)
    {
        heroes[herocounter] = entity;
        herocounter++;
        return ;
    }
    else if(entity->type == 2)
    {
        enemies[enemycounter] = entity;
        enemycounter++;
        return ;
    }
}

// ==================

unit *scan_entity(int entity_count)
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

    int distance_to_base = distance(castle->x, castle->y, x, y);

    unit* entity = init_unit(id, type, x, y, shield_life, is_controlled, health, vx, vy, near_base, threat_for, distance_to_base);
    return entity;
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
    unit *spider = spiders[index];

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
    unit *hero = heroes[index];
    fprintf(stderr, "Hero id: %1d. X: %5d Y: %5d ", hero->id, hero->x, hero->y);
    if(hero->target != NULL)
    {
        fprintf(stderr, "Hero target: %d", hero->target->id);
    }
    fprintf(stderr, "\n");
}

void print_enemies()
{
    for(int i = 0; i < enemycounter; i++)
    {
        print_enemy(i);
    }
    fprintf(stderr, "\n");
}

void print_enemy(int index)
{
    unit *enemy = enemies[index];
    fprintf(stderr, "Enemy id: %1d. X: %5d Y: %5d ", enemy->id, enemy->x, enemy->y);
    fprintf(stderr, "\n");
}

// ==================

void add_target_to_hero(unit* target, unit* hero)
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

void remove_target_from_hero(unit* hero)
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
int has_attackers(unit *spider)
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
unit* get_closest_spider_to_base()
{
    int distance;
    int closest_distance = 50000;
    unit* target = NULL;
    unit* spider;

    for(int i = 0; i < spidercounter; i++)
    {
        spider = spiders[i];
        distance = spider->distance_to_base;
        if(distance < closest_distance && has_attackers(spider) == 0 && spider->threat_for != 2)
        {
            target = spider;
            closest_distance = distance;
        }
    }
    return target;
}

// Gets the closest spider to the hero, that isn't already targeting the enemy base.
unit* get_closest_spider_to_hero(unit* hero)
{
    int distance;
    int closest_distance = 50000;
    unit* target = NULL;
    unit* spider;

    for(int i = 0; i < spidercounter; i++)
    {
        spider = spiders[i];
        distance = distance_to_enemy(hero, spider);
        if(distance < closest_distance && spider->threat_for != 2)
        {
            target = spider;
            closest_distance = distance;
        }
    }
    return target;
}

unit* get_closest_attacking_spider_enemy()
{
    int distance;
    int closest_distance = 50000;
    unit* target = NULL;
    unit* spider;

    for(int i = 0; i < spidercounter; i++)
    {
        spider = spiders[i];
        distance = distance_to_enemy_base(spider);
        if(distance < closest_distance && distance < 4500)
        {
            target = spider;
            closest_distance = distance;
        }
    }
    return target;
}

unit* get_enemy_hero()
{
    return enemies[0];
}

unit* get_enemy_hero_in_base()
{
    unit* enemy;
    for(int i = 0; i < 3; i++)
    {
        enemy = enemies[i];
        if(enemy != NULL)
        {
            if(enemy->distance_to_base < 5500)
            {
                return enemy;
            }
        }
    }
    return NULL;
}

// ==================

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

int distance_to_target(unit *hero)
{
    return distance(hero->x, hero->y, hero->target->x, hero->target->y);
}

int distance_to_enemy(unit* entity, unit* enemy)
{
    return distance(entity->x, entity->y, enemy->x, enemy->y);
}

int distance_to_enemy_base(unit* entity)
{
    return distance(entity->x, entity->y, enemy_castle->x, enemy_castle->y);
}

// ==================

void move_to_base(unit *hero)
{
    int x;
    int y;

    //Dirty stuff, fix this dude.
    if(castle->x == 0)
    {
        x = 2500 * (hero->id + 1);
        y = 10000 - 2500 * (hero->id + 1);
    }
    else
    {
        x = castle->x - 2500 * (hero->id + 1 - 3);
        y = castle->y - (10000 - 2500 * (hero->id + 1 - 3));
    }

    printf("MOVE %d %d\n", x, y);
}

void move_to_hero_target(unit* hero)
{
    printf("MOVE %d %d\n", hero->target->x, hero->target->y);
}

void move_to_target(unit* target)
{
    printf("MOVE %d %d\n", target->x, target->y);
}

void move_to_enemy_base()
{
    int x = enemy_castle->x;
    int y = enemy_castle->y;

    if(x == 0)
    {
        x += 3500;
        y += 3500;
    }
    else {
        x -= 3500;
        y -= 3500;
    }

    printf("MOVE %d %d\n", x, y);
}

void move_to(int x, int y)
{
    printf("MOVE %d %d\n", x, y);
}

void patrol_enemy_perimeter(unit* hero)
{
    static int last_visited = 0;
    int x1, x2, x3, y1, y2, y3, x, y;
    if(castle->x == 0)
    {
        x1 = enemy_castle->x - 7500;
        y1 = enemy_castle->y - 2500;

        x2 = enemy_castle->x - 5000;
        y2 = enemy_castle->y - 5000;

        x3 = enemy_castle->x - 2500;
        y3 = enemy_castle->y - 7500;
    }
    else {
        x1 = enemy_castle->x + 7500;
        y1 = enemy_castle->y + 2500;

        x2 = enemy_castle->x + 5000;
        y2 = enemy_castle->y + 5000;

        x3 = enemy_castle->x + 2500;
        y3 = enemy_castle->y + 7500;
    }

    if(last_visited % 3 == 0)
    {
        x = x1;
        y = y1;
    }
    if(last_visited % 3 == 1)
    {
        x = x2;
        y = y2;
    }
    if(last_visited % 3 == 2)
    {
        x = x3;
        y = y3;
    }

    if(distance(hero->x, hero->y, x, y) < 500)
    {
        last_visited++;
    }

    printf("MOVE %d %d\n", x, y);
}

int cast_wind(unit* hero, unit* target, int x, int y)
{
    if(castle->mana < 10)
        return 0;
    if(distance_to_enemy(hero, target) > 1280)
        return 0;
    if(target->shield_life > 0)
        return 0;

    printf("SPELL WIND %d %d\n", x, y);
    return 1;
}

int cast_shield(unit* hero, unit* target)
{
    if(castle->mana < 10)
        return 0;
    if(distance_to_enemy(hero, target) > 2200)
        return 0;
    if(target->shield_life > 0)
        return 0;

    printf("SPELL SHIELD %d\n", target->id);
    return 1;
}

int cast_control(unit* hero, unit* target, int x, int y)
{
    if(castle->mana < 10)
        return 0;
    if(distance_to_enemy(hero, target) > 2200)
        return 0;
    if(target->shield_life > 0)
        return 0;
    if(target->is_controlled)
        return 0;

    printf("SPELL CONTROL %d %d %d\n", target->id, x, y);
    return 1;
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
    spiders = malloc(sizeof(unit*) * MAX_SPIDERS);
    heroes = malloc(sizeof(unit*) * 3);
    enemies = malloc(sizeof(unit*) * 3);

    while (1)
    {
        // Increment turn counter
        turn++;

        // reset
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
            unit *entity = scan_entity(entity_count);
            add_unit(entity);
        }
        // Hero actions
        defender_behavior(heroes[0]);
        attacker_behavior(heroes[1]);
        collector_behavior(heroes[2]);

        // debug
        print_spiders();
        print_heroes();
        print_enemies();

        free_units();
        free_base();
        free(enemy_castle);
    }
    return 0;
}

void attacker_behavior(unit* hero)
{
    unit* spider;
    if(turn < 100)
    {
        defender_behavior(hero);
        return;
    }
    spider = get_closest_spider_to_hero(hero);
    if(turn > 140)
    {
        if(castle->mana >= 90)
        {
            if(cast_control(hero, spider, enemy_castle->x, enemy_castle->y))
                return;
        }
    }
    if(turn > 175)
    {
        spider = get_closest_attacking_spider_enemy();
        if(spider != NULL)
        {
            if(castle->mana > 50)
            {
                if(cast_shield(hero, spider))
                    return;
            }
        }
        move_to_enemy_base();
        return;
    }
    patrol_enemy_perimeter(hero);
}

void defender_behavior(unit* hero)
{
    unit* target;
    target = get_closest_spider_to_base();
    if(target != NULL)
    {
        add_target_to_hero(target, hero);
        if(target->distance_to_base < 5000)
        {
            if(cast_wind(hero, target, enemy_castle->x, enemy_castle->y))
                return;
        }
        if(turn > 90)
        {
            if(castle->mana >= 50 && target->distance_to_base > 5000)
            {
                if(cast_control(hero, target, enemy_castle->x, enemy_castle->y))
                    return;
            }
        }
        // Default target action
        move_to_hero_target(hero);
        return ;
    }
    // Default action
    move_to_base(hero);
}

// Will try to herd spiders into a corner, then control them all towards the opponent for one big wave.
// Should only collect spiders with the appropriate vector.
void collector_behavior(unit* hero)
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
}

// Chases enemy heroes close to our base to
void chaser_behavior(unit* hero)
{

}

// Mwuhahaha
// void abductor_behavior()
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