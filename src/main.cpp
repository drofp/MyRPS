#include <iostream>

#include "game.h"

using namespace std;

int main()
{
  cout << "Welcome to MyRPS!" << endl;

  myrps::Game this_game;

  this_game.PlayMatch();

  return 0;
}
