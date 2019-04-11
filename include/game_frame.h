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

  /**
     * Event handler for the About menu item.
     * @param event the item selection event.
     */
  void on_about(wxCommandEvent &event);

  /**
     * Event handler for the Quit menu item.
     * @param event the item selection event.
     */
  void on_quit(wxCommandEvent &event);

  /**
    * Set the game's computer decision mode.
    */
  void SetComputerMode(SettingOption mode);

private:
  // The event table that maps events to their handlers.
  wxDECLARE_EVENT_TABLE();

  GamePanel *game_panel;

  /**
     * Initialize the contents of the application frame.
     */
  void init();

  /**
     * Initialize the application frame's menu and status bars.
     */
  void init_menu_bar();

  /**
     * Initialize the application frame's sizer.
     */
  void init_sizer();

   /**
    * Initialize the application's first game.
    */
  void InitGame();
};

// IDs for the menu commands.
enum
{
  GAME_Quit = wxID_EXIT,
  GAME_About = wxID_ABOUT
};

} // namespace myrps

#endif /* GameFRAME_H_ */
