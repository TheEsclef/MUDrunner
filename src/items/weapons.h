#ifndef WEAPONS_H
#define WEAPONS_H

typedef struct Weapon
{
    char *weaponName;
    char *weaponDescription;
    int weaponDamage;
    int value;
} Weapon;

typedef struct Shield
{
    char *shieldName;
    char *shieldDescription;
    int shieldDefence;
    int value;
} Shield;

extern Weapon noWeapon;
extern Shield noShield;

extern Weapon woodenSword;
extern Shield woodenShield;

extern Weapon copperSword;
extern Shield copperShield;

extern Weapon ironSword;
extern Shield ironShield;

extern Weapon steelSword;
extern Shield steelShield;

extern Weapon goldSword;
extern Shield goldShield;

#endif