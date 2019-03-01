#ifndef START_OPTION_H_
#define START_OPTION_H_

#include <ostream>

using namespace std;

namespace StartOptions
{
enum class StartOption
{
  PLAY_GAME,
  OPTIONS,
  EXIT,
  ERROR,
};

static const StartOption options_list[] =
    {
        StartOption::PLAY_GAME,
        StartOption::OPTIONS,
        StartOption::EXIT,
};

static const int num_options = 3;
} // namespace StartOptions

inline ostream &operator<<(ostream &ostr, const StartOptions::StartOption option)
{
  switch (option)
  {
  case StartOptions::StartOption::PLAY_GAME:
    ostr << "Play Game";
    break;

  case StartOptions::StartOption::OPTIONS:
    ostr << "Options";
    break;
  case StartOptions::StartOption::EXIT:
    ostr << "Exit";
    break;
  default:
    ostr << "what?";
    break;
  }
  return ostr;
}

#endif
