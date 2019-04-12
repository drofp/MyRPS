#ifndef SETTINGOPTION_PANEL_H
#define SETTINGOPTION_PANEL_H

#include "my_rps.h"
#include "setting_option.h"

namespace myrps
{
class SettingOptionPanel : public wxPanel
{
public:
  SettingOptionPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
  {
    init();
  }

//   void on_play_game(wxCommandEvent& event);
//   void on_options(wxCommandEvent& event);
//   void on_exit(wxCommandEvent& event);
  void on_random_setting(wxCommandEvent& event);
  void on_smart_setting(wxCommandEvent& event);

private:
  wxStaticText *button_chosen_text;

  void init();
//   void update_button_move_text(const StartOption choice);
  void update_button_move_text(const SettingOption choice);
};
} // namespace myrps

#endif

