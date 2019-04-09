#ifndef GAME_PANEL_H
#define GAME_PANEL_H

#include "my_rps.h"
#include "move_choice.h"
#include "game.h"

#include <string>

namespace myrps
{
class GamePanel : public wxPanel
{
public:
  GamePanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
  {
    init();
  }

  void on_rock(wxCommandEvent& event);
  void on_paper(wxCommandEvent& event);
  void on_scissors(wxCommandEvent& event);
private:
  wxStaticText *button_chosen_text;
  wxStaticText *round_count_text;
  int cnt = 1;

  void init();
  void update_button_move_text(const MoveChoice move);
  void update_round_count_text(const int round_count);
};
} // namespace myrps

#endif

