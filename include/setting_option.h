#ifndef SETTING_OPTION_H
#define SETTING_OPTION_H

#include <ostream>

using namespace std;

// enum class SettingOption
// {
//   D_EASY,
//   D_MEDIUM,
//   D_HARD,
// };

namespace SettingOptions
{
    enum class SettingOption
    {
      D_EASY,
      D_MEDIUM,
      D_HARD,
      D_ERROR,
    };

    static const SettingOption options_list[] = 
    {
        SettingOption::D_EASY, 
        SettingOption::D_MEDIUM, 
        SettingOption::D_HARD,
    };

    static const int num_options = 3;
}

inline ostream& operator<< (ostream& ostr, const SettingOption difficulty)
{
  switch (difficulty)
  {
  case SettingOption::D_EASY:
    ostr << "Easy";
    break;
  case SettingOption::D_MEDIUM:
    ostr << "Medium";
    break;
  case SettingOption::D_HARD:
    ostr << "Hard";
    break;

  default:
    break;
  }

  return ostr;
}

#endif