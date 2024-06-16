#include "mainMenu.h"
#include <iostream>

MainMenu::MainMenu() {
    exitFlag = true;
}

MainMenu::~MainMenu() {}

bool MainMenu::MenuMain() { 
    point = 0;
    while(!WindowShouldClose()) {
        Vector2 top = {(130),(370)};
        Vector2 down = {(130),(410)};
        Vector2 right = {(180),(390)};

        BeginDrawing();

        //ClearBackground((Color){ 4, 14, 42, 255 } );
        DrawTextureEx(mainMenuBackground, {20,20},0 , 50, WHITE);
        MenuMovement();
        UiEffect(top, down, right);
        DrawTriangle(top, down, right, (Color){ 171, 222, 73, 255 });

        EndDrawing();

        if(IsKeyPressed(KEY_ENTER) && point == 0) {UnloadTexture(mainMenuBackground);return true;} //continue
        if(IsKeyPressed(KEY_ENTER) && point == 1) {return false;} 
    }
}

void MainMenu::MenuMovement() {
    if(IsKeyPressed(KEY_S) && point < 1) {point++;} // Agregar Efecto UI
    if(IsKeyPressed(KEY_W) && point > 0) {point--;} // Agregar Efecto UI
}

void MainMenu::UiEffect(Vector2& top, Vector2& down, Vector2& right) {
    if(point == 0) {top = {(130),(370)}; down = {(130),(410)}; right = {(180),(390)};}
    if(point == 1) {top = {(130),(490)}; down = {(130),(530)}; right = {(180),(510)};}
}