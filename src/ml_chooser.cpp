#include "ml_chooser.h"
#include "game.h"

using namespace std;

namespace myrps
{
  MLChooser::MLChooser(Game current_game, int n)
  {
    if (n < 1)
      cout << "Invalid value of N! Please select value greater than 0." << endl;
    
    this->current_game = current_game;
    this->n = n;
    this->hist_data = MLChooser::GetHistData();
    this->old_hist_data = this->hist_data;
  }

  Move MLChooser::DecideMove()
  {
    Move winning_move;
    Move most_likely_move;
    
    Move computer_move = Move::kScissors;
    if (hist_data.empty())
    {
      computer_move =
          static_cast<Move>(rand() % static_cast<int>(Move::kScissors));
      return computer_move;
    }

    if (current_game.GetRoundCount() < n)
    {
      // default random algorithm
      computer_move =
          static_cast<Move>(rand() % static_cast<int>(Move::kScissors));
      
      last_n_minus_one_q.push(current_game.GetPlayerMove());
      last_n_minus_one_q.push(computer_move);

      return computer_move;
    }
    else
    {
      string last_n_minus_one_moves = 
        MLChooser::GetLastNMinusOneMoves(last_n_minus_one_q);
      most_likely_move = MLChooser::GetMostLikelyMove(last_n_minus_one_moves);
      winning_move = MLChooser::GetWinningMove(most_likely_move);
    }
    

    return winning_move;
  }

  unordered_map<string, int> MLChooser::GetHistData()
  {
    unordered_map<string, int> hist;

    if (MLChooser::MLDirectoryExists())
    {
      if (MLChooser::MLFileNExists())
      {
        cout << "File exists! Initializing frequency data..." << endl;
        hist = MLChooser::ReadHistData();
      }
      // else
      // {
      //   hist = GenerateHistData(); // from raw data
      // }
    }

    MLChooser::WriteHistData();

    return hist;
  }
  // Checks if directory for ML Data exists. If it doesn't exist, create a
  // directory for ML Data.
  bool MLChooser::MLDirectoryExists()
  {
    const char *ml_data_directory = "ml_data";

    struct stat info;
    if (stat(ml_data_directory, &info) != 0)
    {
      // can't access directory

      // attempt to create one
      if (mkdir(ml_data_directory, 0777) == -1)
      {
        cerr << "Can't access or create directory error: "
             << strerror(errno) << endl;
        return false;
      }
      else
      {
        cout << "Directory '" << ml_data_directory << "' created." << endl;
        return true;
      }
    }
    else
    {
      cout << "`ml_data` directory already exists" << endl;
    }

    return true;
  }

  // Checks if file for ML Data exists, for some given value of n. If it
  // doesn't exist, create a file for ML Data.
  bool MLChooser::MLFileNExists()
  {
    string file_name = "ml_data/ml_data_" + to_string(n);
    struct stat buffer;

    return stat(file_name.c_str(), &buffer) == 0;
  }

  // Initializes histogram to previously saved frequency data.
  unordered_map<string, int> MLChooser::ReadHistData()
  {
    vector<string> raw_pairs = MLChooser::TokenizeHistData();
    unordered_map<string, int> parsed_hist = ParseHistData(raw_pairs);

    return parsed_hist;
  }

  // Get string representation of each formatted set of N games to frequency 
  // relationship.
  vector<string> MLChooser::TokenizeHistData()
  {
    string ml_file_name = "ml_data/ml_data_" + to_string(n);
    ifstream file(ml_file_name);

    vector<string> raw_pairs;
    string freq_token = "";

    while (getline(file, freq_token, ','))
      raw_pairs.push_back(freq_token);

    file.close();

    return raw_pairs;
  }

  // Parse formatted set of N games to frequency string into map format.
  unordered_map<string, int> MLChooser::ParseHistData(vector<string> raw_pairs)
  {
    unordered_map<string, int> hist;
    string prev_n_moves;
    int freq;
    char delimeter = ':';

    for (string &s : raw_pairs)
      {
        prev_n_moves = s.substr(0, s.find(delimeter));
        freq = stoi(s.substr(s.find(delimeter), s.size()));
        hist[prev_n_moves] = freq;
      }

    return hist;
  }

  // TODO(drofp): If data does not exist yet in frequency table form, frequency 
  // data is generated from raw data
  // unordered_map<string, int> MLChooser::GenerateHistData()
  // {
  // }

  void MLChooser::WriteHistData()
  {
    if (MLChooser::MLDirectoryExists())
    {
      if (MLChooser::MLFileNExists())
      {
        MLChooser::UpdateHistData();
      }
    }
  }

  void MLChooser::UpdateHistData()
  {
    string ml_file_name = "ml_data/ml_data_" + to_string(n);
    ofstream file;
    file.open(ml_file_name, ofstream::out | ofstream::trunc);

    int game_cnt = 0;
    for (pair<string, int> perm_to_freq : hist_data)
    {
      if (old_hist_data.find(perm_to_freq.first) == old_hist_data.end())
      {
        file << perm_to_freq.first << ':' << perm_to_freq.second;
      }
      else
      {
        file << perm_to_freq.first << ':'
             << old_hist_data[perm_to_freq.first] + perm_to_freq.second;
      }

      if (game_cnt < current_game.GetRoundsPerMatch())
        file << ',';
    }

    file.close();
  }

  Move MLChooser::GetWinningMove(Move most_likely_move)
  {
    Move winning_move = Move::kRock;

    if (most_likely_move == Move::kRock)
      winning_move = Move::kPaper;
    else if (most_likely_move == Move::kPaper)
      winning_move = Move::kScissors;
    else if (most_likely_move == Move::kScissors)
      winning_move = Move::kRock;
    else
      cout << "No winning move found! Using default rock" << endl;
    
    return winning_move;
  }

  Move MLChooser::GetMostLikelyMove(string last_n_minus_one_moves)
  {
    Move most_likely_move = Move::kRock;

    vector<pair<string, int>> possible_moves = 
      MLChooser::GetPossibleChoices(last_n_minus_one_moves);

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
      cout << "No valid most likely move. Defaulting to Rock" << endl;
    
    return most_likely_move;
  }

  // TODO(drofp): Enhance memory performance to use iterable container for 
  // queue instead of copying over the queue for the sake of iterating.
  string MLChooser::GetLastNMinusOneMoves(queue<Move> q)
  {
    string last_n_minus_one_moves = "";
    queue<Move> copied_q = q;
    Move current_move;

    while (!copied_q.empty())
    {
      current_move = copied_q.front();

      if (current_move == Move::kRock)
        last_n_minus_one_moves += 'r';
      else if (current_move == Move::kPaper)
        last_n_minus_one_moves += 'p';
      else if (current_move == Move::kScissors)
        last_n_minus_one_moves += 's';
      else
        cout << "Invalid move in queue!!!" << endl;
      
      copied_q.pop();
    }

    return last_n_minus_one_moves;
  }

  bool MLChooser::CompareMoveFreq(pair<string, int> &a,
    pair<string, int> &b)
    {

      return a.first > b.first;
    }

  // TODO: Replace with search algorithm for expandability. Maybe store hist as 
  // tree for improved search time.
  vector<pair<string, int>> 
  MLChooser::GetPossibleChoices(string last_n_minus_one_moves)
  {
    vector<pair<string, int>> possible_choices;

    string permutation;
    permutation = last_n_minus_one_moves + "r";
    MLChooser::InsertPossibleChoice(possible_choices, permutation);

    permutation = last_n_minus_one_moves + "p";
    MLChooser::InsertPossibleChoice(possible_choices, permutation);

    permutation = last_n_minus_one_moves + "s";
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
