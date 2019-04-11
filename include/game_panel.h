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

  void SetGame(Game* g);
  void SetComputerMode(SettingOption mode);

  void OnRock(wxCommandEvent& event);
  void OnPaper(wxCommandEvent& event);
  void OnScissors(wxCommandEvent& event);
private:
  Game* game;

  wxStaticText *button_chosen_text;

  wxStaticText *round_count_text;
  wxStaticText *computer_prediction_text;
  wxStaticText *computer_choice_text;
  wxStaticText *display_winner_text;
  wxStaticText *player_win_cnt_text;
  wxStaticText *comp_win_cnt_text;
  wxStaticText *tie_cnt_text;

  int round_count = 1;

  void init();
  void PlayGame();
  MoveChoice GetPlayerMove();
  MoveChoice GetComputerMove();

  void GenerateButtonPanel(wxPanel* button_panel);
  void GenerateChosenMovePanel(wxPanel* chosen_panel);
  void GenerateGameInfoPanel(wxPanel* game_info_panel);
  void AddSubPanelsToMainPanel(vector<wxPanel *> panels, wxSizer* sizer);

  void UpdateButtonMoveText(const MoveChoice move);
  void UpdateGameInfoText(const MoveChoice move);
};
} // namespace myrps

#endif

