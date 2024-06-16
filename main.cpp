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
  
  DialogueManager dg("textochalla.data");

  Player player = {};
  int previousDangeLevel = player.dangerLevel;

  Font font = LoadFontEx("resources/fonts/IllusionBook-Regular.ttf", 100, NULL, 0);

  Menu menu = Menu();

    //MUSIC
  InitAudioDevice();              // Initialize audio device
  Music music = LoadMusicStream("resources/music/ZeroDanger.wav");
  PlayMusicStream(music);
  float timePlayed = 0.0f;        // Time played normalized [0.0f..1.0f]

  while (!WindowShouldClose())
  {
    if(IsKeyPressed(KEY_P)) {if(!menu.MenuMain()) {return 0;}}
    float scale = MIN((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
    BeginTextureMode(target);

    // Update
    //----------------------------------------------------------------------------------
    std::cout << "danger level: " << player.dangerLevel << std::endl;
    if(player.dangerLevel != previousDangeLevel)
    {
        if(player.dangerLevel == 0)
        {
            UnloadMusicStream(music);   // Unload music stream buffers from RAM
            music = LoadMusicStream("resources/music/ZeroDanger.wav");
            PlayMusicStream(music);
        }
        else if(player.dangerLevel == 1)
        {
            UnloadMusicStream(music);   // Unload music stream buffers from RAM
            music = LoadMusicStream("resources/music/OneDanger.wav");
            PlayMusicStream(music);
        }
        else if(player.dangerLevel == 2)
        {
            UnloadMusicStream(music);   // Unload music stream buffers from RAM
            music = LoadMusicStream("resources/music/TwoDanger.wav");
            PlayMusicStream(music);
        }
        else if(player.dangerLevel == 3)
        {
            UnloadMusicStream(music);   // Unload music stream buffers from RAM
            music = LoadMusicStream("resources/music/ThreeDanger.wav");
            PlayMusicStream(music);
        }
    }
    previousDangeLevel = player.dangerLevel;
    UpdateMusicStream(music);   // Update music buffer with new stream data

    // Get normalized time played for current music stream
    timePlayed = GetMusicTimePlayed(music)/GetMusicTimeLength(music);

    if (timePlayed > 1.0f) timePlayed = 1.0f;   // Make sure time played is no longer than music


    BeginMode2D(player.m_camera);
    ClearBackground(RAYWHITE);
    GM.Update();
    //mapIdle.Draw({0, 0}, 8);
    macetaIdle.Draw({0, 0}, 8);
    floor.Draw(8);
    meatFloor.Draw(8);
    muralla.Draw(8);
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
  UnloadMusicStream(music);   // Unload music stream buffers from RAM
  CloseAudioDevice();         // Close audio device (music streaming is automatically stopped)
  CloseWindow();
}