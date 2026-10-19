#ifndef TEXTHANDLER_H
#define TEXTHANDLER_H

typedef enum
{
    Left,
    Centered,
    Right
} TextAlignment;

extern void printWrapped(const char *text, TextAlignment alignment);
extern void printStatsRow(const char *left, const char *right);
extern void printBorder();

#endif