#include "start_option.h"

using myrps::StartOption;

namespace myrps
{
wxString move_to_wxString(StartOption choice)
{
    switch (choice)
    {
        case StartOption::PLAY_GAME:     return "Play Game";
        case StartOption::OPTIONS:    return "Options";
        case StartOption::EXIT: return "Exit";
        default:       return "none";
    }
}
} // namespace myrps
