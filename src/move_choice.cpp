#include "move_choice.h"

using myrps::MoveChoice;

namespace myrps
{
wxString move_to_wxString(MoveChoice move)
{
    switch (move)
    {
        case MoveChoice::kRock:     return "Rock";
        case MoveChoice::kPaper:    return "Paper";
        case MoveChoice::kScissors: return "Scissors";
        default:       return "none";
    }
}
} // namespace myrps

