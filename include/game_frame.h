#ifndef GAME_FRAME_H_
#define GAME_FRAME_H_

#include "game_panel.h"

namespace myrps
{
class GameFrame : public wxFrame
{
public:
  GameFrame(const wxString &title);

  virtual ~GameFrame();

  void OnAbout(wxCommandEvent &event);
  void OnQuit(wxCommandEvent &event);

  void SetComputerMode(SettingOption mode);

private:
  wxDECLARE_EVENT_TABLE();

  GamePanel *game_panel;

  void init();
  void InitMenuBar();
  void InitSizer();
  void InitGame();
};

// IDs for the menu commands.
enum
{
  GAME_Quit = wxID_EXIT,
  GAME_About = wxID_ABOUT
};
} // namespace myrps

#endif
