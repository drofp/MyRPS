#include "chooser_factory.h"

using namespace std;
using namespace myrps;

Chooser *ChooserFactory::MakeChooser(SettingOption choice, int rounds_per_match)
{
  if(choice == SettingOption::kRandom)
  {
    return new RandomChooser();
  }
  else if(choice == SettingOption::kSmart)
  {
    return new MLChooser(rounds_per_match);
  }
  else
  {
    cout << "you chose none of those!" << endl;
  }

  return nullptr;
}
