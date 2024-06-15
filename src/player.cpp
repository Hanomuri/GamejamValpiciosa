#include <iostream>
#include "player.h"

Player::Player()
{
  SetTransform(960, 540);
  m_camera.target = {GetTransform()->translation.x, GetTransform()->translation.y};
  m_camera.offset = (Vector2){ 960.0f, 540.0f };
  m_camera.rotation = 0.0f;
  m_camera.zoom = 1.0f;
}

void Player::SetCamera()
{
  m_camera.target = {GetTransform()->translation.x, GetTransform()->translation.y};
}

void Player::Update()
{
  if(IsKeyPressed(KEY_TAB)) todo.toggle  = (todo.toggle) ? 0 : 1;
  if(IsKeyDown(KEY_W)) Move(0, -5);
  if(IsKeyDown(KEY_A)) Move(-5, 0);
  if(IsKeyDown(KEY_S)) Move(0, 5);
  if(IsKeyDown(KEY_D)) Move(5, 0);
  if(todo.toggle) todo.Draw(m_camera);

  SetCamera();
}
