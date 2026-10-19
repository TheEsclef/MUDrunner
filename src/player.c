#include <stdio.h>
#include <windows.h>
#include "player.h"
#include "textHandling/textHandler.h"

// Function to display Player's stats
void displayPlayerStats(Player player)
{
    char buffer[50];
    char left[50];
    char right[50];

    sprintf(buffer, "%s's Stats:", player.playerName);
    printWrapped(buffer, Centered);
    printf("\n");

    sprintf(left, "Level: %d", player.playerLevel);
    sprintf(right, "Defence: %d", player.playerDefence);
    printStatsRow(left, right);

    sprintf(left, "Health: %d/%d",
            player.playerHealth,
            player.playerMaxHealth);
    sprintf(right, "Damage: %d", player.playerDMG);
    printStatsRow(left, right);

    sprintf(left, "Gold: %d", player.playerGold);
    sprintf(right, "Location: %d", player.location);
    printStatsRow(left, right);
}

// Function for resting, resetting player's health
void rest(Player player){
    system("cls");
    printBorder();
    printWrapped("You ponder your own existance...", Centered);
    Sleep(2000);
    player.playerHealth = player.playerMaxHealth; // Set the player's health, to it's max health
    printWrapped("You've reached a conclusion there's no reasoning behind it", Centered);
    Sleep(3000);
    printWrapped("You feel well rested, health has been regenerated", Centered);
    Sleep(3000);
}