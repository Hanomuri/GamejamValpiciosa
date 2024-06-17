#include "mainMenu.h"
#include <iostream>

MainMenu::MainMenu() {
    exitFlag = true;
}

MainMenu::~MainMenu() {}

bool MainMenu::MenuMain(Animation& menuBackIdle) { 
    point = 0;
    while(!WindowShouldClose()) {
        Vector2 top = {(750),(800)};
        Vector2 down = {(750),(840)};
        Vector2 right = {(800),(820)};

        BeginDrawing();

        menuBackIdle.Draw({0,0}, 8.45);
        MenuMovement();
        UiEffect(top, down, right);
        DrawTriangle(top, down, right, (Color){ 171, 222, 73, 255 });

        EndDrawing();

        if(IsKeyPressed(KEY_ENTER) && point == 0) {exitFlag = false; return true;} //continue
        if(IsKeyPressed(KEY_ENTER) && point == 1) {return false;} 
    }
}

void MainMenu::MenuMovement() {
    if(IsKeyPressed(KEY_S) && point < 1) {point++;} // Agregar Efecto UI
    if(IsKeyPressed(KEY_W) && point > 0) {point--;} // Agregar Efecto UI
}

void MainMenu::UiEffect(Vector2& top, Vector2& down, Vector2& right) {
    if(point == 0) {top = {(750),(800)}; down = {(750),(840)}; right = {(800),(820)};}
    if(point == 1) {top = {(780),(940)}; down = {(780),(980)}; right = {(830),(960)};}
}