#include <iostream>

#include "random_chooser.h"

using namespace std;

namespace myrps
{
  Move RandomChooser::DecideMove()
  {
    Move computer_move = static_cast<Move>(rand() % static_cast<int>(Move::kScissors));

    return computer_move;
  }
}