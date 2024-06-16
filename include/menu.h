#include "raylib.h"
#include "core.h"

class Menu {
private:
    int point;
    float y, j, k ,i;
    const char* menuButton[4] = {"CONTINUE", "NEW GAME", "SETTINGS", "EXIT"};
    Font font;
    //Animation dotuncheck = {"dot_uncheck", dot, 0, 0, 0};
    //Animation dotcheck = {"dot_check", dot, 1, 1, 0};
public:
    Menu();
    ~Menu();
    void MenuMovement();
    void UiEffect();
    void MenuMain();
    void MenuNewGame();
    void MenuSettings();
    void MenuExit();
};