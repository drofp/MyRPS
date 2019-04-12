#include <iostream>

// #include "game.h"
// #include "start_menu.h"
// #include "settings_menu.h"
// #include "ml_chooser.h"

#include "game_frame.h"
#include "my_rps.h"

using namespace std;
using myrps::MyRps;

wxIMPLEMENT_APP(MyRps);

namespace myrps
{
bool MyRps::OnInit()
{
    if (!wxApp::OnInit()) return false;

    GameFrame *gframe = new GameFrame("what");
    gframe->Show(true);

    return true;
}
} // namespace myrps
