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

  int rounds_per_match = 20;
  int round_count = 1;
  int player_score = 0;
  int computer_score = 0;
  int tie_game_cnt = 0;

  bool IsValidMove(string user_move);
  void PlayRound(Move player_move, Move computer_move);
  void PrintScore();

public:
  Game();
  Game(SettingOption mode);
  void PlayMatch();
  Move GetPlayerMove();
  Move GetComputerMove();
  int GetRoundCount();
  void SetComputerMode(SettingOption mode);
  void SetRoundsPerMatch(int rounds_per_match);
};

} // namespace myrps

#endif
