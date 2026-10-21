#include <windows.h>
#include <stdio.h>
#include "player.h"
#include "locations/locations.h"
#include "textHandling/textHandler.h"
#include "items/items.h"

int action;         // Empty int to handle user input
char name[20];      // Empty buffer for player's name
int isGameOver = 0; // Boolean to check if game is over

// Function for initialization
// In here we initialize what gear the player has on start
// We create buffers and allocate memory
void initialize(Player *player, Backpack backpack, Gear gear)
{
    system("cls");
    printWrapped("-- WELCOME TO MUD RUNNER --", Centered);
    printBorder();
    printWrapped("Please enter your name\n", Centered);
    scanf("%19s", name);
    player->playerName = name;
    player->gear = gear;

    backpack.maxSlots = 28;
    backpack.slotsUsed = 0;
    backpack.totalValue = 0;
    backpack.items = malloc(backpack.maxSlots * sizeof(Item));

    player->location = 0;
    player->Backpack = backpack;

    player->playerMaxHealth = 10;
    player->playerHealth = 10;
    player->playerDMG = 0;
    player->playerDefence = 0;
    player->playerGold = 0;
    player->playerLevel = 1;

    Item starterSword = createWeaponItem(copperSword);
    equipGear(player, &starterSword);

    Item starterShield = createShieldItem(copperShield);
    equipGear(player, &starterShield);

    Item starterHelmet = createHelmetItem(ironHelmet);
    equipGear(player, &starterHelmet);

    Item starterLeggings = createLeggingsItem(ironLeggings);
    equipGear(player, &starterLeggings);

    Item starterChestplate = createChestplateItem(ironChestplate);
    equipGear(player, &starterChestplate);
}

// Function for handling the main game loop and logic
void update(Player player)
{
    system("cls");

    switch (player.location)
    {
    case 0:                   // If the player is in the campsite
        campsiteLoop(player); // Enters the campsite's loop in campsite.c
    }
}

int main()
{
    // Initialize
    Player player;
    Backpack backpack;
    Gear gear;

    initialize(&player, backpack, gear);

    addItemToBag(createWeaponItem(woodenSword), &player.Backpack);
    addItemToBag(createShieldItem(goldShield), &player.Backpack);
    addItemToBag(createWeaponItem(steelSword), &player.Backpack);

    while (isGameOver == 0)
    {
        update(player);
    }

    return 0;
}