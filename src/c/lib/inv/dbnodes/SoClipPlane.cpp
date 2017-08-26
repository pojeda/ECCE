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

/*
 * Copyright (C) 1990,91   Silicon Graphics, Inc.
 *
 _______________________________________________________________________
 ______________  S I L I C O N   G R A P H I C S   I N C .  ____________
 |
 |   $Revision: 22147 $
 |
 |   Classes:
 |      SoClipPlane
 |
 |   Author(s)          : Paul S. Strauss
 |
 ______________  S I L I C O N   G R A P H I C S   I N C .  ____________
 _______________________________________________________________________
 */

#include "inv/actions/SoCallbackAction.hpp"
#include "inv/actions/SoGLRenderAction.hpp"
#include "inv/actions/SoPickAction.hpp"
#include "inv/elements/SoGLClipPlaneElement.hpp"
#include "inv/nodes/SoClipPlane.hpp"

SO_NODE_SOURCE(SoClipPlane);

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Constructor
//
// Use: public

SoClipPlane::SoClipPlane()
//
////////////////////////////////////////////////////////////////////////
{
    SO_NODE_CONSTRUCTOR(SoClipPlane);

    // Default clipping plane defines the half-space with non-negative x
    SO_NODE_ADD_FIELD(plane, (SbPlane(SbVec3f(1.0, 0.0, 0.0), 0.0)));
    SO_NODE_ADD_FIELD(on,    (TRUE));

    isBuiltIn = TRUE;
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Destructor
//
// Use: private

SoClipPlane::~SoClipPlane()
//
////////////////////////////////////////////////////////////////////////
{
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Typical action method.
//
// Use: extender

void
SoClipPlane::doAction(SoAction *action)
//
////////////////////////////////////////////////////////////////////////
{
    // Add clip plane only if it is active
    if (! on.isIgnored() && on.getValue() == FALSE)
	return;

    if (! plane.isIgnored()) {
	SoClipPlaneElement::add(action->getState(), this, plane.getValue());
    }
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Performs callback action
//
// Use: extender

void
SoClipPlane::callback(SoCallbackAction *action)
//
////////////////////////////////////////////////////////////////////////
{
    SoClipPlane::doAction(action);
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Performs GL rendering on a clipPlane node.
//
// Use: extender

void
SoClipPlane::GLRender(SoGLRenderAction *action)
//
////////////////////////////////////////////////////////////////////////
{
    SoClipPlane::doAction(action);
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Performs picking on a clipPlane node.
//
// Use: extender

void
SoClipPlane::pick(SoPickAction *action)
//
////////////////////////////////////////////////////////////////////////
{
    SoClipPlane::doAction(action);
}
