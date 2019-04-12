#include "game_panel.h"

using myrps::GamePanel;

namespace myrps
{
void GamePanel::init()
{
  // main sizer
  wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

  // buttons panel
  wxPanel *button_panel = new wxPanel(this, wxID_ANY);
  GenerateButtonPanel(button_panel);

  // chosen move panel
  wxPanel *chosen_panel = new wxPanel(this, wxID_ANY);
  GenerateChosenMovePanel(chosen_panel);

  // game info panel
  wxPanel *game_info_panel = new wxPanel(this, wxID_ANY);
  GenerateGameInfoPanel(game_info_panel);

  vector<wxPanel *> panels;
  panels.push_back(button_panel);
  panels.push_back(chosen_panel);
  panels.push_back(game_info_panel);

  AddSubPanelsToMainPanel(panels, sizer);

  SetSizer(sizer);
}

void GamePanel::SetGame(Game* g)
{
  game = g;
}

void GamePanel::SetComputerMode(SettingOption mode)
{
  game->SetComputerMode(mode);
}

void GamePanel::GenerateButtonPanel(wxPanel* button_panel)
{
  wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);

  ///// Start Menu Section /////

  ///// Options Menu Section /////

  ///// Game Section /////
  wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
                                               "Choose:");
  wxButton *rock_button = new wxButton(button_panel, wxID_ANY,
                                       move_to_wxString(MoveChoice::kRock));
  wxButton *paper_button = new wxButton(button_panel, wxID_ANY,
                                        move_to_wxString(MoveChoice::kPaper));
  wxButton *scissors_button = new wxButton(button_panel, wxID_ANY,
                                           move_to_wxString(MoveChoice::kScissors));

  rock_button->Bind(wxEVT_BUTTON, &GamePanel::OnRock, this);
  paper_button->Bind(wxEVT_BUTTON, &GamePanel::OnPaper, this);
  scissors_button->Bind(wxEVT_BUTTON, &GamePanel::OnScissors, this);

  button_sizer->Add(choose_text, 0, 0, 0);
  button_sizer->AddSpacer(5);
  button_sizer->Add(rock_button, 0, 0, 0);
  button_sizer->AddSpacer(5);
  button_sizer->Add(paper_button, 0, 0, 0);
  button_sizer->AddSpacer(5);
  button_sizer->Add(scissors_button, 0, 0, 0);

  button_panel->SetSizer(button_sizer);
}

void GamePanel::GenerateChosenMovePanel(wxPanel* chosen_panel)
{
  wxSizer *chosen_sizer = new wxGridSizer(2, 0, 5);

  wxStaticText *chosen_move_text = new wxStaticText(chosen_panel, wxID_ANY,
                                               "Player's move:");
  button_chosen_text = new wxStaticText(chosen_panel, wxID_ANY, "");
  button_chosen_text->SetFont(button_chosen_text->GetFont().Larger());

  chosen_sizer->Add(chosen_move_text, 0, wxALIGN_RIGHT, 0);
  chosen_sizer->Add(button_chosen_text, 0, 0, 0);

  chosen_panel->SetSizer(chosen_sizer);
}

void GamePanel::GenerateGameInfoPanel(wxPanel* game_info_panel)
{
  wxSizer *game_info_sizer = new wxGridSizer(3, 1, 4);

  wxStaticText *current_round_label_text 
                  = new wxStaticText(game_info_panel, wxID_ANY,
                                    "Current round:");
  round_count_text = new wxStaticText(game_info_panel, wxID_ANY, "");
  round_count_text->SetFont(
                          round_count_text->GetFont().Larger());

  wxStaticText *computer_prediction_label_text 
                  = new wxStaticText(game_info_panel, wxID_ANY,
                                    "Computer's prediction:");
  computer_prediction_text = new wxStaticText(game_info_panel, wxID_ANY, "");
  computer_prediction_text->SetFont(
                          computer_prediction_text->GetFont().Larger());

  wxStaticText *computer_choice_label_text 
                  = new wxStaticText(game_info_panel, wxID_ANY,
                                    "Computer's choice:");
  computer_choice_text = new wxStaticText(game_info_panel, wxID_ANY, "");
  computer_choice_text->SetFont(
                          computer_choice_text->GetFont().Larger());

  wxStaticText *display_winner_label_text 
                  = new wxStaticText(game_info_panel, wxID_ANY,
                                    "Round winner:");
  display_winner_text = new wxStaticText(game_info_panel, wxID_ANY, "");
  display_winner_text->SetFont(
                          computer_choice_text->GetFont().Larger());

  wxStaticText *player_win_cnt_label_text
                  = new wxStaticText(game_info_panel, wxID_ANY,
                                    "Player wins:");
  player_win_cnt_text = new wxStaticText(game_info_panel, wxID_ANY, "");
  player_win_cnt_text->SetFont(
                          computer_choice_text->GetFont().Larger());

  wxStaticText *comp_win_cnt_label_text
                  = new wxStaticText(game_info_panel, wxID_ANY,
                                    "Computer wins:");
  comp_win_cnt_text = new wxStaticText(game_info_panel, wxID_ANY, "");
  comp_win_cnt_text->SetFont(
                          computer_choice_text->GetFont().Larger());

  wxStaticText *tie_cnt_label_text
                  = new wxStaticText(game_info_panel, wxID_ANY,
                                    "Tie games:");
  tie_cnt_text = new wxStaticText(game_info_panel, wxID_ANY, "");
  tie_cnt_text->SetFont(
                          computer_choice_text->GetFont().Larger());

  game_info_sizer->Add(current_round_label_text, 0, wxALIGN_RIGHT, 0);
  game_info_sizer->Add(round_count_text, 0, 0, 0);
  game_info_sizer->AddSpacer(20);
  game_info_sizer->Add(computer_prediction_label_text, 0, wxALIGN_RIGHT, 0);
  game_info_sizer->Add(computer_prediction_text, 0, 0, 0);
  game_info_sizer->AddSpacer(20);
  game_info_sizer->Add(computer_choice_label_text, 0, wxALIGN_RIGHT, 0);
  game_info_sizer->Add(computer_choice_text, 0, 0, 0);
  game_info_sizer->AddSpacer(20);
  game_info_sizer->Add(display_winner_label_text, 0, wxALIGN_RIGHT, 0);
  game_info_sizer->Add(display_winner_text, 0, 0, 0);
  game_info_sizer->AddSpacer(20);
  game_info_sizer->Add(player_win_cnt_label_text, 0, wxALIGN_RIGHT, 0);
  game_info_sizer->Add(player_win_cnt_text, 0, 0, 0);
  game_info_sizer->AddSpacer(20);
  game_info_sizer->Add(comp_win_cnt_label_text, 0, wxALIGN_RIGHT, 0);
  game_info_sizer->Add(comp_win_cnt_text, 0, 0, 0);
  game_info_sizer->AddSpacer(20);
  game_info_sizer->Add(tie_cnt_label_text, 0, wxALIGN_RIGHT, 0);
  game_info_sizer->Add(tie_cnt_text, 0, 0, 0);
  game_info_sizer->AddSpacer(20);

  game_info_panel->SetSizer(game_info_sizer);
}

void GamePanel::AddSubPanelsToMainPanel(vector<wxPanel *> panels, 
                                        wxSizer* sizer)
{
  for (wxPanel* panel : panels)
  {
    sizer->Add(panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
  }
}

void GamePanel::OnRock(wxCommandEvent &event)
{
  UpdateButtonMoveText(MoveChoice::kRock);
  UpdateGameInfoText(MoveChoice::kRock);
}

void GamePanel::OnPaper(wxCommandEvent &event)
{
  UpdateButtonMoveText(MoveChoice::kPaper);
  UpdateGameInfoText(MoveChoice::kPaper);
}

void GamePanel::OnScissors(wxCommandEvent &event)
{
  UpdateButtonMoveText(MoveChoice::kScissors);
  UpdateGameInfoText(MoveChoice::kScissors);
}

void GamePanel::UpdateButtonMoveText(const MoveChoice move)
{
  button_chosen_text->SetLabelText(move_to_wxString(move));
}

// Plays game and updates text appropriately
// 
// NOTE: Should check if round_count has reached max number of rounds at end of 
// this function. Feel free to use the FinishGame() method to encapsulate all 
// necessary cleanup and control passing code.
void GamePanel::UpdateGameInfoText(const MoveChoice player_move)
{
  MoveChoice computer_move = game->GetComputerMove(player_move);
  MoveChoice computer_prediction = game->GetComputerPrediction(player_move);

  round_count_text->SetLabelText(std::to_string(game->GetRoundCount()));
  computer_prediction_text->SetLabelText(move_to_wxString(computer_prediction));
  computer_choice_text->SetLabelText(move_to_wxString(computer_move));
  display_winner_text->SetLabelText(game->PlayRound(player_move, computer_move));
  player_win_cnt_text->SetLabelText(std::to_string(game->GetPlayerScore()));
  comp_win_cnt_text->SetLabelText(std::to_string(game->GetComputerScore()));
  tie_cnt_text->SetLabelText(std::to_string(game->GetTieGameCnt()));
}


} // namespace myrps
