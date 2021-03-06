#include <iostream>

#include "random_chooser.h"

using namespace std;

namespace myrps
{
MoveChoice RandomChooser::DecideMove(MoveChoice player_move)
{
  MoveChoice computer_move = static_cast<MoveChoice>(
                              rand() % static_cast<int>(MoveChoice::length));

  return computer_move;
}

MoveChoice RandomChooser::GetPredictedMove(MoveChoice player_move)
{
  return MoveChoice::kScissors;
}

void RandomChooser::SetRoundsPerMatch(int rounds_per_match)
{
  return;
}
} // namespace myrps