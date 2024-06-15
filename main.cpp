#include <iostream>
#include <string.h>
#include "core.h"
#include "raylib.h"
#include "todo.h"

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

std::pair<unsigned int, unsigned int> ScreenResolutions[] = {{720, 405}, {1280, 720}, {1366, 768}, {1920, 1080}};

int main(void)
{
    GameManager GM(ScreenResolutions, 3, 0, "Valpo jam");
    int gameScreenWidth = 1920; int gameScreenHeight = 1080;

    RenderTexture2D target = LoadRenderTexture(1920, 1080);
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);
    
    SpriteSheet map = {"resources/images/placeholderMap.png", 1, 1};
    Animation mapIdle = {"mapIdle", map, 0, 0, 0};

    SpriteSheet maceta = {"resources/images/macetaV1.png", 1, 1};
    Animation macetaIdle = {"macetaIdle", maceta, 0, 0, 0};

    SpriteSheet muralla = {"resources/images/murallaSpriteSheetV1.png", 5, 1};
    Animation murallaIdle = {"idle", muralla, 0, 0, 0};
    
    Todo todo = {};
    Font font = LoadFontEx("resources/fonts/IllusionBook-Regular.ttf", 100, NULL, 0);

    while (!WindowShouldClose())
    {
        float scale = MIN((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
        if(IsKeyPressed(KEY_TAB)) todo.toogle  = (todo.toogle) ? 0 : 1;
        BeginTextureMode(target);
        
        ClearBackground(RAYWHITE);
        GM.Update();
        mapIdle.Draw({0, 0}, 7.5);
        macetaIdle.Draw({0, 0}, 7.5);
        murallaIdle.Draw({100, 500}, 7.5);
        if(todo.toogle) todo.Draw(font);

        EndTextureMode();

        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },
                           (Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5f, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5f,
                           (float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
    }
    CloseWindow();
}
