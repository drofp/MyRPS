#ifndef SETTING_OPTION_H
#define SETTING_OPTION_H

#include <ostream>

using namespace std;

namespace myrps
{
enum class SettingOption
{
  kRandom,
  kSmart,
  kError,
};

static const SettingOption settings_list[] =
    {
        SettingOption::kRandom,
        SettingOption::kSmart,
    };

static const int num_settings = 3;
} // namespace myrps

inline ostream &operator<<(ostream &ostr, const myrps::SettingOption difficulty)
{
  switch (difficulty)
  {
  case myrps::SettingOption::kRandom:
    ostr << "Random";
    break;
  case myrps::SettingOption::kSmart:
    ostr << "Smart";
    break;

  default:
    break;
  }

  return ostr;
}

#endif