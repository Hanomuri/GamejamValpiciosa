#include <iostream>
#include <string.h>
#include "core.h"
#include "dialogue.h"
#include "raylib.h"
#include "player.h"
#include "todo.h"
#include "menu.h"
#include "mainMenu.h"

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
  SetWindowTitle("Pico pal q lee :p");

  SpriteSheet maceta = {"resources/images/macetaV1.png", 1, 1};
  Animation macetaIdle = {"macetaIdle", maceta, 0};

  TileMap floor0 = {"resources/images/World/floorTilesOffice.png", 13, 1};
  TileMap floor1 = {"resources/images/World/floorTilesOffice.png", 13, 1};
  TileMap floor2 = {"resources/images/World/floorTilesOffice.png", 13, 1};
  TileMap floor3 = {"resources/images/World/floorTilesOffice.png", 13, 1};
  floor0.Load("resources/data/0/floor0.data");
  floor1.Load("resources/data/1/floor1.data");
  floor2.Load("resources/data/2/floor2.data");
  floor3.Load("resources/data/3/floor3.data");

  TileMap meatFloor0 = {"resources/images/World/meatFloorV2.png", 10, 1};
  TileMap meatFloor1 = {"resources/images/World/meatFloorV2.png", 10, 1};
  TileMap meatFloor2 = {"resources/images/World/meatFloorV2.png", 10, 1};
  TileMap meatFloor3 = {"resources/images/World/meatFloorV2.png", 10, 1};
  meatFloor0.Load("resources/data/0/meatFloor0.data");
  meatFloor1.Load("resources/data/1/meatFloor1.data");
  meatFloor2.Load("resources/data/2/meatFloor2.data");
  meatFloor3.Load("resources/data/3/meatFloor3.data");

  TileMap muralla0 = {"resources/images/World/murallaSpriteSheetV2.png", 7, 4};
  TileMap muralla1 = {"resources/images/World/murallaSpriteSheetV2.png", 7, 4};
  TileMap muralla2 = {"resources/images/World/murallaSpriteSheetV2.png", 7, 4};
  TileMap muralla3 = {"resources/images/World/murallaSpriteSheetV2.png", 7, 4};
  muralla0.Load("resources/data/0/map0.data");
  muralla1.Load("resources/data/1/map1.data");
  muralla2.Load("resources/data/2/map2.data");
  muralla3.Load("resources/data/3/map3.data");

  Player player = {};
  int previousDangeLevel = player.dangerLevel;

  DialogueManager dg("textochalla.data", &player.m_camera);

  Font font = LoadFontEx("resources/fonts/IllusionBook-Regular.ttf", 100, NULL, 0);

  SpriteSheet menuBack = {"resources/images/UI/LogoConOuroboros.png", 1, 1};
  Animation menuBackIdle = {"menuBackIdle", menuBack, 0};

  Menu menu = Menu();
  MainMenu mainMenu = MainMenu();

    //MUSIC
  InitAudioDevice();              // Initialize audio device
  Music music = LoadMusicStream("resources/music/ZeroDanger.wav");
  PlayMusicStream(music);
  float timePlayed = 0.0f;        // Time played normalized [0.0f..1.0f]

  while (!WindowShouldClose())
  { 
    if(mainMenu.exitFlag) {
        if(!mainMenu.MenuMain(menuBackIdle)) {return 0;}
    }
    if(IsKeyPressed(KEY_P)) {if(!menu.MenuMain()) {return 0;}}
    float scale = MIN((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
    BeginTextureMode(target);

    BeginMode2D(player.m_camera);
    ClearBackground((Color){ 4, 14, 42, 255});
    GM.Update();
    // Update
    //----------------------------------------------------------------------------------
    std::cout << "danger level: " << player.dangerLevel << std::endl;
    if(player.dangerLevel == 0)
    {
        //Visuals
        floor0.Draw(8);
        meatFloor0.Draw(8);
        muralla0.Draw(8);

        //Sound
        if(player.dangerLevel != previousDangeLevel)
        {
            float moment = GetMusicTimePlayed(music);
            PauseMusicStream(music);
            music = LoadMusicStream("resources/music/ZeroDanger.wav");
            PlayMusicStream(music);
            SeekMusicStream(music, moment);
        //collisions
        //player.collider = {"resources/data/collisionMap0.data"};
        std::cout <<"pichula\n";
        }
    }
    else if(player.dangerLevel == 1)
    {
        //Visuals
        floor1.Draw(8);
        meatFloor1.Draw(8);
        muralla1.Draw(8);

        //Sound
        if(player.dangerLevel != previousDangeLevel)
        {
            float moment = GetMusicTimePlayed(music);
            PauseMusicStream(music);
            music = LoadMusicStream("resources/music/OneDanger.wav");
            PlayMusicStream(music);
            SeekMusicStream(music, moment);
            //collisions
            //player.collider = {"resources/data/collisionMap1.data"};

        }
    }
    else if(player.dangerLevel == 2)
    {
        //Visuals
        floor2.Draw(8);
        meatFloor2.Draw(8);
        muralla2.Draw(8);

        //Sound
        if(player.dangerLevel != previousDangeLevel)
        {
            float moment = GetMusicTimePlayed(music);
            PauseMusicStream(music);
            music = LoadMusicStream("resources/music/TwoDanger.wav");
            PlayMusicStream(music);
            SeekMusicStream(music, moment);
        //collisions
        //player.collider = {"resources/data/collisionMap2.data"};

        }
    }
    else if(player.dangerLevel == 3)
    {
        //Visuals
        floor3.Draw(8);
        meatFloor3.Draw(8);
        muralla3.Draw(8);

        //Sound
        if(player.dangerLevel != previousDangeLevel)
        {
            float moment = GetMusicTimePlayed(music);
            PauseMusicStream(music);
            music = LoadMusicStream("resources/music/TwoDanger.wav");
            PlayMusicStream(music);
            SeekMusicStream(music, moment);
        //collisions
        //player.collider = {"resources/data/collisionMap3.data"};
        }
    }
    previousDangeLevel = player.dangerLevel;
    UpdateMusicStream(music);   // Update music buffer with new stream data
    // Get normalized time played for current music stream
    timePlayed = GetMusicTimePlayed(music)/GetMusicTimeLength(music);
    if (timePlayed > 1.0f) timePlayed = 1.0f;   // Make sure time played is no longer than music


    //mapIdle.Draw({0, 0}, 8);
    //macetaIdle.Draw({0, 0}, 8);
    //dg.Render("jefe", 0);
    
    //ESTO AL FINAL
    DrawRectangle(player.m_camera.offset.x, player.m_camera.offset.y, gameScreenWidth, gameScreenHeight, (Color){ 4, 14, 42, 25*previousDangeLevel});
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