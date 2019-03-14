#ifndef ML_CHOOSER_H
#define ML_CHOOSER_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>

#include <sys/types.h>
#include <sys/stat.h>

#include "chooser.h"
#include "move.h"

using namespace std;

namespace myrps
{
class MLChooser : public myrps::Chooser
{
public:
  MLChooser(int round_count);
  Move DecideMove(Move player_move);

  unordered_map<string, int> GetHistData();

private:
  unordered_map<string, int> hist_data;
  unordered_map<string, int> old_hist_data;
  int n; // number of previous games recorded
  int round_count;
  queue<Move> last_n_minus_one_q;

  bool MLDirectoryExists();
  bool MLFileNExists();
  unordered_map<string, int> ReadHistData();
  vector<string> TokenizeHistData();
  unordered_map<string, int> ParseHistData(vector<string> raw_pairs);
  unordered_map<string, int> GenerateHistData();

  void WriteHistData();
  void UpdateHistData();

  Move GetWinningMove(Move most_likely_move);
  Move GetMostLikelyMove(string last_n_minus_one_moves);
  string GetLastNMinusOneMoves(queue<Move> q);
  static bool CompareMoveFreq(pair<string, int> &a,
    pair<string, int> &b);
  vector<pair<string, int>>
    GetPossibleChoices(string last_n_minus_one_moves);
  void
    InsertPossibleChoice(vector<pair<string, int>> &possible_choices,
                          string permutation);
};
}

#endif
