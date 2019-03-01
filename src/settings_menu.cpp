#include <iostream>
#include <boost/algorithm/string.hpp>

#include "settings_menu.h"
#include "setting_option.h"

using namespace std;

namespace myrps
{
SettingsMenu::SettingsMenu()
{
  for (int i = 0; i < num_settings; i++)
  {
    settings.push_back(settings_list[i]);
  }
}

SettingOption SettingsMenu::displaySettings()
{
  cout << "Select difficulty!" << endl;
  SettingOption user_choice = GetUserChoice();
  switch (user_choice)
  {
  case SettingOption::D_EASY:
    std::cout << "Easy" << endl;
    break;
  case SettingOption::D_MEDIUM:
    std::cout << "Medium" << endl;
    break;
  case SettingOption::D_HARD:
    std::cout << "Hard" << endl;
    break;

  default:
    std::cout << "Whatever";
    break;
  }
  return user_choice;
}

SettingOption SettingsMenu::GetUserChoice()
{
  bool notValid = true;
  SettingOption user_choice;
  while (notValid)
  {
    string user_input;
    cout << "Here are your difficulties:" << endl;
    for (unsigned int i = 0; i < settings.size(); i++)
    {
      cout << settings[i] << "(" << i << ")" << endl;
    }
    cout << "What would you like to do?: ";
    cin >> user_input;
    user_choice = ValidateSetting(user_input);
    notValid = (user_choice == SettingOption::D_ERROR);
    cout << endl;
  }
  return user_choice;
}

SettingOption SettingsMenu::ValidateSetting(string val)
{
  SettingOption user_choice;
  if (stoi(val) == 0)
  {
    user_choice = SettingOption::D_EASY;
  }
  else if (stoi(val) == 1)
  {
    user_choice = SettingOption::D_MEDIUM;
  }
  else if (stoi(val) == 2)
  {
    user_choice = SettingOption::D_HARD;
  }
  else
  {
    user_choice = SettingOption::D_ERROR;
  }
  return user_choice;
}

} // namespace myrps