#include "dialogue.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::map<std::string, std::vector<std::string>> dialogues;

DialogueManager::DialogueManager(char* filepath) 
{
  std::string in;
  std::ifstream file(filepath);
  while(getline(file, in)) {
    std::stringstream ss(in);
    std::stringstream parser;
    std::string character;
    ss>>character;
    in.clear();
    while(ss>>in) {
      parser<<in<<" ";
    }
    std::cout<<character<<parser.str()<<std::endl;
  }
  
}

void DialogueManager::Render(std::string character, int id)
{
}
