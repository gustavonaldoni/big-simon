#define COOLDOWN 1.0f

typedef struct
{
    List playsList;
    Stopwatch cooldownStopwatch;
    int score;
} Bot;

void CreateBot(Bot *);
int CalculateNumberOfBotPlays(int);
void GenerateRandomBotPlays(Bot *, int, Board *);
void ResetBotPlaysList(Bot *);
void DrawBotPlaysList(Bot *, int *);
int IsBotTurn(int);
