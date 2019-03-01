#include <iostream>

#include "game.h"
#include "start_menu.h"
#include "settings_menu.h"

using namespace std;

int main()
{
  myrps::SettingsMenu start;

  start.displaySettings();

  return 0;
}
