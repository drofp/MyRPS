#include "start_menu_panel.h"

using myrps::StartMenuPanel;

namespace myrps
{
void StartMenuPanel::init()
{
    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
                                                 "Welcome to myRPS!");
    wxButton *play_game_button = new wxButton(button_panel, wxID_ANY,
                                             move_to_wxString(StartOption::PLAY_GAME));
    wxButton *options_button = new wxButton(button_panel, wxID_ANY,
                                             move_to_wxString(StartOption::OPTIONS));

    play_game_button->Bind(wxEVT_BUTTON, &StartMenuPanel::on_play_game, this);
    options_button->Bind(wxEVT_BUTTON, &StartMenuPanel::on_options, this);

    button_sizer->Add(choose_text, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(play_game_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(options_button, 0, 0, 0);
    button_panel->SetSizer(button_sizer);

    wxPanel *chosen_panel = new wxPanel(this, wxID_ANY);
    wxSizer *chosen_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *chosen_text = new wxStaticText(chosen_panel, wxID_ANY,
                                                 "Chosen object:");
    button_chosen_text = new wxStaticText(chosen_panel, wxID_ANY, "");
    button_chosen_text->SetFont(button_chosen_text->GetFont().Larger());
    chosen_sizer->Add(chosen_text, 0, wxALIGN_RIGHT, 0);
    chosen_sizer->Add(button_chosen_text, 0, 0, 0);
    chosen_panel->SetSizer(chosen_sizer);

    sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(chosen_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);

    SetSizer(sizer);
}

void StartMenuPanel::on_play_game(wxCommandEvent& event)
{
    update_button_move_text(StartOption::PLAY_GAME);
}

void StartMenuPanel::on_options(wxCommandEvent& event)
{
    update_button_move_text(StartOption::OPTIONS);
}

void StartMenuPanel::update_button_move_text(const StartOption choice)
{
    button_chosen_text->SetLabelText(move_to_wxString(choice));
}

} // moveamespace myrps
