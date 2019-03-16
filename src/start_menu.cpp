#include <iostream>
#include <boost/algorithm/string.hpp>

#include "start_menu.h"

using namespace std;

namespace myrps
{
StartMenu::StartMenu()
{
  difficulty = SettingOption::kRandom;
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
  game.SetComputerMode(difficulty);
}

SettingOption StartMenu::GetCurrentDifficulty()
{
  return difficulty;
}

bool StartMenu::ValidateUserChoice(string val){
  return(val == "0" || val == "1" || val == "2");
}

StartOption StartMenu::ConvertUserChoice(string val)
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
  bool valid = false;
  StartOption user_choice;
  while (!valid)
  {
    string user_input;
    cout << "Here are your options:" << endl;
    for (unsigned int i = 0; i < options.size(); i++)
    {
      cout << options[i] << "(" << i << ")" << endl;
    }
    cout << "What would you like to do?: ";
    cin >> user_input;
    if(!ValidateUserChoice(user_input))
    {
      cout << "Please enter a valid option\n" << endl;
    }
    else
    {
      user_choice = ConvertUserChoice(user_input);
      cout << endl;
      valid = true;
    }
  }
  return user_choice;
}

} // namespace myrps
