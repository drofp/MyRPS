#include <iostream>

// #include "game.h"
// #include "start_menu.h"
// #include "settings_menu.h"
// #include "ml_chooser.h"

#include "my_rps.h"
#include "start_menu_frame.h"

using namespace std;
using myrps::MyRps;

wxIMPLEMENT_APP(MyRps);

namespace myrps
{
bool MyRps::OnInit()
{
    if (!wxApp::OnInit()) return false;

    StartMenuFrame *frame = new StartMenuFrame("Rps Demo");
    frame->Show(true);

    return true;
}
} // namespace myrps

// int main()
// {
//   myrps::StartMenu start;
//   start.DisplayOptions();

//   // myrps::MLChooser ml_chooser;
//   // unordered_map<string, int> test_map = ml_chooser.GetHistData();


//   return 0;
// }


