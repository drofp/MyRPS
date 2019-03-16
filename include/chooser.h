#ifndef CHOOSER_H
#define CHOOSER_H

#include "move.h"

namespace myrps
{
class Chooser
{
public:
  virtual Move DecideMove(Move player_move) = 0;
};
} // namespace myrps
#endif
