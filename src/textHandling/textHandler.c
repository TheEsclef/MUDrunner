#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "textHandler.h"

#define WINDOW_WIDTH 100
#define WINDOW_HEIGHT 40

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
    putchar('+');

    for (int i = 0; i < WINDOW_WIDTH - 2; i++)
    {
        putchar('-');
    }

    printf("+\n");
}

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