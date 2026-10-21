#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "textHandler.h"

#define WINDOW_WIDTH 100
#define WINDOW_HEIGHT 40

/*
    THIS FILE IS PRIMARILY FOR HANDLING HOW TEXT IS DISPLAYED
    THINK OF THIS AS A LIBRARY OF MODULES
    PRIMARY REASON FOR THIS FILE IS TO CREATE A FIXED "WINDOW SIZE" FOR THE GAME INSIDE A TERMINAL
*/

// Function to print out text, also takes in an alignment for text alignment
// example printWrapped("Hello World", Centered);
// This prints out "Hello World" in the middle of the window
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

// This function is primarily used to print out the stats of yourself
// Or to print out the stats of an enemy
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

// This simply prints out a border, used to manage readability ingame
void printBorder(void)
{
    putchar('+');

    for (int i = 0; i < WINDOW_WIDTH - 2; i++)
    {
        putchar('-');
    }

    printf("+\n");
}

// Sets the console's size
void setConsoleSize(void)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set the console buffer size first
    COORD bufferSize = {
        WINDOW_WIDTH,
        WINDOW_HEIGHT
    };

    // Set a temporary window small enough to fit the buffer
    SMALL_RECT tempWindow = {
        0, 0, 79, 24
    };

    SetConsoleWindowInfo(console, TRUE, &tempWindow);
    SetConsoleScreenBufferSize(console, bufferSize);

    // Set the final visible window size
    SMALL_RECT windowSize = {
        0, 0,
        WINDOW_WIDTH - 1,
        WINDOW_HEIGHT - 1
    };

    SetConsoleWindowInfo(console, TRUE, &windowSize);
}