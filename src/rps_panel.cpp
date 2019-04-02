#include "rps_panel.h"

namespace myrps
{
void RpsPanel::init()
{
    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
                                                 "Choose:");
    wxButton *rock_button     = new wxButton(button_panel, wxID_ANY,
                                             "Rock");
    wxButton *paper_button    = new wxButton(button_panel, wxID_ANY,
                                             "Paper");
    wxButton *scissors_button = new wxButton(button_panel, wxID_ANY,
                                             "Scissors");

    rock_button->Bind    (wxEVT_BUTTON, &RpsPanel::on_rock, this);
    paper_button->Bind   (wxEVT_BUTTON, &RpsPanel::on_paper, this);
    scissors_button->Bind(wxEVT_BUTTON, &RpsPanel::on_scissors, this);

    button_sizer->Add(choose_text, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(rock_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(paper_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(scissors_button, 0, 0, 0);
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

void RpsPanel::on_rock(wxCommandEvent& event)
{
    update_button_choice_text(Move::kRock);
}

void RpsPanel::on_paper(wxCommandEvent& event)
{
    update_button_choice_text(Move::kPaper);
}

void RpsPanel::on_scissors(wxCommandEvent& event)
{
    update_button_choice_text(Move::kScissors);
}

void RpsPanel::update_button_choice_text(const Move move)
{
    button_chosen_text->SetLabelText(choice_to_wxString(move));
}

} // namespace myrps

