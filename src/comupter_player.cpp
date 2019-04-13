#include "computer_player.h"

namespace myrps
{
ComputerPlayer::ComputerPlayer()
{
}

ComputerPlayer::ComputerPlayer(SettingOption mode, int rounds_per_match)
{
  this->rounds_per_match = rounds_per_match;
  this->chooser = ChooserFactory::MakeChooser(mode, rounds_per_match);
}

void ComputerPlayer::SetRoundsPerMatch(int rounds_per_match)
{
  this->rounds_per_match = rounds_per_match;
  chooser->SetRoundsPerMatch(rounds_per_match);
}

MoveChoice ComputerPlayer::DecideMove(MoveChoice player_move)
{
  MoveChoice computer_move = chooser->DecideMove(player_move);
  return computer_move;
}

void ComputerPlayer::SetComputerMode(SettingOption mode)
{
  chooser = ChooserFactory::MakeChooser(mode, rounds_per_match);
}

MoveChoice ComputerPlayer::GetPredictedMove(MoveChoice player_move)
{
  return chooser->GetPredictedMove(player_move);
}
} // namespace myrps
