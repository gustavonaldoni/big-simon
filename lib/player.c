#include <stdlib.h>
#include "raylib.h"
#include "list.h"
#include "board.h"
#include "stopwatch.h"
#include "bot.h"
#include "player.h"

void CreatePlayer(Player *player)
{
    List playsList = {0};
    ListCreate(&playsList);

    player->score = 0;
    player->numberOfPlays = 0;
    player->playsList = playsList;
}

int PlayIsValid(Player *player, int i, int j, Board *board, int roundNumber)
{
    return (i >= 0 && i < board->matrixOrder) &&
           (j >= 0 && j < board->matrixOrder) &&
           (player->numberOfPlays < CalculateNumberOfBotPlays(roundNumber));
}

int AddPlayerPlayToList(Player *player, int i, int j, Board *board, int roundNumber)
{
    if (!PlayIsValid(player, i, j, board, roundNumber))
        return 0;

    ListInsertEnd(&(player->playsList), i, j);
    player->numberOfPlays += 1;
    return 1;
}

int GetClickedMatrixCoordinates(Board *board, int *iClicked, int *jClicked)
{
    if (!UserClickedInsideBoard(board))
        return 0;

    *iClicked = (GetMouseY() - board->y) / (board->size / board->matrixOrder);
    *jClicked = (GetMouseX() - board->x) / (board->size / board->matrixOrder);

    if (*iClicked >= board->matrixOrder)
        *iClicked = board->matrixOrder - 1;

    if (*jClicked >= board->matrixOrder)
        *jClicked = board->matrixOrder - 1;

    return 1;
}

void ResetPlayerScore(Player *player)
{
    player->score = 0;
}

void ResetPlayerNumberOfPlays(Player *player)
{
    player->numberOfPlays = 0;
}

void ResetPlayerPlaysList(Player *player)
{
    ListRemoveAll(&(player->playsList));
}

int PlayerWonRound(Player *player, Bot *bot)
{
    struct Node *auxPlayer = NULL, *auxBot = NULL;

    if (player->numberOfPlays != ListCountElements(bot->playsList))
        return 0;

    if (ListIsEmpty(player->playsList) || ListIsEmpty(bot->playsList))
        return 0;

    auxPlayer = player->playsList.init;
    auxBot = bot->playsList.init;

    while (auxPlayer != NULL && auxBot != NULL)
    {
        if (auxPlayer->i != auxBot->i || auxPlayer->j != auxBot->j)
            return 0;

        auxPlayer = auxPlayer->next;
        auxBot = auxBot->next;
    }

    return 1;
}

int IsPlayerTurn(int turn)
{
    return turn == 1;
}

void SetTurnToPlayers(int *turn)
{
    *turn = 1;
}

void UpdatePlayerScore(Player *player, int scoreToAdd)
{
    player->score += scoreToAdd;
}