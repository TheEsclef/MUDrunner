#include "items.h"

/*
    THIS HERE IS USED FOR CONVERTING ITEMS INSIDE BAGS
    INTO ACTUAL WEAPONS THE PLAYER CAN EQUIP
    ONCE THE PLAYER CALLS THE EQUIP FUNCTION, THE ITEM OBJECT GETS TURNED INTO
    IT'S WEAPON/ARMOR TYPE TO PROVIDE BONUSES TO THE PLAYER
*/

Item createWeaponItem(Weapon weapon)
{
    Item item = {
        .itemName = weapon.weaponName,
        .itemDescription = weapon.weaponDescription,
        .value = weapon.value,
        .type = ITEM_WEAPON,
        .data.weapon = weapon};

    return item;
}

Item createShieldItem(Shield shield)
{
    Item item = {
        .itemName = shield.shieldName,
        .itemDescription = shield.shieldDescription,
        .value = shield.value,
        .type = ITEM_SHIELD,
        .data.shield = shield};

    return item;
}

Item createHelmetItem(Helmet helmet)
{
    Item item = {
        .itemName = helmet.itemName,
        .itemDescription = helmet.itemDescription,
        .value = helmet.value,
        .type = ITEM_HELMET,
        .data.helmet = helmet};

    return item;
}

Item createChestplateItem(Chestplate chestplate)
{
    Item item = {
        .itemName = chestplate.itemName,
        .itemDescription = chestplate.itemDescription,
        .value = chestplate.value,
        .type = ITEM_CHESTPLATE,
        .data.chestplate = chestplate};

    return item;
}

Item createLeggingsItem(Leggings leggings)
{
    Item item = {
        .itemName = leggings.itemName,
        .itemDescription = leggings.itemDescription,
        .value = leggings.value,
        .type = ITEM_LEGGINGS,
        .data.leggings = leggings};

    return item;
}