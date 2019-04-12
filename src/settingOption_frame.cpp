#include "settingOption_frame.h"

using myrps::SettingOptionFrame;

// The event table.
wxBEGIN_EVENT_TABLE(SettingOptionFrame, wxFrame)
    EVT_MENU(RPS_Quit,  SettingOptionFrame::on_quit)
    EVT_MENU(RPS_About, SettingOptionFrame::on_about)
wxEND_EVENT_TABLE()

namespace myrps
{
const int SIDE_MARGINS = 40;

SettingOptionFrame::SettingOptionFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title),
      settingOption_panel(new SettingOptionPanel(this))
{
    init();

    wxSize size = GetSize();
    size.SetWidth (size.GetWidth() + SIDE_MARGINS);
    SetSize(size);
}

SettingOptionFrame::~SettingOptionFrame()
{
    delete settingOption_panel;
}

void SettingOptionFrame::init()
{
    init_menu_bar();
    init_sizer();

    wxSize size = GetBestSize();
    SetMinClientSize(size);
}

void SettingOptionFrame::init_menu_bar()
{
    wxMenu *fileMenu = new wxMenu;
    fileMenu->Append(RPS_Quit,  "E&xit\tAlt-X", "Quit program");

    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(RPS_About, "&About\tF1",   "Show about dialog");

    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(helpMenu, "&Help");
    SetMenuBar(menuBar);
}

void SettingOptionFrame::init_sizer()
{
    wxSizer *frame_sizer = new wxBoxSizer(wxVERTICAL);

    frame_sizer->AddSpacer(20);
    frame_sizer->Add(settingOption_panel, 0, wxALIGN_CENTER, 0);

    SetSizerAndFit(frame_sizer);
}

void SettingOptionFrame::on_about(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxString::Format(
                    "This is a button demo\n"
                    "built with %s\n"
                    "and running under %s.",
                    wxVERSION_STRING,
                    wxGetOsDescription()
                ),
                "About the button demo",
                wxOK | wxICON_INFORMATION,
                this);
}

void SettingOptionFrame::on_quit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);  // true is to force the frame to close
}
} // namespace myrps
