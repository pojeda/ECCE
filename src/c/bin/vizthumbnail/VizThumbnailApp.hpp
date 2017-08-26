/**
 * @file
 *
 */
#ifndef VIZTHUMBNAILAPP_H_
#define VIZTHUMBNAILAPP_H_

#include "wxgui/ewxApp.hpp"
#include "wxgui/WxJMSMessageDispatch.hpp"
#include "wxgui/WxDavAuth.hpp"
#include "wxgui/WxJMSListener.hpp"


class CommandManager;
class SGContainer;;
class SGViewer;

/**
 */
class VizThumbnailApp : public ewxApp, public WxDavAuth,
                        public WxJMSMessageDispatch
{
   public:
      VizThumbnailApp();
      virtual bool OnInit();
      virtual int  OnExit();

      void subscribeMessages();

      void invokeMCB(JMSMessage& msg);
      void quitMCB(JMSMessage& msg);
      void identifyMCB(JMSMessage& msg);
      void invokeStatusMCB(JMSMessage& msg);
      void msgAuthMCB(JMSMessage& msg);

      string identify();

   protected:
      void render(JMSMessage& msg);
      void notifySuccess(const string& appName, const string& error = "");
};

DECLARE_APP(VizThumbnailApp)

#endif // VIZTHUMBNAILAPP_H_
