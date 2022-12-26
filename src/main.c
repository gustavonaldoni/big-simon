#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "utils.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

int main(void)
{

    srand(time(NULL));

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Big Simon");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCenteredText("Big Simon", GetScreenHeight() / 13, 60.0f, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}