#ifndef RANDOM_CHOOSER_H
#define RANDOM_CHOOSER_H

#include "chooser.h"

namespace myrps
{
class RandomChooser : public myrps::Chooser
{
public:
  MoveChoice DecideMove(MoveChoice player_move);
};
} // namespace myrps
#endif
