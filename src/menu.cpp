#include "menu.h"

Menu::Menu() {
    font = LoadFontEx("resources/fonts/IllusionBook-Regular.ttf", 100, NULL, 0);
    exitFlag = true;
    }

Menu::~Menu() {}

bool Menu::MenuMain() { 
    point = 0; 
    while(!IsKeyReleased(KEY_P)){PollInputEvents();};
    while(!WindowShouldClose()) {
        Vector2 top = {(130),(370)};
        Vector2 down = {(130),(410)};
        Vector2 right = {(180),(390)};
        BeginDrawing();
        ClearBackground((Color){ 4, 14, 42, 255 } );
        if(IsKeyPressed(KEY_P)) {break;}
        MenuMovement();
        UiEffect(top, down, right);
        DrawTextEx(font, "MENU", {100,100}, 120, 0, (Color){ 171, 222, 73, 255 });
        DrawTextEx(font, menuButton[0], {200,340}, 100, 0, (Color){ 171, 222, 73, 255 });
        DrawTextEx(font, menuButton[1], {200,460}, 100, 0, (Color){ 171, 222, 73, 255 });
        DrawTriangle(top, down, right, (Color){ 171, 222, 73, 255 });
        EndDrawing();
        if(IsKeyPressed(KEY_ENTER) && point == 0) {break;} //continue
        if(IsKeyPressed(KEY_ENTER) && point == 1) {
            MenuExit();
            if(!exitFlag) {return false;}
            point = 1;
        } //exit / ¿You sure?
    }
}

void Menu::MenuMovement() {
    if(IsKeyPressed(KEY_S) && point < 1) {point++;} // Agregar Efecto UI
    if(IsKeyPressed(KEY_W) && point > 0) {point--;} // Agregar Efecto UI
}

void Menu::MenuExit() {
    Vector2 top = {(360),(530)};
    Vector2 down = {(360),(570)};
    Vector2 right = {(410),(550)};
    intConfirm = 0;
    while(!WindowShouldClose()) {
        point = 10;
        BeginDrawing();
        ClearBackground((Color){ 4, 14, 42, 255 } );
        UiEffect(top, down, right);
        DrawTextEx(font, "ARE YOU SURE YOU WANT TO EXIT?", {320, 400}, 100, 0, (Color){ 171, 222, 73, 255 });
        DrawTextEx(font, " YES                                       NO", {(430), 500}, 100, 0, (Color){ 171, 222, 73, 255 });
        DrawTriangle(top, down, right, (Color){ 171, 222, 73, 255 });
        EndDrawing();
        if(IsKeyPressed(KEY_D) && intConfirm < 1) {intConfirm++;}
        if(IsKeyPressed(KEY_A) && intConfirm > 0) {intConfirm--;}
        if(IsKeyPressed(KEY_ENTER) && intConfirm == 0) {
            exitFlag = false;
            intConfirm = 10;
            break;
        }
        if(IsKeyPressed(KEY_ENTER) && intConfirm == 1) {intConfirm = 10; break;}  
        if(IsKeyPressed(KEY_P)) {intConfirm = 10; break;} 
    }
}

void Menu::UiEffect(Vector2& top, Vector2& down, Vector2& right) {
    if(point == 0) {top = {(130),(370)}; down = {(130),(410)}; right = {(180),(390)};}
    if(point == 1) {top = {(130),(490)}; down = {(130),(530)}; right = {(180),(510)};}
    if(intConfirm == 0) {top = {(360),(530)}; down = {(360),(570)}; right = {(410),(550)};}
    if(intConfirm == 1) {top = {(1100),(530)}; down = {(1100),(570)}; right = {(1170),(550)};}
}