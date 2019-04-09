#ifndef MOVE_CHOICE_H
#define MOVE_CHOICE_H

#include "wx/wx.h"

#include <ostream>

using namespace std;

namespace myrps
{
enum class MoveChoice
{
  kRock,
  kPaper,
  kScissors,
};

wxString move_to_wxString(MoveChoice move);
} // namespace myrps

inline ostream& operator<< (ostream& out, const myrps::MoveChoice move)
{
  switch (move)
  {
  case myrps::MoveChoice::kRock:
    out << "Rock";
    break;
  case myrps::MoveChoice::kPaper:
    out << "Paper";
    break;
  case myrps::MoveChoice::kScissors:
    out << "Scissors";
    break;

  default:
    break;
  }

  return out;
}

#endif
