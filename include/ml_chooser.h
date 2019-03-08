#ifndef ML_CHOOSER_H
#define ML_CHOOSER_H

#include "chooser.h"

namespace myrps
{
class MLChooser : public myrps::Chooser
{
public:
  Move DecideMove();
};
}

#endif
