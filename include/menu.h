#include "raylib.h"
#include "core.h"

class Menu {
private:
    int point, intConfirm;
    float x, y;
    const char* menuButton[4] = {"CONTINUE", "EXIT"};
    Font font;
    bool exitFlag;
    //Animation dotuncheck = {"dot_uncheck", dot, 0, 0, 0};
    //Animation dotcheck = {"dot_check", dot, 1, 1, 0};
public:
    Menu();
    ~Menu();
    void MenuMovement();
    void UiEffect();
    bool MenuMain();
    void MenuNewGame();
    void MenuSettings();
    void MenuExit();
};