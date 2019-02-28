#include <iostream>
#include <boost/algorithm/string.hpp>

#include "settings_menu.h"
#include "setting_option.h"

using namespace std;
using namespace SettingOptions;

namespace myrps
{
    SettingsMenu::SettingsMenu()
    {
        for (int i = 0; i < num_options; i++)
        {
            options.push_back(options_list[i]);
        }
    }

    void SettingsMenu::displaySettings()
    {
        cout << "Select difficulty!" << endl;
        SettingOption user_choice = GetUserChoice();
        switch (user_choice)
        {
            case SettingOption::D_EASY:
                std::cout << "Easy";
                break;
            case SettingOption::D_MEDIUM:
                std::cout << "Medium";
                break;
            case SettingOption::D_HARD:
                std::cout << "Hard";
                break;

            default:
                std::cout << "Whatever";
                break;
        }
    }

    SettingOption SettingsMenu::GetUserChoice()
    {
        bool notValid = true;
        SettingOption user_choice;
        while(notValid)
        {
            string user_input;
            cout << "Here are your options:" << endl;
            for(unsigned int i = 0; i < options.size(); i++)
            {
                cout << options[i] << "(" << i << ")" << endl;
            }
            cout << "What would you like to do?: ";
            cin >> user_input;
            user_choice = ValidateSetting(user_input);
            notValid = (user_choice == SettingOption::ERROR);
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
            user_choice = SettingOption::ERROR;
        }
        return user_choice;
    }

} // namespace myrps