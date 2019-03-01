#ifndef SETTINGS_MENU_H_
#define SETTINGS_MENU_H_

#include <vector>

#include "setting_option.h"

using namespace std;
using namespace SettingOptions;

namespace myrps
{
    class SettingsMenu
    {
    public:
        SettingsMenu();
        SettingOption displaySettings();
        
    private:
        vector<SettingOption> settings;
        SettingOption GetUserChoice();
        SettingOption ValidateSetting(string val);
    };
}
#endif
