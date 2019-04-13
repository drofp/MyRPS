#include <iostream>

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

    GameFrame *gframe = new GameFrame("MyRPS");
    gframe->Show(true);

    return true;
}
} // namespace myrps
