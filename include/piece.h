typedef struct
{
    int i, j;
    int x, y;
    int size;
    Color baseColor, clickedColor;
    Rectangle hitbox;
} Piece;

void CalculatePieceSize(Piece *, Board);
void CreatePiece(Piece *, int, int, Color, Color, Board);
void UpdatePieceHitbox(Piece *);
void DrawPiece(Piece, int);
Piece *CreatePiecesArray(Board);
void DestroyPiecesArray(Piece *);
void DrawBoard(Board *, Piece *);
