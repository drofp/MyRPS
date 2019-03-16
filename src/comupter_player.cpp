#include "computer_player.h"

namespace myrps
{
ComputerPlayer::ComputerPlayer()
{
}

ComputerPlayer::ComputerPlayer(SettingOption mode, int rounds_per_match)
{
  this->rounds_per_match = rounds_per_match;
  this->chooser = ChooserFactory::MakeChooser(mode, rounds_per_match);
}

Move ComputerPlayer::DecideMove(Move player_move)
{
  Move computer_move = chooser->DecideMove(player_move);
  return computer_move;
}

void ComputerPlayer::SetComputerMode(SettingOption mode)
{
  chooser = ChooserFactory::MakeChooser(mode, rounds_per_match);
}
} // namespace myrps
