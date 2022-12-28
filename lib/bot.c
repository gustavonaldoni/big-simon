#include <stdlib.h>
#include "raylib.h"
#include "random.h"
#include "stopwatch.h"
#include "list.h"
#include "board.h"
#include "bot.h"

void CreateBot(Bot *bot)
{
    List playsList = {0};
    ListCreate(&playsList);

    bot->playsList = playsList;
    bot->cooldownStopwatch = StopwatchCreate(COOLDOWN);
    bot->score = 0;
}

int CalculateNumberOfBotPlays(int round)
{
    return round + 10;
}

void GenerateRandomBotPlays(Bot *bot, int round, Board *board)
{
    int i, numberOfPlays;
    int iRandom, jRandom;

    numberOfPlays = CalculateNumberOfBotPlays(round);

    for (i = 0; i < numberOfPlays; i++)
    {
        iRandom = GenerateRandomInt(0, board->matrixOrder - 1);
        jRandom = GenerateRandomInt(0, board->matrixOrder - 1);

        ListInsertEnd(&(bot->playsList), iRandom, jRandom);
    }
}

void ResetBotPlaysList(Bot *bot)
{
    ListRemoveAll(&(bot->playsList));
}

void DrawBotPlaysList(Bot *bot, int *turn, int *position, Board *board)
{
    int iCurrent = 0, jCurrent = 0;

    StopwatchUpdate(&(bot->cooldownStopwatch));
    ListGetElement(bot->playsList, *position, &iCurrent, &jCurrent);

    if (bot->cooldownStopwatch.currentSeconds <= bot->cooldownStopwatch.endSeconds / 2.0f)
        SetValueOnIntegerMatrix(&(board->matrix), jCurrent, iCurrent, 1);
    else
        SetValueOnIntegerMatrix(&(board->matrix), jCurrent, iCurrent, 0);

    if (StopwatchIsDone(bot->cooldownStopwatch))
    {
        *position += 1;
        StopwatchReset(&(bot->cooldownStopwatch));
    }
}

int IsBotTurn(int turn)
{
    return turn == 0;
}