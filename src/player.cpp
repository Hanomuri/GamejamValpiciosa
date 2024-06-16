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
}

void Player::Move(float x, float y, int tX, int tY)
{
  Transform* t = GetTransform();
  if (tX == 0) {
    t->translation.x += x;
    t->translation.y += y;
    return;
  }
  if(x > 0){
    //std::cout<<"X > 0"<<std::endl;
    t->translation.x = (t->translation.x+(x*2) > tX*128) ? tX*128 : t->translation.x+x;
  } else if(x < 0) {
    //std::cout<<t->translation.x<<" "<<t->translation.y<<std::endl;
    t->translation.x = (t->translation.x+x < tX*128+128) ? tX*128+128: t->translation.x+x;
  } else if(y > 0)
    t->translation.y = (t->translation.y+y > tY*128) ? tY*128 : t->translation.y+y;
  else
    t->translation.y = (t->translation.y+y < tY*128+128) ? tY*128+128: t->translation.y+y;
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
  pos.x -= 70; pos.y -= 40;
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
  if(IsKeyDown(KEY_D)) {
    move.x = 5; tX++;
  }
  //std::cout<<pos.x<<" "<<pos.y<<std::endl;
  //if(collider.colliderMap[tY][tX]) std::cout<<"COLISION\n";
  if(collider.colliderMap[tY][tX]) Move(move.x, move.y, tX, tY);
  else Move(move.x, move.y, 0, 0);
  pos = GetTransform()->translation;
  DrawRectangle(pos.x-64, pos.y-128, 128, 256, RED);
  SetCamera();
  if(todo.toggle) todo.Draw(m_camera);
}
