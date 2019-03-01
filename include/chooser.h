#ifndef CHOOSER_H
#define CHOOSER_H

#include "move.h"

namespace myrps
{
class Chooser
{
public:
  virtual Move DecideMove() = 0;
};
}

#endif
