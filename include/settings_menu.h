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
        void displaySettings();
        void selectSetting();

    private:
        vector<SettingOption> settings;
        // SettingOption GetSetting();
        // SettingOption ValidateSetting(string val);
    };
}
#endif