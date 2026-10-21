#ifndef ARMOR_H
#define ARMOR_H

typedef struct Helmet
{
    char *itemName;
    char *itemDescription;
    int defenseValue;
    int value;
} Helmet;

typedef struct Leggings
{
    char *itemName;
    char *itemDescription;
    int defenseValue;
    int value;
} Leggings;

typedef struct Chestplate
{
    char *itemName;
    char *itemDescription;
    int defenseValue;
    int value;
} Chestplate;

extern Helmet noHelmet;
extern Chestplate noChestplate;
extern Leggings noLeggings;


extern Helmet ironHelmet;
extern Chestplate ironChestplate;
extern Leggings ironLeggings;

extern Helmet steelHelmet;
extern Chestplate steelChestplate;
extern Leggings steelLeggings;

extern Helmet goldHelmet;
extern Chestplate goldChestplate;
extern Leggings goldLeggings;

#endif