#ifndef CHOOSER_FACTORY_H_
#define CHOOSER_FACTORY_H_

#include "setting_option.h"

#include "chooser.h"
#include "random_chooser.h"
#include "ml_chooser.h"

#include <iostream>

namespace myrps
{
class ChooserFactory
{
public:
  static Chooser *MakeChooser(SettingOption choice, int round_count);
};
}
#endif
