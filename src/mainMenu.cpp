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
        //ClearBackground((Color){ 4, 14, 42, 255 } );
        mainMenuBackgroundIdle.Draw({0, 0}, 8);
        MenuMovement();
        UiEffect(top, down, right);
        DrawTriangle(top, down, right, (Color){ 171, 222, 73, 255 });
        if(IsKeyPressed(KEY_ENTER) && point == 0) {break;} //continue
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
    if(intConfirm == 0) {top = {(360),(530)}; down = {(360),(570)}; right = {(410),(550)};}
    if(intConfirm == 1) {top = {(1100),(530)}; down = {(1100),(570)}; right = {(1170),(550)};}
}