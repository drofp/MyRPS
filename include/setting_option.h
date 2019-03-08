#ifndef SETTING_OPTION_H
#define SETTING_OPTION_H

#include <ostream>

using namespace std;

namespace myrps
{
enum class SettingOption
{
  D_RANDOM,
  D_SMART,
  D_GENIUS,
  D_ERROR,
};

static const SettingOption settings_list[] =
    {
        SettingOption::D_RANDOM,
        SettingOption::D_SMART,
        SettingOption::D_GENIUS,
    };

static const int num_settings = 3;
} // namespace myrps

inline ostream &operator<<(ostream &ostr, const myrps::SettingOption difficulty)
{
  switch (difficulty)
  {
  case myrps::SettingOption::D_RANDOM:
    ostr << "Random";
    break;
  case myrps::SettingOption::D_SMART:
    ostr << "Smart";
    break;
  case myrps::SettingOption::D_GENIUS:
    ostr << "Genius";
    break;

  default:
    break;
  }

  return ostr;
}

#endif