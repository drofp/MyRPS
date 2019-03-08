#include "chooser_factory.h"
#include "setting_option.h"
#include "random_chooser.h"
#include "ml_chooser.h"

#include <iostream>

using namespace std;
using namespace myrps;

Chooser *ChooserFactory::MakeChooser(SettingOption choice)
{
  if(choice == SettingOption::D_RANDOM)
  {
    return new RandomChooser();
  }
  else if(choice == SettingOption::D_SMART)
  {
    return new MLChooser();
  }
  else if(choice == SettingOption::D_GENIUS)
  {
    return new MLChooser();
  }
  else
  {
    cout << "you chose none of those!" << endl;
  }

  return nullptr;
}
