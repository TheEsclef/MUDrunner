#include <windows.h>
#include <stdio.h>
#include "player.h"
#include "locations/locations.h"
#include "textHandling/textHandler.h"
#include "items/items.h"

int action;
char name[20];
int isGameOver = 0;

// Function for initialization
void initialize(Player *player, Backpack backpack)
{
    system("cls");
    printWrapped("-- WELCOME TO MUD RUNNER --", Centered);
    printBorder();
    printWrapped("Please enter your name\n", Centered);
    scanf("%19s", name);
    player->playerName = name;

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
}

// Function for handling the main game loop and logic
void update(Player player)
{
    system("cls");

    switch (player.location)
    {
    case 0:
        campsiteLoop(player);
    }
}

int main()
{    
    // Initialize
    Player player;
    Backpack backpack;

    initialize(&player, backpack);

    addItemToBag(createWeaponItem(woodenSword), &player.Backpack);
    addItemToBag(createShieldItem(goldShield), &player.Backpack);
    addItemToBag(createWeaponItem(steelSword), &player.Backpack);

    while (isGameOver == 0)
    {
        update(player);
    }

    return 0;
}