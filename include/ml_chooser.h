#ifndef ML_CHOOSER_H
#define ML_CHOOSER_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

#include "chooser.h"
#include "game.h"

using namespace std;

namespace myrps
{
class MLChooser : public myrps::Chooser
{
public:
  MLChooser();
  MLChooser(Game current_game, int n);
  Move DecideMove();
private:
  unordered_map<string, int> hist_data;
  Game current_game;
  int n; // number of previous games recorded

  unordered_map<string, int> GetHistData();
  void WriteHistData();
  Move GetWinningMove(Move most_likely_move);
  Move GetMostLikelyMove(string last_n_moves);
  static bool CompareMoveFreq(pair<string, int> &a,
    pair<string, int> &b);
  vector<pair<string, int>>
    GetPossibleChoices(string last_n_moves);
  void
    InsertPossibleChoice(vector<pair<string, int>> &possible_choices,
                          string permutation);
};
}

#endif
