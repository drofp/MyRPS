#ifndef GAME_PANEL_H
#define GAME_PANEL_H

#include "my_rps.h"
#include "move_choice.h"
#include "start_option.h"
#include "setting_option.h"
#include "game.h"
#include <wx/numdlg.h> 

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

  ///// Start Menu Section /////
  void OnPlayGame(wxCommandEvent& event);
  void OnOptions(wxCommandEvent& event);

  ///// Options Menu Section /////
  void OnRandom(wxCommandEvent& event);
  void OnSmart(wxCommandEvent& event);
  void OnRoundSet(wxCommandEvent& event);

  ///// Game Section /////
  void SetGame(Game* g);
  void SetComputerMode(SettingOption mode);

  void OnRock(wxCommandEvent& event);
  void OnPaper(wxCommandEvent& event);
  void OnScissors(wxCommandEvent& event);
private:
  Game* game;

  long num_rounds;
  SettingOption current_difficulty;

  wxStaticText *button_chosen_text;

  wxStaticText *round_count_text;
  wxStaticText *computer_prediction_text;
  wxStaticText *computer_choice_text;
  wxStaticText *display_winner_text;
  wxStaticText *player_win_cnt_text;
  wxStaticText *comp_win_cnt_text;
  wxStaticText *tie_cnt_text;

  //Panels

  wxPanel *start_menu_panel;
  wxPanel *options_panel;
  wxPanel *game_buttons_panel;
  wxPanel *game_info_panel;

  int round_count = 1;

  void init();
  void PlayGame();
  void ResetGame();

  MoveChoice GetPlayerMove();
  MoveChoice GetComputerMove();

  void GenerateStartMenuPanel();
  void GenerateOptionsPanel();
  void GenerateGameButtonPanel();

  // void GenerateButtonPanel(wxPanel* button_panel);
  void GenerateGameInfoPanel();
  void AddSubPanelsToMainPanel(vector<wxPanel *> panels, wxSizer* sizer);

  void SelectPlayGameButton(const StartOption option);
  void SelectOptionsButton(const StartOption option);
  void UpdateButtonMoveText(const MoveChoice move);
  void UpdateGameInfoText(const MoveChoice move);

  void SetStartMenuVisibility(bool is_shown);
  void SetOptionsVisibility(bool is_shown);
  void SetGameVisibility(bool is_shown);
  
  void FinishGame();
};
} // namespace myrps

#endif

