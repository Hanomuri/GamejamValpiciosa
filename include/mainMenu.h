#include "raylib.h"
#include "core.h"

class MainMenu {
private:
    int point;
    int intConfirm = 10;
    bool exitFlag;
    SpriteSheet mainMenuBackground = {"/resources/images/UI/LogoConOuroboros.png", 1 ,1};
    Animation mainMenuBackgroundIdle = {"mainMenuBackgroundIdle", mainMenuBackground, 0};
public:
    MainMenu();
    ~MainMenu();
    void MenuMovement();
    void UiEffect(Vector2& top, Vector2& down, Vector2& right);
    bool MenuMain();
};