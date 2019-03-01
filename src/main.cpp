#include <iostream>

#include "game.h"
#include "start_menu.h"

using namespace std;

int main()
{
  // myrps::StartMenu start;

  // start.displayOptions();

  cout << "Welcome to MyRPS!" << endl;

  int computer_chooser_mode = 0;
  myrps::Game this_game(computer_chooser_mode);

  this_game.PlayMatch();

  return 0;
}
