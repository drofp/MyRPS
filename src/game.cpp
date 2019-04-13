#include "game.h"

using namespace std;

namespace myrps
{
Game::Game()
{
  this->ai = ComputerPlayer(SettingOption::kRandom, rounds_per_match);
}

Game::Game(SettingOption computer_mode)
{
  this->ai = ComputerPlayer(computer_mode, rounds_per_match);
}

void Game::PlayMatch()
{
  cout << "Get ready for a match of " << rounds_per_match << " games! " << endl;
  for (int i = 0; i < rounds_per_match; i++)
  {
    MoveChoice player_move = Game::GetPlayerMove();
    MoveChoice computer_move = Game::GetComputerMove(player_move);

    Game::DisplayRound(player_move, computer_move);
  }

  Game::PrintScore();

  cout << "Thanks for playing MyRPS!!!" << endl;
}

void Game::DisplayRound(MoveChoice player_move, MoveChoice computer_move)
{
  string win_result = PlayRound(player_move, computer_move);
  cout << win_result << endl;
  cout << endl;
}

string Game::PlayRound(MoveChoice player_move, MoveChoice computer_move)
{
  cout << "Results of round " << round_count << ':' << endl;
  cout << "Player chose: " << player_move << endl;
  cout << "Computer chose: " << computer_move << endl;

  round_count++;

  if (player_move == MoveChoice::kRock)
  {
    if (computer_move == MoveChoice::kScissors)
    {
      player_score++;
      return "Player wins!";
    }
    else if (computer_move == MoveChoice::kPaper)
    {
      computer_score++;
      return "Player loses...";
    }
    else
    {
      tie_game_cnt++;
      return "Tie game!!!";
    }
  }
  else if (player_move == MoveChoice::kPaper)
  {
    if (computer_move == MoveChoice::kRock)
    {
      player_score++;
      return "Player wins!";
    }
    else if (computer_move == MoveChoice::kScissors)
    {
      computer_score++;
      return "Player loses...";
    }
    else
    {
      tie_game_cnt++;
      return "Tie game!!!";
    }
  }
  else if (player_move == MoveChoice::kScissors)
  {
    if (computer_move == MoveChoice::kPaper)
    {
      player_score++;
      return "Player wins!";
    }
    else if (computer_move == MoveChoice::kRock)
    {
      computer_score++;
      return "Player loses...";
    }
    else
    {
      tie_game_cnt++;
      return "Tie game!!!";
    }
  }
}

MoveChoice Game::GetPlayerMove()
{
  MoveChoice player_move;

  bool still_playing = true;
  string user_input;

  while (still_playing)
  {
    cout << "Select either 'Rock' (r),"
            "'Paper' (p),"
            "or 'Scissors'(s)"
         << endl;
    cin >> user_input;

    // for UTF-8 support
    boost::algorithm::to_lower(user_input);

    cout << "You picked: " << user_input << endl;

    if (!IsValidMove(user_input))
      cout << "Please enter a valid hand\n" << endl;
    else
    {
      if (user_input == "rock" || strcmp(user_input.c_str(), "r") == 0)
        player_move = MoveChoice::kRock;
      else if (user_input == "paper" || strcmp(user_input.c_str(), "p") == 0)
        player_move = MoveChoice::kPaper;
      else if (user_input == "scissors" || strcmp(user_input.c_str(), "s") == 0)
        player_move = MoveChoice::kScissors;

      still_playing = false;
    }
  }

  return player_move;
}

MoveChoice Game::GetComputerMove(MoveChoice player_move)
{
  MoveChoice computer_move = ai.DecideMove(player_move);
  return computer_move;
}

int Game::GetPlayerScore()    {return player_score;}
int Game::GetComputerScore()   {return computer_score;}
int Game::GetTieGameCnt()     {return tie_game_cnt;}
int Game::GetRoundCount()     {return round_count;}
int Game::GetRoundsPerMatch() {return Game::rounds_per_match;}

MoveChoice Game::GetComputerPrediction(const MoveChoice player_move)
{
  return ai.GetPredictedMove(player_move);
}

void Game::SetComputerMode(SettingOption mode)
{
  ai.SetComputerMode(mode);
}

void Game::SetRoundsPerMatch(int rounds_per_match)
{
  this->rounds_per_match = rounds_per_match;
  ai.SetRoundsPerMatch(rounds_per_match);
}

bool Game::IsValidMove(string user_move)
{
  if (!(boost::iequals(user_move, "rock") 
  || boost::iequals(user_move, "paper")
  || boost::iequals(user_move, "scissors")
  || boost::iequals(user_move, "r")
  || boost::iequals(user_move, "p")
  || boost::iequals(user_move, "s")))
    return false;

  return true;
}

void Game::PrintScore()
{
  cout << "===== MATCH FINAL RESULTS =====" << endl;
  cout << "Player Score: " << player_score << endl;
  cout << "Computer Score: " << computer_score << endl;
  cout << "Tie Game Count: " << tie_game_cnt << endl;
}

} // namespace myrps
