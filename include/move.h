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

// TODO: Add support for converting between enum class and strings
// https://github.com/aantron/better-enums
// https://sheep.horse/2018/5/converting_enum_classes_to_strings_and_back_in_c%2B%2B.html
// https://stackoverflow.com/questions/28828957/enum-to-string-in-modern-c11-c14-c17-and-future-c20
// ostream & operator << (ostream &out, const Move &value)
// {
//   switch (value)
//   {
//   case Move::kRock:
//     out << "Rock";
//     break;
//   case Move::kPaper:
//     out << "Paper";
//     break;
//   case Move::kScissors:
//     out << "Scissors";
//     break;

//   default:
//     break;
//   }

//   return out;
// }

#endif
