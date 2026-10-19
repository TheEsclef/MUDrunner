#ifndef PLAYER_H
#define PLAYER_H

typedef struct Backpack{
    int maxSlots;
    int totalValue;
} Backpack;

typedef struct Player{
    char *playerName;
    int location;
    Backpack *Backpack;
    
    int playerHealth;
    int playerMaxHealth;

    int playerDMG;
    int playerDefence;

    int playerGold;
    int playerLevel;
} Player;

extern void displayPlayerStats(Player player);
extern void rest(Player player);

#endif