#include "game_frame.h"

using myrps::GameFrame;

// The event table.
wxBEGIN_EVENT_TABLE(GameFrame, wxFrame)
  EVT_MENU(GAME_Quit, GameFrame::on_quit)
  EVT_MENU(GAME_About, GameFrame::on_about)
  wxEND_EVENT_TABLE()

namespace myrps
{
  const int SIDE_MARGINS = 40;

  GameFrame::GameFrame(const wxString &title)
      : wxFrame(NULL, wxID_ANY, title),
        game_panel(new GamePanel(this))
  {
    init();

    wxSize size = GetSize();
    size.SetWidth(size.GetWidth() + SIDE_MARGINS);
    SetSize(size);
  }

  GameFrame::~GameFrame()
  {
    delete game_panel;
  }

  void GameFrame::init()
  {
    init_menu_bar();
    init_sizer();

    wxSize size = GetBestSize();
    SetMinClientSize(size);
  }

  void GameFrame::init_menu_bar()
  {
    wxMenu *fileMenu = new wxMenu;
    fileMenu->Append(GAME_Quit, "E&xit\tAlt-X", "Quit program");

    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(GAME_About, "&About\tF1", "Show about dialog");

    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(helpMenu, "&Help");
    SetMenuBar(menuBar);
  }

  void GameFrame::init_sizer()
  {
    wxSizer *frame_sizer = new wxBoxSizer(wxVERTICAL);

    frame_sizer->AddSpacer(20);
    frame_sizer->Add(game_panel, 0, wxALIGN_CENTER, 0);

    SetSizerAndFit(frame_sizer);
  }

  void GameFrame::on_about(wxCommandEvent & WXUNUSED(event))
  {
    wxMessageBox(wxString::Format(
                     "This is a button demo\n"
                     "built with %s\n"
                     "and running under %s.",
                     wxVERSION_STRING,
                     wxGetOsDescription()),
                 "About the button demo",
                 wxOK | wxICON_INFORMATION,
                 this);
  }

  void GameFrame::on_quit(wxCommandEvent & WXUNUSED(event))
  {
    Close(true); // true is to force the frame to close
  }
} // namespace myrps
