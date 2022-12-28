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
           (player->numberOfPlays <= CalculateNumberOfBotPlays(roundNumber));
}

int AddPlayerPlayToList(Player *player, int i, int j, Board *board, int roundNumber)
{
    if (!PlayIsValid(player, i, j, board, roundNumber))
        return 0;

    ListInsertEnd(&(player->playsList), i, j);
    player->numberOfPlays += 1;
    return 1;
}