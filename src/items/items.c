#include "items.h"

Item createWeaponItem(Weapon weapon)
{
    Item item = {
        .itemName = weapon.weaponName,
        .itemDescription = weapon.weaponDescription,
        .value = weapon.value,
        .type = ITEM_WEAPON,
        .data.weapon = weapon
    };

    return item;
}

Item createShieldItem(Shield shield)
{
    Item item = {
        .itemName = shield.shieldName,
        .itemDescription = shield.shieldDescription,
        .value = shield.value,
        .type = ITEM_SHIELD,
        .data.shield = shield
    };

    return item;
}