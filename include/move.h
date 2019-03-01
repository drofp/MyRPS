#ifndef MOVE_H
#define MOVE_H

#include <ostream>

using namespace std;

enum class Move
{
  kRock,
  kPaper,
  kScissors,
};

inline ostream& operator<< (ostream& out, const Move move)
{
  switch (move)
  {
  case Move::kRock:
    out << "Rock";
    break;
  case Move::kPaper:
    out << "Paper";
    break;
  case Move::kScissors:
    out << "Scissors";
    break;

  default:
    break;
  }

  return out;
} // namespace myrps

#endif
