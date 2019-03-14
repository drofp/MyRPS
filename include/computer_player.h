#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include <iostream>

#include "move.h"
#include "setting_option.h"
#include "chooser_factory.h"
#include "random_chooser.h"

using namespace std;

namespace myrps
{
class ComputerPlayer
{
private:
  Chooser *chooser;
  int round_count;

public:
  ComputerPlayer();
  ComputerPlayer(SettingOption mode, int round_count);
  Move DecideMove(Move player_move);
  void SetComputerMode(SettingOption mode);
};
} // namespace myrps
#endif
