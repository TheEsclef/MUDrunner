#include <stdio.h>
#include <windows.h>
#include "player.h"
#include "items/items.h"
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
void rest(Player player)
{
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

void addItemToBag(Item itemToAdd, Backpack *backpack)
{
    if (backpack->slotsUsed >= backpack->maxSlots)
    {
        printWrapped("YOUR BAG IS FULL", Centered);
        Sleep(1000);
        return;
    }

    backpack->items[backpack->slotsUsed] = itemToAdd;
    backpack->slotsUsed++;
    backpack->totalValue += itemToAdd.value;
}

void showInventory(Player player)
{
    char buffer[200];
    int inventoryShouldClose = 0;
    int x;

    while (inventoryShouldClose == 0)
    {
        system("cls");

        printBorder();
        printWrapped("PLAYER INVENTORY", Centered);
        printBorder();

        // Print out every item, its name, description and value
        for (int i = 0; i < player.Backpack.slotsUsed; i++)
        {
            Item item = player.Backpack.items[i];

            // Slot, name and value on one line
            snprintf(buffer, sizeof(buffer),
                     "Slot: %d | %s | %d gold",
                     i + 1, item.itemName, item.value);
            printWrapped(buffer, Left);

            // Description on the next line
            snprintf(buffer, sizeof(buffer),
                     "Description: %s",
                     item.itemDescription);
            printWrapped(buffer, Left);

            printf("\n");
        }
        printBorder();

        printWrapped("Choose your next action", Centered);
        printWrapped("1 - Equip an item | 2 - Remove an Item | 0 - Return", Centered);
        scanf("%d", &x);

        switch(x){
            case 0:
                inventoryShouldClose = 1;
                break;
            case 1:
                printf("equipping item...");
                break;
            case 2:
                printf("removing item...");
                break;
        }
    }
}