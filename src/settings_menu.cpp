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

SettingOption SettingsMenu::DisplaySettings()
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
  bool valid = false;
  SettingOption user_choice;
  while (!valid)
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
    if(user_choice == SettingOption::D_ERROR)
    {
      cout << "Please enter a valid difficulty\n" << endl;    
    }else{
      valid = true;
      cout << endl;
    }
  }
  return user_choice;
}

SettingOption SettingsMenu::ValidateSetting(string val)
{
  SettingOption user_choice;
  if(val != "0" && val != "1" && val != "2")
  {
    user_choice = SettingOption::D_ERROR;
  }
  else if (stoi(val) == 0)
  {
    user_choice = SettingOption::D_EASY;
  }
  else if (stoi(val) == 1)
  {
    user_choice = SettingOption::D_MEDIUM;
  }
  else
  {
    //stoi(val) == 2
    user_choice = SettingOption::D_HARD;
  }
  return user_choice;
}

} // namespace myrps
