#include <iostream>
#include <string.h>
#include "core.h"
#include "dialogue.h"
#include "raylib.h"
#include "player.h"
#include "todo.h"
#include "menu.h"

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

std::pair<unsigned int, unsigned int> ScreenResolutions[] = {{720, 405}, {1280, 720}, {1366, 768}, {1920, 1080}};

int main(void)
{
  GameManager GM(ScreenResolutions, 3, 0, "Valpo jam");
  int gameScreenWidth = 1920; int gameScreenHeight = 1080;

  RenderTexture2D target = LoadRenderTexture(1920, 1080);
  SetTextureFilter(target.texture, TEXTURE_FILTER_TRILINEAR);

  SetWindowIcon(LoadImage("resources/images/UI/icono.png"));
  SetWindowTitle("Pico pal que lee :p");

  SpriteSheet maceta = {"resources/images/macetaV1.png", 1, 1};
  Animation macetaIdle = {"macetaIdle", maceta, 0};

  TileMap floor = {"resources/images/floorTilesOffice.png", 13, 1};
  floor.Load("resources/data/floor.data");

  TileMap meatFloor = {"resources/images/meatFloorV2.png", 10, 1};
  meatFloor.Load("resources/data/meatFloor.data");

  TileMap muralla = {"resources/images/murallaSpriteSheetV2.png", 7, 2};
  muralla.Load("resources/data/map.data");

  Player player = {};

  DialogueManager dg("textochalla.data", &player.m_camera);

  Font font = LoadFontEx("resources/fonts/IllusionBook-Regular.ttf", 100, NULL, 0);

  Menu menu = Menu();

  
  while (!WindowShouldClose())
  {
    if(IsKeyPressed(KEY_P)) {if(!menu.MenuMain()) {return 0;}}
    float scale = MIN((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
    BeginTextureMode(target);
    
    BeginMode2D(player.m_camera);
    ClearBackground(RAYWHITE);
    GM.Update();
    //mapIdle.Draw({0, 0}, 8);
    macetaIdle.Draw({0, 0}, 8);
    floor.Draw(8);
    meatFloor.Draw(8);
    muralla.Draw(8);
    dg.Render("jefe", 0);
    player.Update();
    EndMode2D();

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
