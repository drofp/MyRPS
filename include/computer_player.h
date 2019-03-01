#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include <iostream>

#include "move.h"
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
  ComputerPlayer(int mode);
  Move DecideMove();
  Chooser *MakeChooser(int mode);
};

} // namespace myrps
#endif
