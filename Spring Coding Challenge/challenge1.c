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
int MAX_MOBS = 50;
int HERO_COUNT = 3;

//UNIT STRUCT
typedef struct units {
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

    int distance_to_base;
    struct units* target;
    struct units* attackers[3];
} unit;

//BASE STRUCT
typedef struct s_base {
    int x;
    int y;
    int health;
    int mana;
} base;

// GLOBAL VARIABLES
unit** mobs;
unit** heroes;
unit** targets;
int mobcounter = 0;
int herocounter = 0;
int targetcounter = 0;

base* castle;

//FUNCTION PROTOTYPES
//      Main storage
unit* init_unit(int id, int type, int x, int y, int shield_life, int is_controlled, int health, int vx, int vy, int near_base, int threat_for, int distance_to_base);
base* init_base(int x, int y, int health, int mana);
void free_units();
void free_base();
void add_unit(unit* entity);

//      debug
void print_mob(int index);
void print_mobs();
void print_hero(int index);
void print_heroes();

//      algo
int has_attackers(unit *mob);
void move_to_base(unit *hero);
unit* get_closest_target_to_base();
void assign_target_to_hero(unit* target, unit* hero);
void remove_target_from_hero(unit* hero);
int distance(int base_x, int base_y, int unit_x, int unit_y);


//FUNCTIONS
// Create a unit
unit* init_unit(int id, int type, int x, int y, int shield_life, int is_controlled, int health, int vx, int vy, int near_base, int threat_for, int distance_to_base)
{
    unit* mob = malloc(sizeof(unit));

    mob->id = id;
    mob->type = type;
    mob->x = x;
    mob->y = y;
    mob->shield_life = shield_life;
    mob->is_controlled = is_controlled;
    mob->health = health;
    mob->vx = vx;
    mob->vy = vy;
    mob->near_base = near_base;
    mob->threat_for = threat_for;

    mob->distance_to_base = distance_to_base;
    mob->target = NULL;
    for(int i = 0; i < HERO_COUNT; i++)
    {
        mob->attackers[i] = NULL;
    }

    return mob;
};

// Create the base
base* init_base(int x, int y, int health, int mana)
{
    base* basis = malloc(sizeof(base));
    basis->x = x;
    basis->y = y;
    basis->health = health;
    basis->mana = mana;

    return basis;
}

// Free a unit
void free_units()
{
    for(int i = 0; i < mobcounter; i++)
    {
        free(mobs[i]);
    }
    for(int i = 0; i < herocounter; i++)
    {
        free(heroes[i]);
    }
}

// Free the base
void free_base()
{
    free(castle);
}

// adds a unit to the proper array.
void add_unit(unit* entity)
{
    if(entity->type == 0)
    {
        if(mobcounter == MAX_MOBS)
        {
            fprintf(stderr, "too many mobs\n");
            return ;
        }
        mobs[mobcounter] = entity;
        mobcounter++;
    }
    else if(entity->type == 1)
    {
        heroes[herocounter] = entity;
        herocounter++;
        return ;
    }
    else if(entity->type == 2)
    {
        return ;
    }
}

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

// Find the 3 targets closest to the base and put them in the global targets array.
void find_3_targets()
{

}

// Gets the closest target to the base, that isn't already being attacked by a friendly hero.
unit* get_closest_target_to_base()
{
    int distance;
    int closest_distance = 50000;
    unit* target = NULL;
    unit* mob;

    for(int i = 0; i < mobcounter; i++)
    {
        mob = mobs[i];
        distance = mob->distance_to_base;
        if(distance < closest_distance && has_attackers(mob) == 0)
        {
            target = mob;
            closest_distance = distance;
        }
    }
    return target;
}

// return the number of friendly heroes attacking this mob unit.
int has_attackers(unit *mob)
{
    if(mob == NULL)
    {
        fprintf(stderr, "NULL mob given to function has_attackers");
        return -1;
    }
    if(mob->type != 0)
    {
        fprintf(stderr, "Non-mob type given to has_attackers... You fucked up!");
        return -1;
    }

    int attackers = 0;
    for(int i = 0; i < HERO_COUNT; i++)
    {
        if(mob->attackers[i] != NULL)
        {
            attackers++;
        }
    }
    return attackers;
}

void assign_target_to_hero(unit* target, unit* hero)
{
    if(target == NULL || hero == NULL)
    {
        if(target == NULL)
            fprintf(stderr, "NULL target given to function assign_target_to_hero");
        if(hero == NULL)
            fprintf(stderr, "NULL hero given to function assign_target_to_hero");
        return ;
    }

    hero->target = target;
    target->attackers[hero->id] = hero;
}

void remove_target_from_hero(unit* hero)
{
    if(hero == NULL)
    {
        fprintf(stderr, "NULL hero given to function remove_target_from_heroes");
        return ;
    }

    unit *target = hero->target;
    if(target)
    {
        target->attackers[hero->id] = NULL;
    }
    hero->target = NULL;
}

void print_mobs()
{
    fprintf(stderr, "\nMobcount: %d\n", mobcounter);
    for(int i = 0; i < mobcounter; i++)
    {
        print_mob(i);
    }
}

void print_mob(int index)
{
    unit *mob = mobs[index];

    fprintf(stderr, "Mob id: %3d. X: %5d Y: %5d ", mob->id, mob->x, mob->y);
    if(has_attackers(mob) > 0)
    {
        fprintf(stderr, "Mob is attacked by hero(es): ");
        for(int i = 0; i < HERO_COUNT; i++)
        {
            if(mob->attackers[i] != NULL)
            {
                fprintf(stderr, "%d ", mob->attackers[i]->id);
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

void move_to_base(unit *hero)
{
    int x = castle->x + 2000 * (hero->id+1);
    int y = castle->y + (8000 - 2000 * (hero->id+1));

    printf("MOVE %d %d\n", x, y);
}

int main()
{
    // The corner of the map representing your base
    int base_x;
    int base_y;

    scanf("%d%d", &base_x, &base_y);
    // Always 3
    int heroes_per_player;
    scanf("%d", &heroes_per_player);

    mobs = malloc(sizeof(unit*) * MAX_MOBS);
    heroes = malloc(sizeof(unit*) * 3);
    targets = malloc(sizeof(unit*) * 3);

    // game loop
    while (1)
    {
        mobcounter = 0;
        herocounter = 0;
        targetcounter = 0;

        // Your base health
        int health;
        // Ignore in the first league; Spend ten mana to cast a spell
        int mana;
        for (int i = 0; i < 2; i++)
        {
            scanf("%d%d", &health, &mana);
        }
        castle = init_base(base_x, base_y, health, mana);

        // Amount of heros and monsters you can see
        int entity_count;
        scanf("%d", &entity_count);
        for (int i = 0; i < entity_count; i++)
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

            int distance_to_base = distance(base_x, base_y, x, y);
            unit* entity = init_unit(id, type, x, y, shield_life, is_controlled, health, vx, vy, near_base, threat_for, distance_to_base);
            add_unit(entity);
        }

        print_mobs();
        fprintf(stderr, "\n");
        print_heroes();

        for (int i = 0; i < heroes_per_player; i++)
        {
            unit *hero = heroes[i];
            unit *target;

            remove_target_from_hero(hero);

            if(mobcounter != 0)
            {
                target = get_closest_target_to_base();
                if(target == NULL)
                {
                    move_to_base(hero);
                    // target = heroes[0]->target;
                    continue ;
                }

                assign_target_to_hero(target, hero);
                printf("MOVE %d %d\n", hero->target->x - 340, hero->target-> y - 340);
            }
            else
            {
                move_to_base(hero);
            }
            // In the first league: MOVE <x> <y> | WAIT; In later leagues: SPELL <spellParams>;
        }

        free_units();
        free_base();
    }
    return 0;
}
