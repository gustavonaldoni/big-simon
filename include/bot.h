#define COOLDOWN 2.0f

typedef struct
{
    List playsList;
    Stopwatch cooldownStopwatch;
} Bot;

void CreateBot(Bot *);
int CalculateNumberOfBotPlays(int);
void GenerateRandomBotPlays(Bot *, int, Board *);
void ResetBotPlaysList(Bot *);
void DrawBotPlaysList(Bot *, int *, int *, Board *);
int IsBotTurn(int);
void SetTurnToBots(int *);
void ResetBotStopwatch(Bot *);
