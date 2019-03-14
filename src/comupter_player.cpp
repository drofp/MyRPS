#include <iostream>
#include <cstdlib>

#include "computer_player.h"
#include "chooser_factory.h"

using namespace std;

namespace myrps
{
ComputerPlayer::ComputerPlayer()
{
}

ComputerPlayer::ComputerPlayer(SettingOption mode)
{
  this->chooser = ChooserFactory::MakeChooser(mode);
}

Move ComputerPlayer::DecideMove()
{
  Move computer_move = chooser->DecideMove();
  return computer_move;
}

void ComputerPlayer::SetComputerMode(SettingOption mode)
{
  chooser = ChooserFactory::MakeChooser(mode);
}
} // namespace myrps
