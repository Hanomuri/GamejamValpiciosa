#include "raylib.h"

class MainMenu {
private:
    int point;
    int intConfirm = 10;
    bool exitFlag;
    Texture2D mainMenuBackground = LoadTextureFromImage(LoadImage("/resources/images/UI/LogoConOuroboros.png"));
public:
    MainMenu();
    ~MainMenu();
    void MenuMovement();
    void UiEffect(Vector2& top, Vector2& down, Vector2& right);
    bool MenuMain();
};