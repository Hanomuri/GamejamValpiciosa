#include <iostream>
#include "todo.h"

void Todo::Draw(Font font)
{
  //std::cout<<pageIdle.animationName<<std::endl;
  pageIdle.Draw({640, 10}, 10);

  for(int k = 0; k < 5; k++) {
    if(taskCheck[k]) dotcheck.Draw({1480, (float)(100+(k*70))}, 10);
    else dotuncheck.Draw({1480, (float)(100+(k*70))}, 10);
    DrawTextEx(font, task[k], {1540, (float)(80+(k*70))}, 80, 0, BLACK);
  }
}
