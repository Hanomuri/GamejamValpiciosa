#include <iostream>
#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "TESTING");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        DrawRectangle(200, 150, 300, 100, RED);
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    CloseWindow();
}
