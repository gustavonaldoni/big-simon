#include "raylib.h"
#include "list.h"
#include "player.h"

void CreatePlayer(Player *player)
{
    List playsList = {0};
    ListCreate(&playsList);

    player->score = 0;
    player->playsList = playsList;
}