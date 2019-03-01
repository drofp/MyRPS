#ifndef START_MENU_H_
#define START_MENU_H_

#include <vector>

#include "start_option.h"
#include "settings_menu.h"
#include "move.h"
#include "game.h"

using namespace std;
using namespace StartOptions;

namespace myrps
{
    class StartMenu
    {
    public:
        StartMenu();
        void displayOptions();
        void playGame();
        void setDifficulty(SettingOption choice);
        void displayDifficulties();
        SettingOption getCurrentDifficulty();
        StartOption GetUserChoice(string val);

    private:
        vector<StartOption> options;
        StartOption GetUserChoice();
        StartOption ValidateUserChoice(string val);
        SettingOption difficulty;
        myrps::SettingsMenu settings;
        myrps::Game game;
        // Difficulty current_difficulty;
    };
}
#endif
