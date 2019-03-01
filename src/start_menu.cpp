#include <iostream>
#include <boost/algorithm/string.hpp>

#include "start_menu.h"
#include "start_option.h"
#include "game.h"

using namespace std;

namespace myrps
{
StartMenu::StartMenu()
{
  difficulty = SettingOption::D_EASY;
  for (int i = 0; i < num_options; i++)
  {
    options.push_back(options_list[i]);
  }

  game.SetComputerMode(difficulty);
}

void StartMenu::DisplayOptions()
{
  cout << "Welcome to MyRPS! " << endl;
  StartOption user_choice = GetUserChoice();
  if (user_choice == StartOption::PLAY_GAME)
  {
    PlayGame();
  }
  else if (user_choice == StartOption::OPTIONS)
  {
    SettingOption choice = settings.DisplaySettings();
    SetDifficulty(choice);
    DisplayOptions();
  }
}

void StartMenu::PlayGame()
{
  game.PlayMatch();
}

void StartMenu::SetDifficulty(SettingOption choice)
{
  difficulty = choice;
}

SettingOption StartMenu::GetCurrentDifficulty()
{
  return difficulty;
}

StartOption StartMenu::ValidateUserChoice(string val)
{
  StartOption user_choice;
  if (stoi(val) == 0)
  {
    user_choice = StartOption::PLAY_GAME;
  }
  else if (stoi(val) == 1)
  {
    user_choice = StartOption::OPTIONS;
  }
  else if (stoi(val) == 2)
  {
    user_choice = StartOption::EXIT;
  }
  else
  {
    user_choice = StartOption::ERROR;
  }
  return user_choice;
}

StartOption StartMenu::GetUserChoice()
{
  bool notValid = true;
  StartOption user_choice;
  while (notValid && user_choice != StartOption::EXIT)
  {
    string user_input;
    cout << "Here are your options:" << endl;
    for (unsigned int i = 0; i < options.size(); i++)
    {
      cout << options[i] << "(" << i << ")" << endl;
    }
    cout << "What would you like to do?: ";
    cin >> user_input;
    user_choice = ValidateUserChoice(user_input);
    notValid = (user_choice == StartOption::ERROR);
    cout << endl;
  }
  return user_choice;
}

} // namespace myrps
