#include <algorithm>
#include <iostream>
#include "player.h"

Player::Player()
{
  SetTransform(540, 340);
  m_camera.target = {GetTransform()->translation.x, GetTransform()->translation.y};
  m_camera.offset = (Vector2){ 1960.0f/2, 1080.0f/2 };
  m_camera.rotation = 0.0f;
  m_camera.zoom = 1.0f;
  
  m_animator.BuildNeighbors(0, 3, rIdleN);
  m_animator.BuildNeighbors(1, 3, rMoveN);
  m_animator.BuildNeighbors(2, 2, lIdleN);
  m_animator.BuildNeighbors(3, 2, lMoveN);
  m_animator.BuildNeighbors(4, 2, uIdleN);
  m_animator.BuildNeighbors(5, 3, uMoveN);
}

void Player::Move(float x, float y, int tX, int tY)
{
  Transform* t = GetTransform();
  if (tX == -1) {
    t->translation.x += x;
    t->translation.y += y;
    return;
  }
  if(x > 0){
    //std::cout<<"X > 0"<<std::endl;
    t->translation.x = (t->translation.x+x > (tX-1)*128) ? t->translation.x : t->translation.x+x;
  } else if(x < 0) {
    t->translation.x = (t->translation.x+x < (tX)*128) ? t->translation.x: t->translation.x+x;
  } else if(y > 0)
    t->translation.y = (t->translation.y+y > (tY-1)*128) ? t->translation.y : t->translation.y+y;
  else
    t->translation.y = (t->translation.y+y < (tY)*128) ? t->translation.y: t->translation.y+y;
}

void Player::SetCamera()
{
  m_camera.offset = (Vector2){ 1960.0f/2, 1080.0f/2 };
  m_camera.target = {GetTransform()->translation.x, GetTransform()->translation.y};
  /*
  float minX = 1000, minY = 1000, maxX = -1000, maxY = -1000;
  Vector2 max = GetWorldToScreen2D((Vector2){ maxX, maxY }, m_camera);
  Vector2 min = GetWorldToScreen2D((Vector2){ minX, minY }, m_camera);

  if (max.x < 1920) m_camera.offset.x = 960 - (max.x - 960);
  if (max.y < 1080) m_camera.offset.y = 540 - (max.y - 540);
  if (min.x > 0) m_camera.offset.x = 960 - min.x;
  if (min.y > 0) m_camera.offset.y = 540 - min.y;*/
}

void Player::Update()
{
    if(IsKeyPressed(KEY_H)) TogglePills();
  if(hasPills)
  {
    if(IsKeyPressed(KEY_Q)) dangerLevel++;
    if(IsKeyPressed(KEY_E)) dangerLevel--;
  }

  if(IsKeyPressed(KEY_TAB)) todo.toggle  = (todo.toggle) ? 0 : 1;
  int tX, tY;
  Vector3 pos = GetTransform()->translation;
  pos.x += 50; pos.y += 40;
  if(pos.x < 0) pos.x = 0;
  if(pos.y < 0) pos.y = 0;
  Vector2 move = {0, 0};
  tX = (int)(pos.x)/128;
  tY = (int)(pos.y)/128;
  if(IsKeyDown(KEY_W)) {
    move.y = -5;
  } 
  if(IsKeyDown(KEY_A)) {
    move.x = -5;
  } 
  if(IsKeyDown(KEY_S)) {
    move.y = 5; tY++;
  } 
  if (IsKeyDown(KEY_D)) {
    move.x = 5; tX++;
  }
  //std::cout<<"X: "<<pos.x<<" Tile: "<<tX<<'\n';
  //std::cout<<"Y: "<<pos.y<<" Tile: "<<tY<<std::endl;
  //if(collider.colliderMap[tY][tX]) std::cout<<"COLISION\n";
  if(collider.colliderMap[tY][tX]) Move(move.x, move.y, tX, tY);
  else Move(move.x, move.y, -1, 0);
  pos = GetTransform()->translation;
  m_animator.UpdateAnimation({pos.x, pos.y}, 8);
  SetCamera();
  if(todo.toggle) todo.Draw(m_camera);
}
