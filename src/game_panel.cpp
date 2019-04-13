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


  // game info panel
  game_info_panel = new wxPanel(this, wxID_ANY);
  GenerateGameInfoPanel();

  vector<wxPanel *> panels;
  panels.push_back(button_panel);
  panels.push_back(game_info_panel);

  AddSubPanelsToMainPanel(panels, sizer);

  SetGameVisibility(false);
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
  ///// Main Button Sizer /////
  wxSizer *button_sizer = new wxBoxSizer(wxVERTICAL);

  ///// Start Menu Section /////
  wxSizer *start_sizer = new wxBoxSizer(wxHORIZONTAL);

  wxStaticText *start_text = new wxStaticText(button_panel, wxID_ANY,
                                               "Welcome to MyRPS!");
  wxButton *play_game_button = new wxButton(button_panel, wxID_ANY,
                                       move_to_wxString(StartOption::PLAY_GAME));
  wxButton *options_button = new wxButton(button_panel, wxID_ANY,
                                        move_to_wxString(StartOption::OPTIONS));

  play_game_button->Bind(wxEVT_BUTTON, &GamePanel::OnPlayGame, this);
  options_button->Bind(wxEVT_BUTTON, &GamePanel::OnOptions, this);

  start_sizer->Add(start_text, 0, 0, 0);
  start_sizer->AddSpacer(5);
  start_sizer->Add(play_game_button, 0, 0, 0);
  start_sizer->AddSpacer(5);
  start_sizer->Add(options_button, 0, 0, 0);

  button_sizer->Add(start_sizer);
  button_sizer->AddSpacer(10);

  ///// Options Menu Section /////
  wxSizer *options_sizer = new wxBoxSizer(wxHORIZONTAL);
  wxStaticText *option_text = new wxStaticText(button_panel, wxID_ANY,
                                              "Choose difficulty level:");
  wxButton *random_button = new wxButton(button_panel, wxID_ANY,
                                            move_to_wxString(SettingOption::kRandom));
  wxButton *smart_button = new wxButton(button_panel, wxID_ANY,
                                            move_to_wxString(SettingOption::kSmart));

  random_button->Bind(wxEVT_BUTTON, &GamePanel::OnRandom, this);
  smart_button->Bind(wxEVT_BUTTON, &GamePanel::OnSmart, this);
  
  options_sizer->Add(option_text, 0, 0, 0);
  options_sizer->AddSpacer(10);
  options_sizer->Add(random_button, 0, 0, 0);
  options_sizer->AddSpacer(5);
  options_sizer->Add(smart_button, 0, 0, 0);

  // options_sizer->Hide();
  
  button_sizer->Add(options_sizer);
  
  SetOptionsVisibility(false);

  button_sizer->AddSpacer(10);

  ///// Game Section /////
  wxSizer *game_sizer = new wxBoxSizer(wxHORIZONTAL);

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

  game_sizer->Add(choose_text, 0, 0, 0);
  game_sizer->AddSpacer(5);
  game_sizer->Add(rock_button, 0, 0, 0);
  game_sizer->AddSpacer(5);
  game_sizer->Add(paper_button, 0, 0, 0);
  game_sizer->AddSpacer(5);
  game_sizer->Add(scissors_button, 0, 0, 0);

  button_sizer->Add(game_sizer);

  button_panel->SetSizer(button_sizer);
}

void GamePanel::GenerateGameInfoPanel()
{
  wxSizer *game_info_sizer = new wxGridSizer(3, 1, 4);

  wxStaticText *chosen_move_text = new wxStaticText(game_info_panel, wxID_ANY,
                                               "Player's move:");

  button_chosen_text = new wxStaticText(game_info_panel, wxID_ANY, "");
  button_chosen_text->SetFont(button_chosen_text->GetFont().Larger());

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

  game_info_sizer->Add(chosen_move_text, 0, wxALIGN_RIGHT, 0);
  game_info_sizer->Add(button_chosen_text, 0, 0, 0);
  game_info_sizer->AddSpacer(20);
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

void GamePanel::OnPlayGame(wxCommandEvent& event)
{
  SetStartMenuVisibility(false);
  SetGameVisibility(true);
}

void GamePanel::OnOptions(wxCommandEvent& event)
{

}

void GamePanel::OnRandom(wxCommandEvent& event)
{

}

void GamePanel::OnSmart(wxCommandEvent& event)
{

}


void GamePanel::SetStartMenuVisibility(bool is_shown)
{
  // is_shown ? button_sizer->Enable() : button_sizer->Disable();
  // button_sizer->Layout();
}

void GamePanel::SetOptionsVisibility(bool is_shown)
{
  // is_shown ? options_sizer->Enable() : options_sizer->Disable();
  // options_sizer->Layout();
}

void GamePanel::SetGameVisibility(bool is_shown)
{
  is_shown ? game_info_panel->Enable() : game_info_panel->Disable();
  game_info_panel->Layout();
//   button_sizer->Hide(game_sizer, is_shown);
//   button_sizer->Layout();
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
