#pragma once

#include <map>
#include <string>
#include <vector>

typedef struct DialogueManager
{
  std::map<std::string, std::vector<std::string>> dialogues;

  DialogueManager(char* filepath);
  void Render(std::string character, int id);
} DialogueManager;
