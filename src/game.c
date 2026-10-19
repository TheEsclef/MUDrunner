#include <windows.h>
#include <stdio.h>
#include "player.h"
#include "locations/locations.h"
#include "textHandling/textHandler.h"

int action;
char name[20];
int isGameOver = 0;

// Function for initialization
void initialize(Player *player)
{
    system("cls");
    printWrapped("-- WELCOME TO MUD RUNNER --", Centered);
    printBorder();
    printWrapped("Please enter your name\n", Centered);
    scanf("%s", player->playerName);
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
    // Initialize the backpack
    Backpack backpack = {
        28, // maxSlots
        0   // totalValue
    };

    // Initialize the player
    Player player = {
        name,        // Name
        0,         // location - 0 means campsite
        &backpack, // Backpack
        10,        // Health
        10,        // maxHealth
        1,         // playerDMG
        1,         // playerDefence
        0,         // playerGold
        1          // playerLevel
    };

    initialize(&player);

    while (isGameOver == 0)
    {
        update(player);
    }

    return 0;
}