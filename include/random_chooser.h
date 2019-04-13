#ifndef RANDOM_CHOOSER_H
#define RANDOM_CHOOSER_H

#include "chooser.h"

namespace myrps
{
class RandomChooser : public myrps::Chooser
{
public:
  MoveChoice DecideMove(MoveChoice player_move);
  MoveChoice GetPredictedMove(MoveChoice player_move);
  void SetRoundsPerMatch(int rounds_per_match);
};
} // namespace myrps
#endif
