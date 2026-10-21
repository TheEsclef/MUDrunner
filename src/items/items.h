#ifndef ITEMS_H
#define ITEMS_H

#include "weapons.h"
#include "armor.h"

typedef enum ItemType
{
    ITEM_WEAPON,
    ITEM_SHIELD,
    ITEM_HELMET,
    ITEM_CHESTPLATE,
    ITEM_LEGGINGS
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
        Helmet helmet;
        Chestplate chestplate;
        Leggings leggings;
    } data;

} Item;

extern Item createShieldItem(Shield shield);
extern Item createWeaponItem(Weapon weapon);
extern Item createHelmetItem(Helmet helmet);
extern Item createChestplateItem(Chestplate chestplate);
extern Item createLeggingsItem(Leggings leggings);

#endif