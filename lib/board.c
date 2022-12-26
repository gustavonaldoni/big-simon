#include "raylib.h"
#include "board.h"

void CreateBoard(Board *board, int matrixOrder, int size)
{
    IntegerMatrix boardMatrix = {0};

    board->x = (GetScreenWidth() - size) / 2;
    board->y = (GetScreenHeight() - size) / 2;
    board->size = size;
    board->matrixOrder = matrixOrder;

    CreateIntegerMatrix(&boardMatrix, board->matrixOrder, board->matrixOrder);
    ZeroIntegerMatrix(&boardMatrix);

    board->matrix = boardMatrix;
}

void DestroyBoard(Board *board)
{
    DestroyIntegerMatrix(&(board->matrix));
}

int UserClickedInsideBoard(Board *board)
{
    return IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
           CheckCollisionPointRec(GetMousePosition(), (Rectangle){board->x, board->y, board->size, board->size});
}