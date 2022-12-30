typedef struct
{
    int score;
    int numberOfPlays;
    List playsList;
} Player;

void CreatePlayer(Player *);
int PlayIsValid(Player *, int, int, Board *, int);
int AddPlayerPlayToList(Player *, int, int, Board *, int);
int GetClickedMatrixCoordinates(Board *, int *, int *);
void ResetPlayerScore(Player *);
void ResetPlayerNumberOfPlays(Player *);
void ResetPlayerPlaysList(Player *);
int PlayerWonRound(Player *, Bot *);
int IsPlayerTurn(int);
void SetTurnToPlayers(int *);
void UpdatePlayerScore(Player *, int);