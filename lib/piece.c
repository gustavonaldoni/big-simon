#include <stdlib.h>
#include "random.h"
#include "raylib.h"
#include "board.h"
#include "piece.h"

void CalculatePieceSize(Piece *piece, Board board)
{
    piece->size = board.size / board.matrixOrder;
}

void CreatePiece(Piece *piece, int i, int j, Color baseColor, Color clickedColor, Board board)
{
    piece->i = i;
    piece->j = j;
    piece->baseColor = baseColor;
    piece->clickedColor = clickedColor;

    CalculatePieceSize(piece, board);
    piece->x = board.x + i * piece->size;
    piece->y = board.y + j * piece->size;

    piece->hitbox = (Rectangle){piece->x, piece->y, piece->size, piece->size};
}

void UpdatePieceHitbox(Piece *piece)
{
    piece->hitbox.x = piece->x;
    piece->hitbox.y = piece->y;
}

void DrawPiece(Piece piece, int isClicked)
{
    if (isClicked)
        DrawRectangle(piece.x, piece.y, piece.size, piece.size, piece.clickedColor);
    else
        DrawRectangle(piece.x, piece.y, piece.size, piece.size, piece.baseColor);
}

Piece *CreatePiecesArray(Board board)
{
    Piece *piecesArray = NULL;
    int i, j;
    int piecesArrayLength = 0;

    Color randomBaseColor = {0}, randomClickedColor = {0};

    piecesArrayLength = board.matrixOrder * board.matrixOrder;
    piecesArray = (Piece *)malloc(piecesArrayLength * sizeof(Piece));

    if (piecesArray == NULL)
        return NULL;

    for (i = 0; i < board.matrixOrder; i++)
    {
        for (j = 0; j < board.matrixOrder; j++)
        {
            randomBaseColor = (Color){GenerateRandomInt(0, 255),
                                      GenerateRandomInt(0, 255),
                                      GenerateRandomInt(0, 255),
                                      255};

            randomClickedColor = (Color){randomBaseColor.r,
                                         randomBaseColor.g,
                                         randomBaseColor.b,
                                         150};

            CreatePiece(&piecesArray[i * board.matrixOrder + j], i, j, randomBaseColor, randomClickedColor, board);
        }
    }

    return piecesArray;
}

void DestroyPiecesArray(Piece *piecesArray)
{
    free(piecesArray);
    piecesArray = NULL;
}

void DrawBoard(Board *board, Piece *pieceArray)
{
    int i, j;
    int isClicked = 0;

    for (i = 0; i < board->matrixOrder; i++)
    {
        for (j = 0; j < board->matrixOrder; j++)
        {
            isClicked = *GetValueFromIntegerMatrix(&(board->matrix), i, j);
            DrawPiece(pieceArray[i * board->matrixOrder + j], isClicked);
        }
    }
}