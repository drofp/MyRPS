#include <iostream>
#include <cstdlib>

#include "computer_player.h"

using namespace std;

namespace myrps
{
ComputerPlayer::ComputerPlayer()
{
}

ComputerPlayer::ComputerPlayer(int mode)
{
  this->chooser = MakeChooser(mode);
}

Move ComputerPlayer::DecideMove()
{
  Move computer_move = chooser->DecideMove();
  return computer_move;
}

Chooser *ComputerPlayer::MakeChooser(int mode)
{
  Chooser *chooser;

  if (mode == 0)
    chooser = new RandomChooser();
  else
    cout << "Invalid move chooser!!" << endl;

  return chooser;
}
} // namespace myrps
