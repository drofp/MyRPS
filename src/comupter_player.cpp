#include <iostream>
#include <cstdlib>

#include "computer_player.h"

using namespace std;

namespace myrps
{
ComputerPlayer::ComputerPlayer()
{
}

ComputerPlayer::ComputerPlayer(SettingOption mode)
{
  this->chooser = MakeChooser(mode);
}

Move ComputerPlayer::DecideMove()
{
  Move computer_move = chooser->DecideMove();
  return computer_move;
}

Chooser *ComputerPlayer::MakeChooser(SettingOption mode)
{
  Chooser *chooser = nullptr;

  if (mode == SettingOption::D_EASY)
    chooser = new RandomChooser();
  else
    cout << "Invalid move chooser!!" << endl;

  return chooser;
}

void ComputerPlayer::SetComputerMode(SettingOption mode)
{
  chooser = MakeChooser(mode);
}
} // namespace myrps
