#include <stdio.h>
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

int i, j;

int main(void)
{
    srand(time(NULL));
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Big Simon");

    CreateBoard(&board, 3, 500);
    piecesArray = CreatePiecesArray(board);
    printf("%p ===== ", piecesArray);

    PrintIntegerMatrix(&board.matrix);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCenteredText("Big Simon", GetScreenHeight() / 13, 60.0f, DARKGRAY);

        DrawBoard(&board, piecesArray);

        EndDrawing();
    }

    DestroyBoard(&board);
    DestroyPiecesArray(piecesArray);

    CloseWindow();

    return 0;
}