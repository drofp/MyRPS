#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "move_choice.h"
#include "setting_option.h"
#include "chooser_factory.h"
#include "random_chooser.h"

#include <iostream>
#include <cstdlib>

using namespace std;

namespace myrps
{
class ComputerPlayer
{
private:
  Chooser *chooser;
  int rounds_per_match;

public:
  ComputerPlayer();
  ComputerPlayer(SettingOption mode, int rounds_per_match);
  MoveChoice DecideMove(MoveChoice player_move);
  void SetComputerMode(SettingOption mode);
};
} // namespace myrps
#endif
