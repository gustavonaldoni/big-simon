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
void CreatePiecesArray(Piece *, Board);
void DestroyPiecesArray(Piece *);
