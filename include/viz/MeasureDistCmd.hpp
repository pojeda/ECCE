/**
 * @file
 *
 *
 */
#ifndef  MEASUREDISTCMD_H
#define  MEASUREDISTCMD_H

#include "util/Command.hpp"
#include "viz/MeasureBaseCmd.hpp"

class Fragment;

/**
 * Command wrapper for adding a distance measure.
 */
class MeasureDistCmd : public MeasureBaseCmd
{
   public:
      MeasureDistCmd(const string& name, Receiver * receiver);
      virtual ~MeasureDistCmd();

      virtual bool execute() throw(EcceException);

   protected:
      virtual void init();

};

#endif




