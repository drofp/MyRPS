#ifndef START_MENU_FRAME_H
#define START_MENU_FRAME_H

#include "start_menu_panel.h"

namespace myrps
{
class StartMenuFrame : public wxFrame
{
public:
    StartMenuFrame(const wxString& title);

    virtual ~StartMenuFrame();

    /**
     * Event handler for the About menu item.
     * @param event the item selection event.
     */
    void on_about(wxCommandEvent& event);

    /**
     * Event handler for the Quit menu item.
     * @param event the item selection event.
     */
    void on_quit(wxCommandEvent& event);

private:
    // The event table that maps events to their handlers.
    wxDECLARE_EVENT_TABLE();

    StartMenuPanel *start_menu_panel;

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
};

// IDs for the menu commands.
enum
{
    RPS_Quit  = wxID_EXIT,
    RPS_About = wxID_ABOUT
};

} // namespace myrps

#endif


