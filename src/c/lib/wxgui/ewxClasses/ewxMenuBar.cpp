#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wxgui/ewxMenuBar.hpp"
#include "wxgui/ewxHelpHandler.hpp"

ewxMenuBar::ewxMenuBar() : wxMenuBar(), ewxStyledWindow()
{
   PushEventHandler(new ewxHelpHandler(this));
   setStyles(this, false);
}


ewxMenuBar::~ewxMenuBar()
{
  PopEventHandler(true);
}


bool ewxMenuBar::show(bool show)
{
  return wxMenuBar::Show(show);
   //setStyles(this);
}
