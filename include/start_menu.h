#ifndef START_MENU_H_
#define START_MENU_H_

#include <vector>

#include "start_option.h"
#include "settings_menu.h"
#include "move.h"
#include "game.h"

using namespace std;

namespace myrps
{
class StartMenu
{
public:
  StartMenu();
  void DisplayOptions();
  void PlayGame();
  void SetDifficulty(SettingOption choice);
  void DisplayDifficulties();
  SettingOption GetCurrentDifficulty();
  StartOption GetUserChoice(string val);

private:
  vector<StartOption> options;
  StartOption GetUserChoice();
  StartOption ConvertUserChoice(string val);
  bool ValidateUserChoice(string val);
  SettingOption difficulty;
  myrps::SettingsMenu settings;
  myrps::Game game;
};
} // namespace myrps
#endif
