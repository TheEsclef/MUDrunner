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
    printWrapped(left, Left);
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

// Function for equipping new gear
void equipGear(Player *player, Item *item)
{
    switch (item->type)
    {
    case ITEM_WEAPON:
        player->gear.weapon = item->data.weapon;
        player->playerDMG += item->data.weapon.weaponDamage;
        printf("Equipped");
        break;
    case ITEM_SHIELD:
        player->gear.shield = item->data.shield;
        player->playerDefence += item->data.shield.shieldDefence;
        printf("Equipped");
        break;
    case ITEM_HELMET:
        player->gear.helmet = item->data.helmet;
        player->playerDefence += item->data.helmet.defenseValue;
        printf("Equipped");
        break;
    case ITEM_CHESTPLATE:
        player->gear.chestplate = item->data.chestplate;
        player->playerDefence += item->data.chestplate.defenseValue;
        printf("Equipped");
        break;
    case ITEM_LEGGINGS:
        player->gear.leggings = item->data.leggings;
        player->playerDefence += item->data.leggings.defenseValue;
        printf("Equipped");
        break;
    }
}

// Function for adding items into player's bag
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

// Function for displaying player's gear
// Creates a new page
void showGear(Player *player)
{
    char buffer[100];
    int gearShouldClose = 0;
    int x;

    while (gearShouldClose == 0)
    {
        system("cls");

        printBorder();
        // Print out the name of the player
        snprintf(buffer, sizeof(buffer), "%s's Gear", player->playerName);
        printWrapped(buffer, Centered);

        // Print out the total damage and defence of the player
        snprintf(buffer, sizeof(buffer),
                 "Total Damage: %d | Total Defence: %d",
                 player->playerDMG,
                 player->playerDefence);
        printWrapped(buffer, Centered);
        printBorder();

        // Create a line of text for displaying equipped weapon stats
        snprintf(buffer, sizeof(buffer),
                 "1. Weapon: %-20s | Damage: %-10d | Defence: %-10d | Value: %-10d",
                 player->gear.weapon.weaponName ? player->gear.weapon.weaponName : "Nothing",
                 player->gear.weapon.weaponDamage,
                 0,
                 player->gear.weapon.value);
        printWrapped(buffer, Left);

        // Create a line of text for displaying equipped shield stats
        snprintf(buffer, sizeof(buffer),
                 "2. Shield: %-20s | Damage: %-10d | Defence: %-10d | Value: %-10d",
                 player->gear.shield.shieldName ? player->gear.shield.shieldName : "Nothing",
                 0,
                 player->gear.shield.shieldDefence,
                 player->gear.shield.value);
        printWrapped(buffer, Left);

        // Create a line of text for displaying equipped helmet stats
        snprintf(buffer, sizeof(buffer),
                 "3. Helmet: %-20s | Damage: %-10d | Defence: %-10d | Value: %-10d",
                 player->gear.helmet.itemName ? player->gear.helmet.itemName : "Nothing",
                 0,
                 player->gear.helmet.defenseValue,
                 player->gear.helmet.value);
        printWrapped(buffer, Left);

        // Create a line of text for displaying equipped chestplate stats
        snprintf(buffer, sizeof(buffer),
                 "4. Chestplate: %-16s | Damage: %-10d | Defence: %-10d | Value: %-10d",
                 player->gear.chestplate.itemName ? player->gear.chestplate.itemName : "Nothing",
                 0,
                 player->gear.chestplate.defenseValue,
                 player->gear.chestplate.value);
        printWrapped(buffer, Left);

        // Create a line of text for displaying equipped leggings stats
        snprintf(buffer, sizeof(buffer),
                 "5. Leggings: %-18s | Damage: %-10d | Defence: %-10d | Value: %-10d",
                 player->gear.leggings.itemName ? player->gear.leggings.itemName : "Nothing",
                 0,
                 player->gear.leggings.defenseValue,
                 player->gear.leggings.value);
        printWrapped(buffer, Left);
        printBorder();

        // Ask the user for the next prompt
        printWrapped("1 - Unequip an Item | 2 - Exit gear page", Centered);
        scanf("%d", &x);

        switch (x)
        {
        case 1: // User picked unequip item
            printf("unequipping");
            break;
        case 2: // User picked exit gear page
            gearShouldClose = 1;
            break;
        }
    }
}

// Function to display the player's inventory
void showInventory(Player *player)
{
    char buffer[200];             // Initialize a buffer for text
    int inventoryShouldClose = 0; // Create boolean to check whether or not inventory should close
    int x;                        // empty int to handle user input

    // While inventory should stay open
    while (inventoryShouldClose == 0)
    {
        system("cls");

        printBorder();
        printWrapped("PLAYER INVENTORY", Centered);
        printBorder();

        // Print out every item, its name, description and value
        for (int i = 0; i < player->Backpack.slotsUsed; i++)
        {
            Item item = player->Backpack.items[i];

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

        switch (x)
        {
        case 0: // User picked return
            inventoryShouldClose = 1;
            break;
        case 1: // User picked Equip
            printWrapped("Choose an item by it's Slot to equip:", Centered);
            scanf("%d", &x);
            equipGear(player, &player->Backpack.items[x - 1]);
            printWrapped("Equipped Item!", Centered);
            Sleep(1000);
            break;
        case 2: // User picked remove
            printf("removing item...");
            break;
        }
    }
}