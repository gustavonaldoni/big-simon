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

int iClicked = 0, jClicked = 0;

int main(void)
{
    srand(time(NULL));
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Big Simon");

    CreateBoard(&board, 3, 500);
    piecesArray = CreatePiecesArray(board);

    while (!WindowShouldClose())
    {
        if (UserClickedInsideBoard(&board))
        {
            iClicked = (GetMouseY() - board.y) / (board.size / board.matrixOrder);
            jClicked = (GetMouseX() - board.x) / (board.size / board.matrixOrder);

            SetValueOnIntegerMatrix(&(board.matrix), jClicked, iClicked, !(*GetValueFromIntegerMatrix(&(board.matrix), jClicked, iClicked)));
        }

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