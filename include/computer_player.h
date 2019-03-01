#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include <iostream>

#include "move.h"
#include "setting_option.h"
#include "random_chooser.h"

using namespace std;

namespace myrps
{
class ComputerPlayer
{
private:
  Move player_move;
  Chooser *chooser;

public:
  ComputerPlayer();
  ComputerPlayer(SettingOptions::SettingOption mode);
  Move DecideMove();
  Chooser *MakeChooser(SettingOptions::SettingOption mode);
  void SetComputerMode(SettingOptions::SettingOption mode);
};
} // namespace myrps
#endif
