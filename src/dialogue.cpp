#include "dialogue.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

DialogueManager::DialogueManager(char* filepath, Camera2D* cam) 
  : m_camera(cam)
{
  font = LoadFontEx("resources/fonts/IllusionBook-Regular.ttf", 100, NULL, 0);
  std::string in;
  std::ifstream file(filepath);
  while(getline(file, in)) {
    std::stringstream ss(in);
    std::stringstream parser;
    std::string character;
    bool smellLikeTeenSpirit;
    ss>>character>>smellLikeTeenSpirit;
    in.clear();
    while(ss>>in) {
      parser<<in<<" ";
    }
    dialogues[character].push_back({smellLikeTeenSpirit, parser.str()});
    if(smellLikeTeenSpirit) std::cout<<character<<" "<<parser.str()<<std::endl;
  }
}

void DialogueManager::Render(std::string character, int id)
{
  Vector2 posBox = GetScreenToWorld2D({400, 700}, *m_camera);
  if(dialogues[character][id].first) spirit.Draw(posBox, 8);
  else human.Draw(posBox, 8);
  posBox.x += 340;
  posBox.y += 30;
  DrawTextEx(font, character.c_str(), posBox, 80, 0, BLACK);
  posBox.y += 50;
  std::stringstream ss(dialogues[character][id].second);
  std::stringstream visible;
  std::string parser;
  while(ss>>parser) {
    parser.push_back(' ');
    int a = MeasureTextEx(font, visible.str().c_str(), 80, 0).x;
    int b = MeasureTextEx(font, parser.c_str(), 80, 0).x;
    if(740+a+b < 1400) {
      visible<<parser;
    } else {
      DrawTextEx(font, visible.str().c_str(), posBox, 80, 0, BLACK);
      visible.clear();
      visible.str(std::string());
      visible<<parser;
      posBox.y += 50;
    }
  }
  DrawTextEx(font, visible.str().c_str(), posBox, 80, 0, BLACK);
}
