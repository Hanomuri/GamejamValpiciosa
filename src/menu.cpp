#include "menu.h"
#include <iostream>

Menu::Menu() {
    font = LoadFontEx("resources/fonts/IllusionBook-Regular.ttf", 100, NULL, 0);
    }

Menu::~Menu() {}

void Menu::MenuMain() { 
    point = 0;
    //UiEffect();
    while(!IsKeyReleased(KEY_P)){PollInputEvents();};
    while(!WindowShouldClose()) {
        BeginDrawing();
        if(IsKeyPressed(KEY_P)) {break;}
        MenuMovement();
        DrawTextEx(font, "MENU", {52,52}, 100, 0, GRAY);
        DrawTextEx(font, menuButton[0], {200,240}, 100, 0, GRAY);
        DrawTextEx(font, menuButton[1], {200,300}, 100, 0, GRAY);
        DrawTextEx(font, menuButton[2], {200,360}, 100, 0, GRAY);
        DrawTextEx(font, menuButton[3], {200,420}, 100, 0, GRAY);
        EndDrawing();

        if(IsKeyPressed(KEY_ENTER) && point == 0) {break;} //continue
        if(IsKeyPressed(KEY_ENTER) && point == 1) {MenuNewGame();} //new game
        if(IsKeyPressed(KEY_ENTER) && point == 2) {MenuSettings();} //Settings
        if(IsKeyPressed(KEY_ENTER) && point == 3) {MenuExit();} //exit / ¿You sure?
    }
}

void Menu::MenuMovement() {
    if(IsKeyPressed(KEY_DOWN) && point < 3) {point++;} // Agregar Efecto UI
    if(IsKeyPressed(KEY_UP) && point > 0) {point--;} // Agregar Efecto UI
}

void Menu::MenuNewGame() {}
void Menu::MenuSettings() {}
void Menu::MenuExit() {}
/*
void Menu::MenuNewGame() {}
void Menu::MenuSettings() {}
void Menu::MenuExit() {
    int intConfirm = 0;
    MenuMain();
    while(!WindowShouldClose()) {
        DrawTextEx(font, "ARE YOU SURE YOU WANT TO EXIT?", {960, 540}, 100, 0, GRAY);
        DrawTextEx(font, "YES", {(y+960), 580}, 100, 0, GRAY);
        DrawTextEx(font, "NO", {(j+1000), 580}, 100, 0, GRAY);
    

        if(IsKeyPressed(KEY_LEFT) && point < 2) {intConfirm++;}
        if(IsKeyPressed(KEY_RIGHT) && point > 0) {intConfirm--;}
        if(IsKeyPressed(KEY_ENTER) && point == 0) {CloseWindow();}
        if(IsKeyPressed(KEY_ENTER) && point == 1) {break;}  
        if(IsKeyPressed(KEY_P)) {break;} 
    }
}

void Menu::UiEffect() {
    BeginDrawing();
    if(point == 0) {
        y = 40;
        j = 0;
        k = 0;
        i = 0;
    }
    else if(point == 1) {
        j = 40;
        y = 0;
        k = 0;
        i = 0;
    }
    else if(point == 2) {
        i = 40;
        y = 0;
        j = 0;
        k = 0;
    }
    else if(point == 3) {
        y = 0;
        j = 0;
        k = 40;
        i = 0;
    }
    EndDrawing();
}
*/