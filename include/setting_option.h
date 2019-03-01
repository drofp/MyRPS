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

    static const SettingOption settings_list[] = 
    {
        SettingOption::D_EASY, 
        SettingOption::D_MEDIUM, 
        SettingOption::D_HARD,
    };

    static const int num_settings = 3;
}

inline ostream& operator<< (ostream& ostr, const SettingOptions::SettingOption difficulty)
{
  switch (difficulty)
  {
  case SettingOptions::SettingOption::D_EASY:
    ostr << "Easy";
    break;
  case SettingOptions::SettingOption::D_MEDIUM:
    ostr << "Medium";
    break;
  case SettingOptions::SettingOption::D_HARD:
    ostr << "Hard";
    break;

  default:
    break;
  }

  return ostr;
}

#endif