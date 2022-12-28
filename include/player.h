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