#include "dialogue.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

DialogueManager::DialogueManager(char* filepath) 
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
  if(dialogues[character][id].first) spirit.Draw({400,700}, 8);
  else human.Draw({400,700}, 8);
}
