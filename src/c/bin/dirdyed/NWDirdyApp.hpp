#ifndef _NWDIRDYAPP_H
#define _NWDIRDYAPP_H

#include "wxgui/ewxApp.hpp"
#include "wxgui/WxJMSMessageDispatch.hpp"

class NWDirdy;
class JMSMessage;

class NWDirdyApp : public ewxApp
{
   public:
      NWDirdyApp();
      virtual ~NWDirdyApp();

      virtual string getName() const;

      /**
       *  Initialize application
       */
      virtual bool OnInit();


   protected:

      NWDirdy *p_nwdirdy;
};

DECLARE_APP(NWDirdyApp)

#endif
