#ifndef RANDOM_CHOOSER_H
#define RANDOM_CHOOSER_H

#include "chooser.h"

namespace myrps
{
class RandomChooser : public myrps::Chooser
{
public:
  Move DecideMove(Move player_move);
};
} // namespace myrps
#endif
