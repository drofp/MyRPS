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
  Chooser *chooser;

public:
  ComputerPlayer();
  ComputerPlayer(SettingOption mode);
  Move DecideMove();
  void SetComputerMode(SettingOption mode);
};
} // namespace myrps
#endif
