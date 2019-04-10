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

  void OnRock(wxCommandEvent& event);
  void OnPaper(wxCommandEvent& event);
  void OnScissors(wxCommandEvent& event);
private:
  wxStaticText *button_chosen_text;

  wxStaticText *round_count_text;
  wxStaticText *computer_prediction_text;
  wxStaticText *computer_choice_text;
  wxStaticText *display_winner_text;
  wxStaticText *game_spec_text;

  int cnt = 1;

  void init();
  void GenerateButtonPanel(wxPanel* button_panel);
  void GenerateChosenMovePanel(wxPanel* chosen_panel);
  void GenerateGameInfoPanel(wxPanel* game_info_panel);
  void AddSubPanelsToMainPanel(vector<wxPanel *> panels, wxSizer* sizer);

  void UpdateButtonMoveText(const MoveChoice move);
  void UpdateGameInfoText(const int round_count);
};
} // namespace myrps

#endif

