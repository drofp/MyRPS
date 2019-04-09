#include "rps_frame.h"

using myrps::RpsFrame;

// The event table.
wxBEGIN_EVENT_TABLE(RpsFrame, wxFrame)
    EVT_MENU(RPS_Quit,  RpsFrame::on_quit)
    EVT_MENU(RPS_About, RpsFrame::on_about)
wxEND_EVENT_TABLE()

namespace myrps
{
const int SIDE_MARGINS = 40;

RpsFrame::RpsFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title),
      rps_panel(new RpsPanel(this))
{
    init();

    wxSize size = GetSize();
    size.SetWidth (size.GetWidth() + SIDE_MARGINS);
    SetSize(size);
}

RpsFrame::~RpsFrame()
{
    delete rps_panel;
}

void RpsFrame::init()
{
    init_menu_bar();
    init_sizer();

    wxSize size = GetBestSize();
    SetMinClientSize(size);
}

void RpsFrame::init_menu_bar()
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

void RpsFrame::init_sizer()
{
    wxSizer *frame_sizer = new wxBoxSizer(wxVERTICAL);

    frame_sizer->AddSpacer(20);
    frame_sizer->Add(rps_panel, 0, wxALIGN_CENTER, 0);

    SetSizerAndFit(frame_sizer);
}

void RpsFrame::on_about(wxCommandEvent& WXUNUSED(event))
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

void RpsFrame::on_quit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);  // true is to force the frame to close
}
} // namespace myrps
