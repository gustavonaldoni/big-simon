#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "utils.h"
#include "board.h"
#include "piece.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

Board board = {0};
Piece *piecesArray = NULL;

int main(void)
{
    CreateBoard(&board, 3, 500);
    CreatePiecesArray(piecesArray, board);

    srand(time(NULL));

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Big Simon");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCenteredText("Big Simon", GetScreenHeight() / 13, 60.0f, DARKGRAY);

        EndDrawing();
    }

    DestroyBoard(&board);
    DestroyPiecesArray(piecesArray);

    CloseWindow();

    return 0;
}