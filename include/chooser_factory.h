#ifndef CHOOSER_FACTORY_H_
#define CHOOSER_FACTORY_H_

#include "chooser.h"
#include "setting_option.h"

namespace myrps
{
class ChooserFactory
{
public:
  static Chooser *MakeChooser(SettingOption choice);
};
}
#endif
