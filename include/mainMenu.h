#include "raylib.h"

class MainMenu {
private:
    int point;
    int intConfirm = 10;
    
public:
    MainMenu();
    ~MainMenu();
    void MenuMovement();
    void UiEffect(Vector2& top, Vector2& down, Vector2& right);
    bool MenuMain(Texture2D backTexture);
    bool exitFlag;
};