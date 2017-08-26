#include "wxviz/SGViewer.hpp"
#include "wxviz/CenterViewCmd.hpp"

CenterViewCmd::CenterViewCmd(const string& name, Receiver *receiver)
       : Command(name, receiver)
{
  init();
}


CenterViewCmd::~CenterViewCmd()
{
}


void CenterViewCmd::init() 
{
}


bool CenterViewCmd::execute() throw(EcceException)
{
  SGViewer *viewer = dynamic_cast<SGViewer*>(getReceiver());
  viewer->viewAll();

  return true;
}


void CenterViewCmd::undo()
{
}


bool CenterViewCmd::isUndoable() const
{
  return false;
}
