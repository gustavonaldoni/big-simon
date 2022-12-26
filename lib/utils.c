#include "raylib.h"
#include "utils.h"

void DrawCenteredText(const char *text, int y, float fontSize, Color color)
{
    int xText, yText;
    int textWidth;

    textWidth = MeasureTextEx(GetFontDefault(), text, fontSize, DEFAULT_FONT_SPACING).x;

    xText = (GetScreenWidth() - textWidth) / 2;
    yText = y;

    DrawTextEx(GetFontDefault(), text, (Vector2){xText, yText}, fontSize, DEFAULT_FONT_SPACING, color);
}