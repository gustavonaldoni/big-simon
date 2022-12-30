#include "matrix.h"

typedef struct
{
    int x, y;
    int size;
    int matrixOrder;
    IntegerMatrix matrix;
} Board;

void CreateBoard(Board *, int, int);
void DestroyBoard(Board *);
int UserClickedInsideBoard(Board *);
void ResetBoard(Board *);
