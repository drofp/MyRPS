#ifndef CHOOSER_H
#define CHOOSER_H

#include "move_choice.h"

namespace myrps
{
class Chooser
{
public:
  virtual MoveChoice DecideMove(MoveChoice player_move) = 0;
};
} // namespace myrps
#endif
