#include <algorithm>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "core.h"

//          --ScreenResolutions SavedResolution isWindowBorderless Title--
GameManager::GameManager(std::pair<ushort, ushort>* GR, ushort SR, bool IWB, const char *TITLE)
{
  screenResolutions = GR;
  savedResolution = SR;
  isWindowBorderless = IWB;
  InitWindow(screenResolutions[savedResolution].first, screenResolutions[savedResolution].second, TITLE);
  SetTargetFPS(60);
  ChangeDirectory(GetApplicationDirectory());
}

void GameManager::SetResolution(ushort newResolution)
{
  savedResolution = newResolution;
  SetBorderless();
}

bool GameManager::SetBorderless()
{
  SetWindowSize(screenResolutions[savedResolution].first, screenResolutions[savedResolution].second);
  return 0;
}

bool GameManager::SetUnBorderless()
{
  int Monitor = GetCurrentMonitor();
  SetWindowSize(GetMonitorWidth(Monitor), GetMonitorHeight(Monitor));
  return 1;
}

void GameManager::ToggleBorderless()
{
  isWindowBorderless = (isWindowBorderless) ? SetBorderless() : SetUnBorderless();
}

void GameManager::Update()
{
  if((GetWindowPosition().x != 1 || GetWindowPosition().y != 1) && isWindowBorderless) SetWindowPosition(0, 0);
  if(IsKeyPressed(KEY_A) && !isWindowBorderless) SetResolution(3); 
  if(IsKeyPressed(KEY_S) && !isWindowBorderless) SetResolution(2);
  if(IsKeyPressed(KEY_D) && !isWindowBorderless) SetResolution(1);
  if(IsKeyPressed(KEY_W) && !isWindowBorderless) SetResolution(0);
  //Work Someway in a Borderless Mode
  if(IsKeyPressed(KEY_F)) 
    ToggleBorderless();
    
}
void GameManager::Close()
{
  delete[] screenResolutions;
}

//          --DirectoryFile FramesInX FramesInY--
SpriteSheet::SpriteSheet(const char* nameFile, ushort fX, ushort fY)
{
  spriteBuffer = LoadTexture(nameFile);
  framesX=fX;
  framesY=fY;

  frameWidth = (float)(spriteBuffer.width/framesX);
  frameHeight = (float)(spriteBuffer.height/framesY);
}

//          --Name SpriteSheet InitialFrame AnimationFrames TimeperFrame--
Animation::Animation(char* name, SpriteSheet& spriteB, int initialF, int animationFs, float frameT)
{
  animationName = name;
  this->sprite = &spriteB;
  initialFrame = initialF;
  currentFrame = 0;
  animationFrames = animationFs;
  timer = 0.0f;
  frameTime = frameT;
}

Animation::Animation(char* name, SpriteSheet& spriteB, int frame)
{
  animationName = name;
  this->sprite = &spriteB;
  initialFrame = frame;
  currentFrame = 0;
  animationFrames = 0;
  timer = 0.0f;
  frameTime = 0.0f;
}

void Animation::Initialize()
{
  currentFrame = 0;
  timer = 0.0f;
  triggerCondition = false;
}

void Animation::Draw(Vector2 position, float scale)
{
  timer += GetFrameTime();

  if(timer >= frameTime) {
    timer = 0;
    currentFrame++;
  }

  if(currentFrame >= animationFrames) currentFrame = 0;

  DrawTexturePro(
    sprite->spriteBuffer,
    Rectangle{
      ((initialFrame+currentFrame)%(sprite->framesX))*sprite->frameWidth,
      ((initialFrame+currentFrame)/(sprite->framesX))*sprite->frameHeight,
      sprite->frameWidth,
      sprite->frameHeight},
    Rectangle{
      position.x,
      position.y,
      sprite->frameWidth*scale,
      sprite->frameHeight*scale
    },
    Vector2{0, 0},
    0,
    RAYWHITE);
}

TileMap::TileMap(char* file, ushort fX, ushort fY)
  : tileSheet(SpriteSheet{file, fX, fY}), tileDim({fX, fY})
{
  for(unsigned short k = 0; k < fX*fY; k++) {tiles.push_back(Animation{"tile", tileSheet, k});}
}

void TileMap::Load(char* file)
{
  std::ifstream input(file);
  input>>tilesX>>tilesY;
  for(unsigned int k = 0; k < tilesX*tilesY; k++) {
    int til;
    input>>til;
    tMap.push_back(til);
  }
}

void TileMap::Draw(float scale)
{
  for(unsigned int k = 0; k < tilesX*tilesY; k++) {
    tiles[tMap[k]].Draw({tileSheet.frameWidth*(k%tilesX)*scale, tileSheet.frameHeight*(k/tilesX)*scale}, scale);
  }
}

//        --AnimationArray  AnimationsSize--
Animator::Animator(Animation* animations, ushort animationsSize)
{
  animationArray = animations;
  neighborsSize = new ushort[animationsSize];
  neighbors = new ushort*[animationsSize];
  currentNode = 0;
}

void Animator::BuildNeighbors(ushort node, ushort size , ushort* neightorhood)
{
  *(neighbors+node) = new ushort[size];
  *(neighborsSize+node) = size;
  *(neighbors+node) = neightorhood;
}

void Animator::ChangeAnimation(ushort toAnimation)
{
  ushort* endNode = *(neighbors+currentNode) + *(neighborsSize + currentNode);
  if(std::find(*(neighbors+currentNode), endNode, toAnimation) == endNode) {
    std::cerr<<"Node not connected"<<std::endl;
    return;
  }
  currentNode = toAnimation;

  animationArray[currentNode].Initialize();

}

void Animator::UpdateAnimation(Vector2 position, float scale)
{
  #define neighborNode *(*(neighbors+currentNode)+i)

  animationArray[currentNode].Draw(position, scale);
  for(ushort i = 0; i < *(neighborsSize+currentNode); i++)
    if((animationArray[neighborNode].triggerCondition)) ChangeAnimation(neighborNode);
};

State::State(char* name)
{
    stateName = name;
}

template<class T>
void State::Initialize(T var)
{}

void State::Reset()
{}

void State::Update()
{
    std::cout<<"Please provide a override of Update()"<<std::endl;
}

StateMachine::StateMachine(Animator* animator, State** states)
  : currentState(nullptr), m_animator(animator), m_states(states){}

void StateMachine::ChangeState(State* newState){
    currentState = newState;
    currentState->Reset();
}

void StateMachine::Update()
{
    currentState->Update();
}
void ExitState(){

}

Vector2 FixPosition(Vector2 position)
{
  return {position.x * GetScreenWidth() / 1920 , position.y * GetScreenHeight() / 1080};
}
