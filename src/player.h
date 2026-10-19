#ifndef PLAYER_H
#define PLAYER_H
#include "items/items.h"

typedef struct Backpack
{
    int maxSlots;
    int slotsUsed;
    int totalValue;
    Item *items;
} Backpack;

typedef struct Gear
{
    Weapon weapon;
    Shield shield;

    // TO DO
    // helmet
    // chest
    // leggings
    // gloves
    // boots
    // ring
    // necklace
} Gear;

typedef struct Player
{
    char *playerName;
    int location;
    Backpack Backpack;
    Gear gear;

    int playerHealth;
    int playerMaxHealth;

    int playerDMG;
    int playerDefence;

    int playerGold;
    int playerLevel;
} Player;

extern void displayPlayerStats(Player player);
extern void rest(Player player);
extern void addItemToBag(Item itemToAdd, Backpack *backpack);
extern void showInventory(Player player);

#endif