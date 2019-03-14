#include "chooser_factory.h"
#include "setting_option.h"
#include "random_chooser.h"
#include "ml_chooser.h"

#include <iostream>

using namespace std;
using namespace myrps;

Chooser *ChooserFactory::MakeChooser(SettingOption choice)
{
  if(choice == SettingOption::kRandom)
  {
    return new RandomChooser();
  }
  else if(choice == SettingOption::kSmart)
  {
    return new RandomChooser();
  }
  else if(choice == SettingOption::kGenius)
  {
    return new RandomChooser();
  }
  else
  {
    cout << "you chose none of those!" << endl;
  }

  return nullptr;
}
