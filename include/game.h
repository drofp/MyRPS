#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "computer_player.h"
#include "setting_option.h"

using namespace std;

namespace myrps
{
class Game
{
private:
  ComputerPlayer ai;

  const int rounds_per_match = 5; // TODO: Why can't make after changing ONLY this value?
  int round_count = 0;
  int player_score = 0;
  int computer_score = 0;
  int tie_game_cnt = 0;

  bool IsValidMove(string user_move);
  void PlayRound(Move player_move, Move computer_move);
  void PrintScore();

public:
  Game();
  Game(SettingOptions::SettingOption mode);
  void PlayMatch();
  Move GetPlayerMove();
  Move GetComputerMove();
  void SetComputerMode(SettingOptions::SettingOption mode);
};

} // namespace myrps

#endif
