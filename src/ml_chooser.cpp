#include "ml_chooser.h"

namespace myrps
{
  MLChooser::MLChooser(int rounds_per_match)
  {
    this->n = 5; // default value. must be greater than 1
    this->rounds_per_match = rounds_per_match;
    this->hist_data = MLChooser::GetHistData();
    this->old_hist_data = this->hist_data;
  }

  Move MLChooser::DecideMove(Move player_move)
  {
    Move winning_move = Move::kScissors;
    Move most_likely_move;

    if (round_count < n / 2)
    {
      // default random algorithm
      cout << "defaulting to random algo" << endl;
      winning_move =
          static_cast<Move>(rand() % static_cast<int>(Move::kScissors));
    }
    else
    {
      cout << "using smart algo" << endl;
      string last_n_minus_one_moves = 
        MLChooser::GetLastNMinusOneMoves(last_n_minus_one_q);
      
      MLChooser::AddLastNMovesToHist(last_n_minus_one_moves, player_move);

      most_likely_move = MLChooser::GetMostLikelyMove(last_n_minus_one_moves);
      winning_move = MLChooser::GetWinningMove(most_likely_move);
    }
    
    last_n_minus_one_q.push(player_move);
    last_n_minus_one_q.push(winning_move);

    round_count++;
    cout << "rounds_per_match is: " << rounds_per_match << endl;
    if (round_count == rounds_per_match)
      MLChooser::WriteHistData();
    
    return winning_move;
  }

  void MLChooser::AddLastNMovesToHist(
    string last_n_minus_one_moves,
    Move curr_move)
    {
      string last_n_moves = "";

      if (curr_move == Move::kRock)
        last_n_moves = last_n_minus_one_moves + 'r';
      else if (curr_move == Move::kPaper)
        last_n_moves = last_n_minus_one_moves + 'p';
      else if (curr_move == Move::kScissors)
        last_n_moves = last_n_minus_one_moves + 's';
      else
        cout << "Invalid move" << endl;
      
      if (hist_data.find(last_n_moves) == hist_data.end())
      {
        hist_data.insert(make_pair(last_n_moves, 1));
      }
      else
      {
        hist_data[last_n_moves]++;
      }
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
    cout << "starting tokenizer..." << endl;
    string ml_file_name = "ml_data/ml_data_" + to_string(n);
    ifstream file(ml_file_name);

    cout << "successfully opened file!" << endl;

    vector<string> raw_pairs;
    string freq_token = "";

    while (getline(file, freq_token, ','))
    {
      cout << "getting pair: " << freq_token << endl;
      raw_pairs.push_back(freq_token);
    }

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

    string freq_str;
    for (string &s : raw_pairs)
      {
        cout << "parsing: " << s << endl; 
        prev_n_moves = s.substr(0, s.find(delimeter));
        cout << "prev_n_moves: " << prev_n_moves << endl;
        
        freq_str = s.substr(s.find(delimeter)+1, s.size());
        cout << "freq_str: " << freq_str << endl;
        freq = stoi(freq_str);

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
        cout << "ML File Exists!" << endl;
        MLChooser::UpdateHistData();
      }
      else
      {
        cout << "ML File doesn't exist yet. Writing to new file" << endl;
        MLChooser::UpdateHistData();
      }
    }
  }

  // writes frequency data to a file to be read for next match
  void MLChooser::UpdateHistData()
  {
    string ml_file_name = "ml_data/ml_data_" + to_string(n);
    cout << "Writing frequency data to file: " << ml_file_name << endl;

    ofstream file;

    // clear file first before overwritting
    file.open(ml_file_name, ofstream::out | ofstream::trunc);

    int token_cnt = 1;
    cout << "==========sizeof hist_data: " << hist_data.size() << endl;
    for (pair<string, int> perm_to_freq : hist_data)
    {
      cout << "===============writing to file! " << endl;
      if (old_hist_data.find(perm_to_freq.first) == old_hist_data.end())
      {
        file << perm_to_freq.first << ':' << perm_to_freq.second;
      }
      else
      {
        // OLD: adding onto old hist data
        // file << perm_to_freq.first << ':'
        //      << old_hist_data[perm_to_freq.first] + perm_to_freq.second;
        file << perm_to_freq.first << ':'
             << perm_to_freq.second;
      }

      if (token_cnt < hist_data.size())
        file << ',';
      token_cnt++;
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
    
    cout << "MOST LIKELY: " << most_likely_move << endl;
    cout << "WINNING MOVE: " << winning_move << endl;
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
    int amount_to_copy = n;
    Move current_move;

    while (amount_to_copy > 0)
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
      
      amount_to_copy--;
      copied_q.pop();
    }

    q.pop();
    q.pop();

    return last_n_minus_one_moves;
  }

  bool MLChooser::CompareMoveFreq(pair<string, int> &a,
    pair<string, int> &b)
    {

      return a.second > b.second;
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

  void MLChooser::PrintHistData()
  {
    cout << "hist_data:";
    for (pair<string, int> perm_to_freq : hist_data)
    {
      cout << " " << perm_to_freq.first << ":" << perm_to_freq.second << ",";
    }
    cout << endl;
  }
}
