#include <iostream>

#include "random_chooser.h"

using namespace std;

namespace myrps
{
  MoveChoice RandomChooser::DecideMove(MoveChoice player_move)
  {
    MoveChoice computer_move = static_cast<MoveChoice>(rand() % static_cast<int>(MoveChoice::kScissors));

    return computer_move;
  }

  MoveChoice RandomChooser::GetPredictedMove(MoveChoice player_move)
  {
    return MoveChoice::kScissors;
  }
} // namespace myrps