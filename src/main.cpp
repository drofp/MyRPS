#include <iostream>

#include "game.h"
#include "start_menu.h"
#include "settings_menu.h"

#include "ml_chooser.h"

using namespace std;

int main()
{
  myrps::StartMenu start;
  start.DisplayOptions();

  // myrps::MLChooser ml_chooser;
  // unordered_map<string, int> test_map = ml_chooser.GetHistData();


  return 0;
}
