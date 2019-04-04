#include "move.h"

using myrps::Move;

namespace myrps
{
wxString move_to_wxString(Move move)
{
    switch (move)
    {
        case Move::kRock:     return "Rock";
        case Move::kPaper:    return "Paper";
        case Move::kScissors: return "Scissors";
        default:       return "none";
    }
}
} // namespace myrps

