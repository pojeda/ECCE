/*
 *
 *  Copyright (C) 2000 Silicon Graphics, Inc.  All Rights Reserved. 
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  Further, this software is distributed without any warranty that it is
 *  free of the rightful claim of any third person regarding infringement
 *  or the like.  Any license provided herein, whether implied or
 *  otherwise, applies only to this software file.  Patent licenses, if
 *  any, provided herein do not apply to combinations of this program with
 *  other software, or any other product whatsoever.
 * 
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,
 *  Mountain View, CA  94043, or:
 * 
 *  http://www.sgi.com 
 * 
 *  For further information regarding this notice, see: 
 * 
 *  http://oss.sgi.com/projects/GenInfo/NoticeExplan/
 *
 */

//  -*- C++ -*-

/*
 * Copyright (C) 1990,91,92   Silicon Graphics, Inc.
 *
 _______________________________________________________________________
 ______________  S I L I C O N   G R A P H I C S   I N C .  ____________
 |
 |   $Revision: 22147 $
 |
 |   Description:
 |	This file contains the implementation of the SoUnknownNode engine
 |
 |   Classes:
 |	SoUnknownEngine
 |
 |   Author(s)		: Gavin Bell, Dave Immel
 |
 ______________  S I L I C O N   G R A P H I C S   I N C .  ____________
 _______________________________________________________________________
 */

#ifndef  _SO_UNKNOWN_ENGINE_
#define  _SO_UNKNOWN_ENGINE_

#include "inv/engines/SoSubEngine.hpp"

class SoUnknownEngine : public SoEngine {

    SO_ENGINE_HEADER(SoUnknownEngine);
    
  public:

    // Constructor
    SoUnknownEngine();
    
  protected:
    // Returns file format name
    virtual const char *getFileFormatName() const;

    // Copies the contents of the given engine into this instance
    virtual void	copyContents(const SoFieldContainer *fromFC,
				     SbBool copyConnections);

  SoINTERNAL public:

    static void 	initClass();
    void 	    	setClassName(const char *name);

  private:

    // Per-instance input and output data:
    SoFieldData		*instanceInputData;
    SoEngineOutputData	*instanceOutputData;

    // The class name read from the file.  This is used when writing the
    // engine back out.
    char		*className;

    // Destructor
    ~SoUnknownEngine();

    // Evaluation method
    virtual void evaluate();
};

#endif  /* _SO_UNKNOWN_ENGINE_ */
