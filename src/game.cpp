#include <iostream>

#include "game.h"
#include "computer_player.h"
#include <boost/algorithm/string.hpp>

using namespace std;

namespace myrps
{
void Game::PlayMatch()
{
  for (int i = 0; i < rounds_per_match; i++)
  {
    Move player_move = Game::GetPlayerMove();
    Move computer_move = Game::GetComputerMove();

    Game::PlayRound(player_move, computer_move);
  }

  Game::PrintScore();

  cout << "Thanks for playing MyRPS!!!" << endl;
}

void Game::PlayRound(Move player_move, Move computer_move)
{
  cout << "Player chose: " << player_move << endl;
  cout << "Computer chose: " << computer_move << endl;

  if (player_move == Move::kRock)
  {
    if (computer_move == Move::kScissors)
    {
      cout << "Player wins!" << endl;
      player_score++;
    }
    else if (computer_move == Move::kPaper)
    {
      cout << "Player loses..." << endl;
      computer_score++;
    }
    else
    {
      cout << "Tie game!!!" << endl;
      tie_game_cnt++;
    }
  }
  else if (player_move == Move::kPaper)
  {
    if (computer_move == Move::kRock)
    {
      cout << "Player wins!" << endl;
      player_score++;
    }
    else if (computer_move == Move::kScissors)
    {
      cout << "Player loses..." << endl;
      computer_score++;
    }
    else
    {
      cout << "Tie game!!!" << endl;
      tie_game_cnt++;
    }
  }
  else if (player_move == Move::kScissors)
  {
    if (computer_move == Move::kPaper)
    {
      cout << "Player wins!" << endl;
      player_score++;
    }
    else if (computer_move == Move::kRock)
    {
      cout << "Player loses..." << endl;
      computer_score++;
    }
    else
    {
      cout << "Tie game!!!" << endl;
      tie_game_cnt++;
    }
  }

  cout << endl;
  round_count++;
}

Move Game::GetPlayerMove()
{
  Move player_move;

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

    // TODO: clean up print to be consistent and cleaner
    // maybe have helper function for this
    cout << "You picked: " << user_input << endl;

    if (!IsValidMove(user_input))
      cout << "Please enter a valid hand\n" << endl;
    else
    {
      if (user_input == "rock" || strcmp(user_input.c_str(), "r") == 0)
        player_move = Move::kRock;
      else if (user_input == "paper" || strcmp(user_input.c_str(), "p") == 0)
        player_move = Move::kPaper;
      else if (user_input == "scissors" || strcmp(user_input.c_str(), "s") == 0)
        player_move = Move::kScissors;

      still_playing = false;
    }
  }

  return player_move;
}

Move Game::GetComputerMove()
{
  Move computer_move = ai.DecideMove();
  return computer_move;
}

// TODO: Reverse logic to defensive programming (return false first)
bool Game::IsValidMove(string user_move)
{
  if (boost::iequals(user_move, "rock") 
  || boost::iequals(user_move, "paper")
  || boost::iequals(user_move, "scissors")
  || boost::iequals(user_move, "r")
  || boost::iequals(user_move, "p")
  || boost::iequals(user_move, "s"))
    return true;

  return false;
}

void Game::PrintScore()
{
  cout << "===== MATCH FINAL RESULTS =====" << endl;
  cout << "Player Score: " << player_score << endl;
  cout << "Computer Score: " << computer_score << endl;
  cout << "Tie Game Count: " << tie_game_cnt << endl;
}

} // namespace myrps
