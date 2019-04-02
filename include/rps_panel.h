#ifndef RPS_PANEL_H
#define RPS_PANEL_H

#include "my_rps.h"
#include "move.h"

namespace myrps
{
class RpsPanel : public wxPanel
{
public:
  RpsPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
  {
    init();
  }

  void on_rock(wxCommandEvent& event);
  void on_paper(wxCommandEvent& event);
  void on_scissors(wxCommandEvent& event);

private:
  wxStaticText *button_chosen_text;

  void init();
  void update_button_choice_text(const Move move)
};
} // namespace myrps

#endif

