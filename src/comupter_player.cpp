#include <iostream>
#include <cstdlib>

#include "computer_player.h"

using namespace std;

namespace myrps
{
ComputerPlayer::ComputerPlayer()
{
}

ComputerPlayer::ComputerPlayer(SettingOption mode, int round_count)
{
  this->round_count = round_count;
  this->chooser = ChooserFactory::MakeChooser(mode, round_count);
}

Move ComputerPlayer::DecideMove(Move player_move)
{
  Move computer_move = chooser->DecideMove(player_move);
  return computer_move;
}

void ComputerPlayer::SetComputerMode(SettingOption mode)
{
  chooser = ChooserFactory::MakeChooser(mode, round_count);
}
} // namespace myrps
