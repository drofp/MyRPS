#include <iostream>
#include <boost/algorithm/string.hpp>

#include "start_menu.h"
#include "start_option.h"
#include "game.h"

using namespace std;
using namespace StartOptions;

namespace myrps
{
    StartMenu::StartMenu()
    {
        for (int i = 0; i < num_options; i++)
        {
            options.push_back(options_list[i]);
        }
    }

    void StartMenu::displayOptions()
    {
        cout << "Welcome to MyRPS!" << endl;
        StartOption user_choice = GetUserChoice();
        if(user_choice == StartOption::PLAY_GAME)
        {
            playGame();
        }
    }

    void StartMenu::playGame()
    {
        game.PlayMatch();
    }

    bool StartMenu::setDifficulty()
    {
        //can't do this until enum is done
        return false;
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
            user_choice = ValidateUserChoice(user_input);
            notValid = (user_choice == StartOption::ERROR);
        }
        return user_choice;
    }

    // Difficulty getCurrentDifficulty()
    // {

    // }

} // namespace myrps

