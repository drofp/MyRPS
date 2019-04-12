#ifndef START_MENU_PANEL_H
#define START_MENU_PANEL_H

#include "my_rps.h"
#include "start_option.h"

namespace myrps
{
class StartMenuPanel : public wxPanel
{
public:
  StartMenuPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
  {
    init();
  }

  void on_play_game(wxCommandEvent& event);
  void on_options(wxCommandEvent& event);
  void on_exit(wxCommandEvent& event);

private:
  wxStaticText *button_chosen_text;

  void init();
  void update_button_move_text(const StartOption choice);
};
} // namespace myrps

#endif

