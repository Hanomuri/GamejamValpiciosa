#pragma once

#include "core.h"
#include "raylib.h"
#include <map>
#include <string>
#include <vector>

typedef struct DialogueManager
{
  std::map<std::string, std::vector<std::pair<bool, std::string>>> dialogues;
  Font font;
  SpriteSheet humanUI = {"resources/images/UI/textBubbleHuman.png", 1, 1};
  SpriteSheet spiritUI = {"resources/images/UI/textBubbleSpirit.png", 1, 1};
  Animation human = {"human", humanUI, 0};
  Animation spirit = {"spirit", spiritUI, 0};
  Camera2D* m_camera;

  DialogueManager(char* filepath, Camera2D* cam);
  void Render(std::string character, int id);
} DialogueManager;
