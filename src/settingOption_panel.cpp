#include "settingOption_panel.h"

using myrps::SettingOptionPanel;

namespace myrps
{
void SettingOptionPanel::init()
{
    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
                                                 "Choose difficulty level:");
    wxButton *random_button = new wxButton(button_panel, wxID_ANY,
                                             move_to_wxString(SettingOption::kRandom));
    wxButton *smart_button = new wxButton(button_panel, wxID_ANY,
                                             move_to_wxString(SettingOption::kSmart));

    random_button->Bind(wxEVT_BUTTON, &SettingOptionPanel::on_random_setting, this);
    smart_button->Bind(wxEVT_BUTTON, &SettingOptionPanel::on_smart_setting, this);
    
    button_sizer->Add(choose_text, 0, 0, 0);
    button_sizer->AddSpacer(10);
    button_sizer->Add(random_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(smart_button, 0, 0, 0);
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

void SettingOptionPanel::on_random_setting(wxCommandEvent& event)
{
    update_button_move_text(SettingOption::kRandom);
}

void SettingOptionPanel::on_smart_setting(wxCommandEvent& event)
{
    update_button_move_text(SettingOption::kSmart);
}

// void StartMenuPanel::on_exit(wxCommandEvent& event)
// {
//     update_button_move_text(StartOption::EXIT);
// }

void SettingOptionPanel::update_button_move_text(const SettingOption choice)
{
    button_chosen_text->SetLabelText(move_to_wxString(choice));
}

} // moveamespace myrps
