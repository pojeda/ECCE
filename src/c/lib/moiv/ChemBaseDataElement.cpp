/*
 * ChemBaseDataElement.c++
 *
 *     Classes:  ChemBaseDataElement base class
 *
 *
 * Copyright 1996, 1997, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 *
 * UNPUBLISHED -- Rights reserved under the copyright laws of the United
 * States.   Use of a copyright notice is precautionary only and does not
 * imply publication or disclosure.
 *
 * U.S. GOVERNMENT RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to restrictions
 * as set forth in FAR 52.227.19(c)(2) or subparagraph (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS 252.227-7013 and/or
 * in similar or successor clauses in the FAR, or the DOD or NASA FAR
 * Supplement.  Contractor/manufacturer is Silicon Graphics, Inc.,
 * 2011 N. Shoreline Blvd. Mountain View, CA 94039-7311.
 *
 * THE CONTENT OF THIS WORK CONTAINS CONFIDENTIAL AND PROPRIETARY
 * INFORMATION OF SILICON GRAPHICS, INC. ANY DUPLICATION, MODIFICATION,
 * DISTRIBUTION, OR DISCLOSURE IN ANY FORM, IN WHOLE, OR IN PART, IS STRICTLY
 * PROHIBITED WITHOUT THE PRIOR EXPRESS WRITTEN PERMISSION OF SILICON
 * GRAPHICS, INC.
 */
/**************************************************************************\
 *
 * OpenMOIV - C++ library for molecular visualization using Inventor.
 * Copyright (C) 2001-2003 Universitat Pompeu Fabra - Barcelona (Spain)
 * 
 * Developers: Interactive Technology Group (GTI)
 * Team: Josep Blat, Eduard Gonzalez, Sergi Gonzalez,
 *       Daniel Soto, Alejandro Ramirez, Oscar Civit.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details (see the file 
 * LICENSE.LGPL at the root directory).
 *
 * REMARK: This library is a derived product.
 *         You need also to accept all other applicable licenses.
 * 
 * Homepage: http://www.tecn.upf.es/openMOIV/
 * Contact:  openmoiv@upf.es
 *
\**************************************************************************/

#ident "$Revision: 22141 $"

#include "inv/ChemKit/ChemBaseDataElement.hpp"

SO_ELEMENT_SOURCE(ChemBaseDataElement);

////////////////////////////////////////////////////////////////////////
// 
// Description:
//    Initializes element.
// 
// Use: public

void
ChemBaseDataElement::init(SoState *)
//
////////////////////////////////////////////////////////////////////////
{
    data = NULL;
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Overrides this method to return TRUE if the two elements match.
//    Comparison is based on nodeId and the value of "data".
// Use: public

SbBool
ChemBaseDataElement::matches(const SoElement *elt) const
//
////////////////////////////////////////////////////////////////////////
{
    if (elt == NULL) return FALSE;

    if ((nodeId == ((const ChemBaseDataElement *) elt)->nodeId) &&
        (data == ((const ChemBaseDataElement *) elt)->data)) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Set element's value.
//
// Use: public, static

void
ChemBaseDataElement::set(SoState *state, SoNode *node,
    ChemBaseData *value)
//
////////////////////////////////////////////////////////////////////////
{
    ChemBaseDataElement  *elt;

    // Get an instance we can change (pushing if necessary)
    elt = (ChemBaseDataElement *)getElement(state, classStackIndex, node);

    if (elt != NULL) elt->data = value;
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Returns value of a subclass from state.
//
// Use: public, static

ChemBaseData *
ChemBaseDataElement::get(SoState *state)
//
////////////////////////////////////////////////////////////////////////
{
    const ChemBaseDataElement *elt;

    elt =
    (const ChemBaseDataElement *)getConstElement(state, classStackIndex);

    return elt->data;
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Returns the first (top) instance of the element in the state.
//
// Use: public, static

const ChemBaseDataElement *
ChemBaseDataElement::getInstance(SoState *state)
// 
////////////////////////////////////////////////////////////////////////
{
    return (const ChemBaseDataElement *)
        getConstElement(state, classStackIndex);
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//     Create a copy of this instance suitable for calling matches()
//     on.
//
// Use: protected

SoElement *
ChemBaseDataElement::copyMatchInfo() const
//
////////////////////////////////////////////////////////////////////////
{
    ChemBaseDataElement *result =
        (ChemBaseDataElement *)getTypeId().createInstance();

    result->nodeId = nodeId;
    result->data = data;

    return result;
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
ChemBaseDataElement::print(FILE *fp) const
{
    SoElement::print(fp);

    fprintf(fp, "node: \"%s\", pointer: %d\n", getTypeId().getName().getString(),
        data);
}
#else  /* DEBUG */
void
ChemBaseDataElement::print(FILE *) const
{
}
#endif /* DEBUG */
