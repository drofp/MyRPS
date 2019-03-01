#ifndef SETTING_OPTION_H
#define SETTING_OPTION_H

#include <ostream>

using namespace std;

namespace myrps
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
} // namespace myrps

inline ostream &operator<<(ostream &ostr, const myrps::SettingOption difficulty)
{
  switch (difficulty)
  {
  case myrps::SettingOption::D_EASY:
    ostr << "Easy";
    break;
  case myrps::SettingOption::D_MEDIUM:
    ostr << "Medium";
    break;
  case myrps::SettingOption::D_HARD:
    ostr << "Hard";
    break;

  default:
    break;
  }

  return ostr;
}

#endif