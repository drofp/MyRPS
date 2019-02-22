#include <iostream>
#include <cstdlib>

#include "computer_player.h"

using namespace std;

namespace myrps
{
Move ComputerPlayer::DecideMove()
{
  Move computer_move = static_cast<Move>(rand() % static_cast<int>(Move::kScissors));
  return computer_move;
}
} // namespace myrps
