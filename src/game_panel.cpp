#include "game_panel.h"

using myrps::GamePanel;

namespace myrps
{
void GamePanel::init()
{
  // main panel
  wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

  // buttons' panel
  wxPanel *button_panel = new wxPanel(this, wxID_ANY);
  wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);

  wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
                                               "Choose:");
  wxButton *rock_button = new wxButton(button_panel, wxID_ANY,
                                       move_to_wxString(MoveChoice::kRock));
  wxButton *paper_button = new wxButton(button_panel, wxID_ANY,
                                        move_to_wxString(MoveChoice::kPaper));
  wxButton *scissors_button = new wxButton(button_panel, wxID_ANY,
                                           move_to_wxString(MoveChoice::kScissors));

  rock_button->Bind(wxEVT_BUTTON, &GamePanel::on_rock, this);
  paper_button->Bind(wxEVT_BUTTON, &GamePanel::on_paper, this);
  scissors_button->Bind(wxEVT_BUTTON, &GamePanel::on_scissors, this);

  button_sizer->Add(choose_text, 0, 0, 0);
  button_sizer->AddSpacer(5);
  button_sizer->Add(rock_button, 0, 0, 0);
  button_sizer->AddSpacer(5);
  button_sizer->Add(paper_button, 0, 0, 0);
  button_sizer->AddSpacer(5);
  button_sizer->Add(scissors_button, 0, 0, 0);

  button_panel->SetSizer(button_sizer);

  // chosen move panel
  wxPanel *chosen_panel = new wxPanel(this, wxID_ANY);
  wxSizer *chosen_sizer = new wxGridSizer(2, 0, 5);

  wxStaticText *chosen_move_text = new wxStaticText(chosen_panel, wxID_ANY,
                                               "Chosen move:");
  button_chosen_text = new wxStaticText(chosen_panel, wxID_ANY, "");
  button_chosen_text->SetFont(button_chosen_text->GetFont().Larger());

  chosen_sizer->Add(chosen_move_text, 0, wxALIGN_RIGHT, 0);
  chosen_sizer->Add(button_chosen_text, 0, 0, 0);

  chosen_panel->SetSizer(chosen_sizer);

  // which round currently being played panel
  wxPanel *round_count_panel = new wxPanel(this, wxID_ANY);
  wxSizer *round_count_sizer = new wxGridSizer(2, 0, 5);

  wxStaticText *current_round_text = new wxStaticText(round_count_panel, wxID_ANY,
                                               "Current round:");
  round_count_text = new wxStaticText(round_count_panel, wxID_ANY, "");
  round_count_text->SetFont(round_count_text->GetFont().Larger());

  round_count_sizer->Add(current_round_text, 0, wxALIGN_RIGHT, 0);
  round_count_sizer->Add(round_count_text, 0, 0, 0);

  round_count_panel->SetSizer(round_count_sizer);

  // put everything into main panel
  sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
  sizer->AddSpacer(20);
  sizer->Add(chosen_panel, 0, wxALIGN_CENTER, 0);
  sizer->AddSpacer(20);
  sizer->Add(round_count_panel, 0, wxALIGN_CENTER, 0);
  sizer->AddSpacer(20);

  SetSizer(sizer);
}

void GamePanel::on_rock(wxCommandEvent &event)
{
  update_button_move_text(MoveChoice::kRock);
  update_round_count_text(cnt++);
}

void GamePanel::on_paper(wxCommandEvent &event)
{
  update_button_move_text(MoveChoice::kPaper);
  update_round_count_text(cnt++);
}

void GamePanel::on_scissors(wxCommandEvent &event)
{
  update_button_move_text(MoveChoice::kScissors);
  update_round_count_text(cnt++);
}

void GamePanel::update_button_move_text(const MoveChoice move)
{
  button_chosen_text->SetLabelText(move_to_wxString(move));
}

void GamePanel::update_round_count_text(const int round_count)
{
  round_count_text->SetLabelText(std::to_string(round_count));
}

} // namespace myrps
