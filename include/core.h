#pragma once

#include <vector>
#include <utility>
#include <raylib.h>

typedef struct GameManager {
  typedef unsigned int ushort;
    
  std::pair<ushort, ushort>* screenResolutions;
  ushort savedResolution;
  bool isWindowBorderless;

  GameManager(std::pair<ushort, ushort> *GR, ushort SR, bool IWB, const char *title);
  void SetResolution(ushort newResolution);
  bool SetBorderless();
  bool SetUnBorderless();
  void ToggleBorderless();
  void Update();
  void Close();
}GameManager;

typedef struct SpriteSheet {
  typedef unsigned int ushort;
  Texture2D spriteBuffer;
  ushort framesX;
  ushort framesY;
  float frameWidth;
  float frameHeight;

  SpriteSheet(const char* nameFile, ushort fX, ushort fY);
}SpriteSheet;

typedef struct Animation {
  typedef unsigned int ushort;
  char* animationName; 
  SpriteSheet* sprite;
  ushort initialFrame;
  ushort currentFrame;
  ushort animationFrames;
  float timer;
  float frameTime;
  bool triggerCondition = 0;

  Animation(char* name, SpriteSheet& spriteB, int initialF, int animationFs, float frameT);
  Animation(char* name, SpriteSheet& spriteB, int frame);

  void Initialize();
  void Draw(Vector2 Position, float Scale);
  ushort FinishAnimation();
}Animation;

typedef struct TileMap {
  typedef unsigned int ushort;
  ushort tilesX, tilesY;
  SpriteSheet tileSheet;
  std::pair<ushort, ushort> tileDim;
  std::vector<int> tMap;
  std::vector<Animation> tiles;

  TileMap(char* file, ushort fX, ushort fY);
  void Load(char* file);
  void Draw(float scale);
}TileMap;

typedef struct TileCollider {
  typedef unsigned int ushort;
  ushort tilesX, tilesY;
  std::vector<std::vector<bool>> colliderMap;

  TileCollider(char* file);
}TileCollider;

typedef struct Animator {
  typedef unsigned int ushort;
  Animation* animationArray;
  ushort currentNode;
  ushort* neighborsSize;
  ushort** neighbors;

  Animator(Animation* animations, ushort animationsSize);
  void BuildNeighbors(ushort node, ushort size, ushort* neightorhood);
  void ChangeAnimation(ushort toAnimation);
  void UpdateAnimation(Vector2 position, float scale);
}Animator;

typedef struct State {
  char* stateName;
  
  State(char* name);
  template<class T>
  void Initialize(T var);
  virtual void Reset();
  virtual void Update();
  void Exit();
}State;

typedef struct StateMachine{
  State* currentState;
  Animator* m_animator;
  State** m_states;

  StateMachine(Animator* animator, State** states);
  void Update();
  void ChangeState(State* newState);
}StateMachine;

Vector2 FixPosition(Vector2 position);
