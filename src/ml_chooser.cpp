#include "ml_chooser.h"

using namespace std;

namespace myrps
{
  Move MLChooser::DecideMove()
  {
    Move computer_move = Move::kScissors;

    return computer_move;
  }

  Move MLChooser::GetMostLikelyMove(string last_n_moves)
  {
    Move most_likely_move;

    vector<pair<string, int>> possible_moves = 
      MLChooser::GetPossibleChoices(last_n_moves);

      // sort(possible_moves.begin(), possible_moves.end(), 
      //   this->CompareMoveFreq);

    return most_likely_move;
  }

  // bool MLChooser::CompareMoveFreq(unordered_map<string, int> &a,
  //   unordered_map<string, int> &b)
  //   {

  //     return a. > b->first;
  //   }

  // TODO: Replace with search algorithm for expandability. Maybe store hist as 
  // tree for improved search time.
  vector<pair<string, int>> 
  MLChooser::GetPossibleChoices(string last_n_moves)
  {
    vector<pair<string, int>> possible_choices;

    string permutation;
    permutation = last_n_moves + "r";
    MLChooser::InsertPossibleChoice(possible_choices, permutation);

    permutation = last_n_moves + "p";
    MLChooser::InsertPossibleChoice(possible_choices, permutation);

    permutation = last_n_moves + "s";
    MLChooser::InsertPossibleChoice(possible_choices, permutation);
      
    return possible_choices;
  }

  void MLChooser::InsertPossibleChoice(
    vector<pair<string, int>> &possible_choices,
    string permutation)
  {
    unordered_map<string, int> possible_choice;

    unordered_map<string, int>::iterator it = hist_data.find(permutation);
    if (it != hist_data.end())
    {
      // possible_choice[permutation] = hist_data.find(permutation)->second;
      possible_choices.push_back(
        make_pair(permutation, hist_data.find(permutation)->second));
    }
    else
    {
      possible_choices.push_back(
        make_pair(permutation, 0));
    }
  }
}
