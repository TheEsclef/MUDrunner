#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "../player.h"
#include "../locations/locations.h"
#include "../textHandling/textHandler.h"

void goToTown(Player *player)
{
    int move;
    system("cls");

    printBorder();
    printWrapped("You follow a nice and clean dirt road towards a city on the horizon...", Centered);
    Sleep(1000);
    printWrapped("On your way there you spot a lake to your left.... would you like to investigate?", Centered);
    Sleep(1000);
    printWrapped("Your options are: 1 - Yes | 2 - No", Centered);
    printBorder();

    scanf("%d", &move);
    switch (move)
    {
    case 1:
        system("cls");
        printBorder();
        printWrapped("You arrive on the edge of the lake, what would you like to do?", Centered);
        Sleep(1000);
        printWrapped("1 - Return to the road | 2 - Go Fishing | 3 - Look for treasure", Centered);
        printBorder();
        scanf("%d", &move);
        
        switch(move){
            case 1:
                break;
            case 2:
                system("cls");
                printBorder();
                printWrapped("You cast your rod in the water....", Centered);
                Sleep(2000);
                printWrapped("You sit there....", Centered);
                Sleep(2000);
                printWrapped("The sound of morning dew hitting the water make you want to pee", Centered);
                Sleep(2000);
                printWrapped("FINALLY! You caught a fish", Centered);
                break;
            case 3:
                system("cls");
                printBorder();
                printWrapped("You decide to look around for valuable items...", Centered);
                Sleep(3000);
                printWrapped("All you find is some dogshit", Centered);
                Sleep(2000);
                break;
        }
    case 2:
        system("cls");
        printBorder();
        printWrapped("You continue towards the city....", Centered);
        Sleep(2000);
        printWrapped("In the distance you see cows munching hay...... you also hear sheep", Centered);
        Sleep(1000);
        printWrapped("Would you like to go take a look at the sheep", Centered);
        printWrapped("1 - Yes | 2 - No", Centered);
        scanf("%d", &move);
        switch (move)
        {
        case 1:
            system("cls");
            printBorder();
            printWrapped("You walk over to the sheep pen....", Centered);
            Sleep(2000);
            printWrapped("You arrive at the sheep pen, those are indeed some beautiful sheep", Centered);
            Sleep(1000);
            printWrapped("It's best if I leave the be.... for now", Centered);
            Sleep(2000);
        case 2:
            system("cls");
            printBorder();
            printWrapped("Ahh... who gives a fuck about sheep anyway", Centered);
            Sleep(2000);
        }

        printBorder();
        printWrapped("You continue your journey, with a mild pace....", Centered);
        Sleep(1000);
        printWrapped("You arrive at the city", Centered);
        printBorder();
        Sleep(2000);
    }
}

void explore(Player *player)
{
    int isExploring = 1;
    char action[30];
    int move;

    while (isExploring == 1)
    {
        system("cls");

        printBorder();
        printWrapped("YOU ARE EXPLORING", Centered);
        printBorder();

        printWrapped("You come across a signpost, which helps you navigate", Centered);
        printWrapped("North - Campsite | South - Town | East - Coal Mines | West - Thick forest", Centered);
        printBorder();

        printWrapped("Choose your next step... But tread carefully", Centered);
        scanf("%s", action);

        if (strcmp(action, "North") == 0)
        {
            campsiteLoop(player);
            isExploring = 0;
        }
        else if (strcmp(action, "South") == 0)
        {
            goToTown(player);
        }
        else
        {
            printBorder();
            printWrapped("INVALID OPTIONS", Centered);
        }
    }
}