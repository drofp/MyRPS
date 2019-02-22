#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include <iostream>

#include "move.h"

using namespace std;

namespace myrps
{

class ComputerPlayer
{
private:
  Move player_move;

public:
  Move DecideMove();
};

} // namespace myrps
#endif
