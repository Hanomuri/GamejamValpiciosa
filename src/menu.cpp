#include "menu.h"
#include <iostream>

Menu::Menu() {
    font = LoadFontEx("resources/fonts/IllusionBook-Regular.ttf", 100, NULL, 0);
    exitFlag = true;
    x = y = 0;
    }

Menu::~Menu() {}

bool Menu::MenuMain() { 
    point = 0;
    //UiEffect();
    while(!IsKeyReleased(KEY_P)){PollInputEvents();};
    while(!WindowShouldClose()) {
        BeginDrawing();
        if(IsKeyPressed(KEY_P)) {break;}
        MenuMovement();
        DrawTextEx(font, "MENU", {100,100}, 120, 0, GRAY);
        DrawTextEx(font, menuButton[0], {200,340}, 100, 0, GRAY);
        DrawTextEx(font, menuButton[1], {200,460}, 100, 0, GRAY);
        DrawTriangle({(x+130),(y+370)}, {(x+130),(y+410)}, {(x+180),(y+390)}, GRAY);
        EndDrawing();
        std::cout << point << '\n';
        if(IsKeyPressed(KEY_ENTER) && point == 0) {break;} //continue
        if(IsKeyPressed(KEY_ENTER) && point == 1) {
            MenuExit();
            if(!exitFlag) {return false;}
            else return true;
        } //exit / ¿You sure?
    }
}

void Menu::MenuMovement() {
    if(IsKeyPressed(KEY_S) && point < 1) {point++;} // Agregar Efecto UI
    if(IsKeyPressed(KEY_W) && point > 0) {point--;} // Agregar Efecto UI
    UiEffect();
}

void Menu::MenuNewGame() {}
void Menu::MenuSettings() {}
void Menu::MenuExit() {
    intConfirm = 0;
    while(!WindowShouldClose()) {
        BeginDrawing();
        DrawTextEx(font, "ARE YOU SURE YOU WANT TO EXIT?", {540, 430}, 100, 0, GRAY);
        DrawTextEx(font, " YES                                       NO", {(650), 530}, 100, 0, GRAY);
        EndDrawing();
    std::cout<<intConfirm<< '\n';
        if(IsKeyPressed(KEY_D) && intConfirm < 1) {intConfirm++;}
        if(IsKeyPressed(KEY_A) && intConfirm > 0) {intConfirm--;}
        if(IsKeyPressed(KEY_ENTER) && intConfirm == 0) {
            exitFlag = false;
            break;
        }
        if(IsKeyPressed(KEY_ENTER) && intConfirm == 1) {break;}  
        if(IsKeyPressed(KEY_P)) {break;} 
    }
}

void Menu::UiEffect() {
    if(point == 0) {x = y = 0;}
    if(point == 1) {x = 0; y = 120;}
    if(intConfirm == 0) {}
}
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

*/