
#ifndef ITEMS_H
#define ITEMS_H

#include "weapons.h"

typedef enum ItemType
{
    ITEM_WEAPON,
    ITEM_SHIELD
} ItemType;

typedef struct Item
{
    char *itemName;
    char *itemDescription;
    int value;
    ItemType type;

    union
    {
        Weapon weapon;
        Shield shield;
    } data;

} Item;

extern Item createShieldItem(Shield shield);
extern Item createWeaponItem(Weapon weapon);

#endif