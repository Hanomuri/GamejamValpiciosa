#include <iostream>
#include "todo.h"

void Todo::Draw(const Camera2D &camera)
{
  //std::cout<<GetScreenToWorld2D({640, 10}, camera).x<<std::endl;
  pageIdle.Draw(GetScreenToWorld2D({640, 10}, camera), 10);

  for(int k = 0; k < 5; k++) {
    if(taskCheck[k]) dotcheck.Draw(GetScreenToWorld2D({1480, (float)(100+(k*70))}, camera), 10);
    else dotuncheck.Draw(GetScreenToWorld2D({1480, (float)(100+(k*70))}, camera), 10);
    DrawTextEx(font, task[k], GetScreenToWorld2D({1540, (float)(80+(k*70))}, camera), 80, 0, BLACK);
  }
}
