#include "game_frame.h"

using myrps::GameFrame;

// The event table.
wxBEGIN_EVENT_TABLE(GameFrame, wxFrame)
  EVT_MENU(GAME_Quit, GameFrame::OnQuit)
  EVT_MENU(GAME_About, GameFrame::OnAbout)
wxEND_EVENT_TABLE()

namespace myrps
{
const int SIDE_MARGINS = 40;

GameFrame::GameFrame(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title),
      game_panel(new GamePanel(this))
{
  Init();

  wxSize size = GetSize();
  size.SetWidth(size.GetWidth() + SIDE_MARGINS);
  SetSize(size);
}

GameFrame::~GameFrame()
{
  delete game_panel;
}

void GameFrame::Init()
{
  InitMenuBar();
  InitSizer();
  InitGame();

  wxSize size = GetBestSize();
  SetMinClientSize(size);
}

void GameFrame::InitGame()
{
  Game* g = new Game(SettingOption::kRandom);
  game_panel->SetGame(g);
}

void GameFrame::SetComputerMode(SettingOption mode)
{
  game_panel->SetComputerMode(mode);
}

void GameFrame::InitMenuBar()
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

void GameFrame::InitSizer()
{
  wxSizer *frame_sizer = new wxBoxSizer(wxVERTICAL);

  frame_sizer->AddSpacer(20);
  frame_sizer->Add(game_panel, 0, wxALIGN_CENTER, 0);

  SetSizerAndFit(frame_sizer);
}

void GameFrame::OnAbout(wxCommandEvent & WXUNUSED(event))
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

void GameFrame::OnQuit(wxCommandEvent & WXUNUSED(event))
{
  Close(true); // true is to force the frame to close
}
} // namespace myrps
