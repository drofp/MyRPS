#ifndef MOVE_H
#define MOVE_H

#include <ostream>

using namespace std;

namespace myrps
{
enum class Move
{
  kRock,
  kPaper,
  kScissors,
};
} // namespace myrps

inline ostream& operator<< (ostream& out, const myrps::Move move)
{
  switch (move)
  {
  case myrps::Move::kRock:
    out << "Rock";
    break;
  case myrps::Move::kPaper:
    out << "Paper";
    break;
  case myrps::Move::kScissors:
    out << "Scissors";
    break;

  default:
    break;
  }

  return out;
} // namespace myrps

#endif
