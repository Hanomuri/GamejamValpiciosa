#pragma once

#include "core.h"
#include <string>

typedef struct Todo {
  Font font;
  bool toggle = 0;
  bool taskCheck[5] = {0};
  const char* task[5] = {"When haces", "tus momos", "en un", "motherfokin", "videojogo"};
  SpriteSheet dot = {"resources/images/todo/dot.png", 2, 1};
  SpriteSheet page = {"resources/images/todo/todopage.png", 1, 1};
  Animation dotuncheck = {"dot_uncheck", dot, 0, 0, 0};
  Animation dotcheck = {"dot_check", dot, 1, 1, 0};
  Animation pageIdle = {"page", page, 0, 0, 0};

  Todo() {
    font = LoadFontEx("resources/fonts/IllusionBook-Regular.ttf", 100, NULL, 0);
  };
  void Draw(const Camera2D &camera);
} todo;
