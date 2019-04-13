#include "setting_option.h"

using myrps::SettingOption;

namespace myrps
{
wxString move_to_wxString(SettingOption choice)
{
  switch (choice)
  {
    case SettingOption::kRandom:     return "Random";
    case SettingOption::kSmart:    return "Smart";
    default:       return "none";
  }
}
} // namespace myrps