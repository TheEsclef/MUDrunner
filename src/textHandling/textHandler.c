#include <stdio.h>
#include <string.h>
#include "textHandler.h"

#define WINDOW_WIDTH 100

void printWrapped(const char *text, TextAlignment alignment)
{
    int len = strlen(text);

    switch (alignment)
    {
        case Centered:
        {
            int padding = (WINDOW_WIDTH - len) / 2;

            if (padding < 0)
                padding = 0;

            for (int i = 0; i < padding; i++)
                putchar(' ');

            printf("%s\n", text);
            break;
        }

        case Right:
        {
            int padding = WINDOW_WIDTH - len;

            if (padding < 0)
                padding = 0;

            for (int i = 0; i < padding; i++)
                putchar(' ');

            printf("%s\n", text);
            break;
        }

        case Left:
        default:
        {
            int width = 0;

            while (*text)
            {
                putchar(*text);

                if (*text == '\n')
                {
                    width = 0;
                }
                else
                {
                    width++;
                }

                if (width >= WINDOW_WIDTH && *text == ' ')
                {
                    putchar('\n');
                    width = 0;
                }

                text++;
            }

            putchar('\n');
            break;
        }
    }
}

void printStatsRow(const char *left, const char *right)
{
    int contentWidth = WINDOW_WIDTH;

    /* Divide available space between both columns */
    int leftWidth = contentWidth / 2;
    int rightWidth = contentWidth - leftWidth;

    printf("%-*s%-*s\n",
           leftWidth,
           left,
           rightWidth,
           right);
}

void printBorder(void)
{
    printf("+");
    for (int i = 0; i < WINDOW_WIDTH-2; i++){
        printf("-");
    }
    printf("+\n");
}