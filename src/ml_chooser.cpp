#include "ml_chooser.h"

using namespace std;

namespace myrps
{
  MLChooser::MLChooser()
  {
  }

  MLChooser::MLChooser(Game current_game, int n)
  {
    if (n < 1)
      cout << "Invalid value of N! Please select value greater than 0." << endl;
    
    this->current_game = current_game;
    this->n = n;
    // TODO: instantiate `hist_data` with file read in GetHistData()
  }

  unordered_map<string, int> GetHistData()
  {
    // IF FILE EXISTS, Read from freq data (map structured CSV) to get freq data
    // IF FILE EXISTS, Read from raw data to construct freq data
    // ELSE, initialize `hist_data` to empty map
  }

  // TODO: improve speed with sorted data to reduce to O(n*lg(n))
  void WriteHistData()
  {
    // IF FILE EXISTS, for every element in `hist_data`
    //  IF element in file, add `hist_data` count to file count
    //  ELSE append new element to end of file
    // ELSE create file and write entire `hist_data` to file
  }

  Move MLChooser::DecideMove()
  {
    Move computer_move = Move::kScissors;
    if (hist_data.empty())
    {
      computer_move = 
        static_cast<Move>(rand() % static_cast<int>(Move::kScissors));
      return computer_move;
    }

    // IF current move is less than n, use random algo (add to above IF condition)
    // ELSE GetWinningMove(), and return it

    return computer_move;
  }

  Move MLChooser::GetMostLikelyMove(string last_n_moves)
  {
    Move most_likely_move;

    vector<pair<string, int>> possible_moves = 
      MLChooser::GetPossibleChoices(last_n_moves);

      sort(possible_moves.begin(), possible_moves.end(), 
        MLChooser::CompareMoveFreq);

    char most_likely_move_str = possible_moves.at(0).first.back();
    if (most_likely_move_str == 'r')
      most_likely_move = Move::kRock;
    else if (most_likely_move_str == 'p')
      most_likely_move = Move::kPaper;
    else if (most_likely_move_str == 's')
      most_likely_move = Move::kScissors;
    else
      cout << "No valid most likely move.." << endl;
    
    return most_likely_move;
  }

  bool MLChooser::CompareMoveFreq(pair<string, int> &a,
    pair<string, int> &b)
    {

      return a.first > b.first;
    }

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
