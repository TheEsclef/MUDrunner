#include <stdio.h>
#include <windows.h>
#include "../player.h"
#include "../textHandling/textHandler.h"
#include "../exploring/exploring.h"

void campsiteLoop(Player *player)
{
    int x;           // Initialize x for user input
    char buffer[50]; // Initialize a buffer for sprintf functions

    // Location 0 is the campsite
    while (player->location == 0)
    {
        system("cls"); // Clear the screen

        printBorder();
        printWrapped("THE CAMPSITE", Centered);
        printBorder();

        printWrapped("You are sitting by a crackling campfire", Centered);
        printWrapped("You hear wolves howling in the distance", Centered);
        printBorder();

        displayPlayerStats(*player);
        printBorder();

        printWrapped("Choose your next move", Centered);
        printWrapped("1 - Rest | 2 - Inventory | 3 - View Gear | 4 - Explore", Centered);
        scanf("%d", &x);
        printBorder();

        switch (x)
        {
        case 1:
            rest(*player);
            break;
        case 2:
            showInventory(player);
            break;
        case 3:
            showGear(player);
            break;
        case 4:
            player->location = 1;
            break;
        }
    }
}