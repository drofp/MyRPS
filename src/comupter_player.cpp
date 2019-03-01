#include <iostream>
#include <cstdlib>

#include "computer_player.h"

using namespace std;

namespace myrps
{
ComputerPlayer::ComputerPlayer()
{
}

ComputerPlayer::ComputerPlayer(SettingOptions::SettingOption mode)
{
  this->chooser = MakeChooser(mode);
}

Move ComputerPlayer::DecideMove()
{
  Move computer_move = chooser->DecideMove();
  return computer_move;
}

Chooser *ComputerPlayer::MakeChooser(SettingOptions::SettingOption mode)
{
  Chooser *chooser;

  if (mode == SettingOptions::SettingOption::D_EASY)
    chooser = new RandomChooser();
  else
    cout << "Invalid move chooser!!" << endl;

  return chooser;
}

void ComputerPlayer::SetComputerMode(SettingOptions::SettingOption mode)
{
  chooser = MakeChooser(mode);
}
} // namespace myrps
