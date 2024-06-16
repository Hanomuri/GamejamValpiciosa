#include "raylib.h"
#include "core.h"

class Menu {
private:
    int point;
    int intConfirm = 10;
    const char* menuButton[4] = {"CONTINUE", "EXIT"};
    Font font;
    bool exitFlag;
public:
    Menu();
    ~Menu();
    void MenuMovement();
    void UiEffect(Vector2& top, Vector2& down, Vector2& right);
    bool MenuMain();
    void MenuExit();
};