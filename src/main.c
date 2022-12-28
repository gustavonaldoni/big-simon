#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "stopwatch.h"
#include "utils.h"
#include "board.h"
#include "piece.h"
#include "list.h"
#include "bot.h"
#include "player.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define MAX_FPS 60

int iClicked = 0, jClicked = 0;
int turn = 0;
int roundNumber = 1;
int position = 0;

int main(void)
{
    srand(time(NULL));
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Big Simon");

    Board board = {0};
    Piece *piecesArray = NULL;

    CreateBoard(&board, 2, 500);
    piecesArray = CreatePiecesArray(board);

    Bot bot;
    CreateBot(&bot);

    Stopwatch initialBotPlayCooldown = StopwatchCreate(3.0f);

    SetTargetFPS(MAX_FPS);
    while (!WindowShouldClose())
    {
        StopwatchUpdate(&initialBotPlayCooldown);

        if (IsBotTurn(turn) && StopwatchIsDone(initialBotPlayCooldown))
        {
            if (ListIsEmpty(bot.playsList))
                GenerateRandomBotPlays(&bot, roundNumber, &board);

            ListShow(bot.playsList);

            if (position < ListCountElements(bot.playsList))
                DrawBotPlaysList(&bot, &turn, &position, &board);
        }

        else if (!IsBotTurn(turn) && StopwatchIsDone(initialBotPlayCooldown))
        {
            if (UserClickedInsideBoard(&board))
            {
                GetClickedMatrixCoordinates(&board, &iClicked, &jClicked);
                printf("iClicked = %d, jClicked = %d\n", iClicked, jClicked);
                SetValueOnIntegerMatrix(&(board.matrix), jClicked, iClicked, !(*GetValueFromIntegerMatrix(&(board.matrix), jClicked, iClicked)));
            }
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