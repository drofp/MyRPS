#ifndef START_MENU_H_
#define START_MENU_H_

#include <vector>

#include "start_option.h"
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
        bool setDifficulty();
        void displayDifficulties();
        int getCurrentDifficulty();
        StartOption GetUserChoice(string val);

    private:
        vector<StartOption> options;
        StartOption GetUserChoice();
        StartOption ValidateUserChoice(string val);
        myrps::Game game;
        // Difficulty current_difficulty;
    };
}
#endif
