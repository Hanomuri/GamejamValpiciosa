#pragma once
#include "core.h"

class MainMenu {
private:
    int point;
    int intConfirm = 10;
    
public:
    MainMenu();
    ~MainMenu();
    void MenuMovement();
    void UiEffect(Vector2& top, Vector2& down, Vector2& right);
    bool MenuMain(Animation& menuBackIdle);
    bool exitFlag;
};