#include "raylib.h"
#include "board.h"

void CreateBoard(Board *board, int matrixOrder, int size)
{
    IntegerMatrix boardMatrix = {0};

    board->size = size;
    board->x = (GetScreenWidth() - board->size) / 2;
    board->y = (GetScreenHeight() - board->size) / 2;
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

void ResetBoard(Board *board)
{
    ZeroIntegerMatrix(&(board->matrix));
}