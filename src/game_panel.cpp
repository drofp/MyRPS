#include "game_panel.h"

using myrps::GamePanel;

namespace myrps
{
void GamePanel::init()
{
  wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

  start_menu_panel = new wxPanel(this, wxID_ANY);
  GenerateStartMenuPanel();

  options_panel = new wxPanel(this, wxID_ANY);
  GenerateOptionsPanel();

  game_buttons_panel = new wxPanel(this, wxID_ANY);
  GenerateGameButtonPanel();

  game_info_panel = new wxPanel(this, wxID_ANY);
  GenerateGameInfoPanel();

  vector<wxPanel *> panels;
  panels.push_back(start_menu_panel);
  panels.push_back(options_panel);
  panels.push_back(game_buttons_panel);
  panels.push_back(game_info_panel);

  AddSubPanelsToMainPanel(panels, sizer);

  SetGameVisibility(false);
  SetOptionsVisibility(false);

  SetSizer(sizer);

  current_difficulty = SettingOption::kRandom;
  num_rounds = 20;
}

void GamePanel::SetGame(Game* g)
{
  game = g;
}

void GamePanel::SetComputerMode(SettingOption mode)
{
  game->SetComputerMode(mode);
}

void GamePanel::GenerateStartMenuPanel()
{
  wxSizer *start_sizer = new wxBoxSizer(wxHORIZONTAL);

  wxStaticText *start_text = new wxStaticText(start_menu_panel, wxID_ANY,
                                               "Welcome to MyRPS!");
  wxButton *play_game_button = new wxButton(start_menu_panel, wxID_ANY,
                                       move_to_wxString(StartOption::PLAY_GAME));
  wxButton *options_button = new wxButton(start_menu_panel, wxID_ANY,
                                        move_to_wxString(StartOption::OPTIONS));

  play_game_button->Bind(wxEVT_BUTTON, &GamePanel::OnPlayGame, this);
  options_button->Bind(wxEVT_BUTTON, &GamePanel::OnOptions, this);

  start_sizer->Add(start_text, 0, 0, 0);
  start_sizer->AddSpacer(5);
  start_sizer->Add(play_game_button, 0, 0, 0);
  start_sizer->AddSpacer(5);
  start_sizer->Add(options_button, 0, 0, 0);
  start_menu_panel->SetSizer(start_sizer);
}

void GamePanel::GenerateOptionsPanel()
{
  wxSizer *options_sizer = new wxBoxSizer(wxHORIZONTAL);
  wxStaticText *option_text = new wxStaticText(options_panel, wxID_ANY,
                                              "Choose difficulty level:");
  wxButton *random_button = new wxButton(options_panel, wxID_ANY,
                                            move_to_wxString(SettingOption::kRandom));
  wxButton *smart_button = new wxButton(options_panel, wxID_ANY,
                                            move_to_wxString(SettingOption::kSmart));
  wxButton *round_button = new wxButton(options_panel, wxID_ANY,
                                            "Set # rounds");

  random_button->Bind(wxEVT_BUTTON, &GamePanel::OnRandom, this);
  smart_button->Bind(wxEVT_BUTTON, &GamePanel::OnSmart, this);
  round_button->Bind(wxEVT_BUTTON, &GamePanel::OnRoundSet, this);
  
  options_sizer->Add(option_text, 0, 0, 0);
  options_sizer->AddSpacer(5);
  options_sizer->Add(random_button, 0, 0, 0);
  options_sizer->AddSpacer(5);
  options_sizer->Add(smart_button, 0, 0, 0);
  options_sizer->AddSpacer(5);
  options_sizer->Add(round_button, 0, 0, 0);

  options_panel->SetSizer(options_sizer);
}

void GamePanel::GenerateGameButtonPanel()
{
  wxSizer *game_sizer = new wxBoxSizer(wxHORIZONTAL);

  wxStaticText *choose_text = new wxStaticText(game_buttons_panel, wxID_ANY,
                                               "Choose:");
  wxButton *rock_button = new wxButton(game_buttons_panel, wxID_ANY,
                                       move_to_wxString(MoveChoice::kRock));
  wxButton *paper_button = new wxButton(game_buttons_panel, wxID_ANY,
                                        move_to_wxString(MoveChoice::kPaper));
  wxButton *scissors_button = new wxButton(game_buttons_panel, wxID_ANY,
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

  game_buttons_panel->SetSizer(game_sizer);
}

void GamePanel::ResetGame()
{
  delete game;
  game = new Game(current_difficulty);
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
  SetOptionsVisibility(false);
  SetGameVisibility(true);
}

void GamePanel::OnOptions(wxCommandEvent& event)
{
  SetStartMenuVisibility(false);
  SetOptionsVisibility(true);
}

void GamePanel::OnRandom(wxCommandEvent& event)
{
  current_difficulty = SettingOption::kRandom;
  SetComputerMode(current_difficulty);
  SetStartMenuVisibility(true);
  SetOptionsVisibility(false);
}

void GamePanel::OnSmart(wxCommandEvent& event)
{
  current_difficulty = SettingOption::kSmart;
  SetComputerMode(current_difficulty);
  SetStartMenuVisibility(true);
  SetOptionsVisibility(false);
}

void GamePanel::OnRoundSet(wxCommandEvent& event)
{

  num_rounds = wxGetNumberFromUser(
      wxT("Set Number of Rounds\n"), wxT("Rounds: "), 
        wxT("MyRPS"), 20, 
        0, 100);
  game->SetRoundsPerMatch(num_rounds);

  SetOptionsVisibility(false);
  SetStartMenuVisibility(true);
}

void GamePanel::SetStartMenuVisibility(bool is_shown)
{
  is_shown ? start_menu_panel->Enable() : start_menu_panel->Disable();
  start_menu_panel->Layout();
}

void GamePanel::SetOptionsVisibility(bool is_shown)
{
  is_shown ? options_panel->Enable() : options_panel->Disable();
  options_panel->Layout();
}

void GamePanel::SetGameVisibility(bool is_shown)
{
  if(is_shown)
  {
    game_buttons_panel->Enable();
    game_info_panel->Enable();
  }
  else
  {
    game_buttons_panel->Disable();
    game_info_panel->Disable();
  }
  
  game_buttons_panel->Layout();
  game_info_panel->Layout();

}

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
  
  if (game->GetRoundCount() > num_rounds)
  {
    SetGameVisibility(false);
    SetStartMenuVisibility(true);
    ResetGame();
  }
}


} // namespace myrps
