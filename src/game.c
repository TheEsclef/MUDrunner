#include <windows.h>
#include <stdio.h>
#include "player.h"
#include "locations/locations.h"
#include "exploring/exploring.h"
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
    scanf("%[^\n]", name);
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

    Item starterSword = createWeaponItem(noWeapon);
    equipGear(player, &starterSword);

    Item starterShield = createShieldItem(noShield);
    equipGear(player, &starterShield);

    Item starterHelmet = createHelmetItem(noHelmet);
    equipGear(player, &starterHelmet);

    Item starterLeggings = createLeggingsItem(noLeggings);
    equipGear(player, &starterLeggings);

    Item starterChestplate = createChestplateItem(noChestplate);
    equipGear(player, &starterChestplate);
}

// Function for handling the main game loop and logic
void update(Player *player)
{
    system("cls");

    switch (player->location)
    {
    case 0:                   // If the player is in the campsite
        campsiteLoop(player); // Enters the campsite's loop in campsite.c
    case 1:                   // If the player is in exploring mode
        explore(player);      // Enter the explore function
        break;
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
        update(&player);
    }

    return 0;
}