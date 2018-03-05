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
 |	SoNormalBindingElement
 |
 |   Author(s)		: Paul S. Strauss
 |
 ______________  S I L I C O N   G R A P H I C S   I N C .  ____________
 _______________________________________________________________________
 */

#include "inv/elements/SoNormalBindingElement.H"

SO_ELEMENT_SOURCE(SoNormalBindingElement);

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Destructor.
//
// Use: private

SoNormalBindingElement::~SoNormalBindingElement()
//
////////////////////////////////////////////////////////////////////////
{
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Initializes element
//
// Use: public

void
SoNormalBindingElement::init(SoState *)
//
////////////////////////////////////////////////////////////////////////
{
    data = getDefault();
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Prints element for debugging.
//
// Use: public
//
////////////////////////////////////////////////////////////////////////

#ifdef DEBUG
void
SoNormalBindingElement::print(FILE *fp) const
{
    const char *bindingName;

    SoElement::print(fp);

    switch ((Binding)data) {

      case OVERALL:
	bindingName = "OVERALL";
	break;

      case PER_PART:
	bindingName = "PER_PART";
	break;

      case PER_PART_INDEXED:
	bindingName = "PER_PART_INDEXED";
	break;

      case PER_FACE:
	bindingName = "PER_FACE";
	break;

      case PER_FACE_INDEXED:
	bindingName = "PER_FACE_INDEXED";
	break;

      case PER_VERTEX:
	bindingName = "PER_VERTEX";
	break;

      case PER_VERTEX_INDEXED:
	bindingName = "PER_VERTEX_INDEXED";
	break;
    }

    fprintf(fp, "\tNormal Binding = %s\n", bindingName);
}
#else  /* DEBUG */
void
SoNormalBindingElement::print(FILE *) const
{
}
#endif /* DEBUG */
