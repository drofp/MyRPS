#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

#include "computer_player.h"
#include "setting_option.h"

#include <boost/algorithm/string.hpp>

using namespace std;

namespace myrps
{
class Game
{
public:
  Game();
  Game(SettingOption mode);
  void PlayMatch();
  void DisplayRound(MoveChoice player_move, MoveChoice computer_move);
  string PlayRound(MoveChoice player_move, MoveChoice computer_move);
  MoveChoice GetPlayerMove();
  MoveChoice GetComputerMove(MoveChoice player_move);
  
  int GetPlayerScore();
  int GetComputerScore();
  int GetTieGameCnt();
  int GetRoundCount();
  int GetRoundsPerMatch();
  MoveChoice GetComputerPrediction(const MoveChoice player_move);

  void SetComputerMode(SettingOption mode);
  void SetRoundsPerMatch(int rounds_per_match);

private:
  ComputerPlayer ai;

  int rounds_per_match = 20;
  int round_count = 1;
  int player_score = 0;
  int computer_score = 0;
  int tie_game_cnt = 0;

  bool IsValidMove(string user_move);
  void PrintScore();
};
} // namespace myrps

#endif
