#include <iostream>

#include "game.h"
#include "start_menu.h"
#include "settings_menu.h"
#include "ml_chooser.h"

#include "my_rps.h"

using namespace std;

wxIMPLEMENT_APP(ButtonDemo);

bool ButtonDemo::OnInit()
{
    if (!wxApp::OnInit()) return false;

    DemoFrame *frame = new DemoFrame("Button Demo");
    frame->Show(true);

    return true;
}

// int main()
// {
//   myrps::StartMenu start;
//   start.DisplayOptions();

//   // myrps::MLChooser ml_chooser;
//   // unordered_map<string, int> test_map = ml_chooser.GetHistData();


//   return 0;
// }


