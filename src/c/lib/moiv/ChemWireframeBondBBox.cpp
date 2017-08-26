/*
 * ChemWireframeBondBBox.c++
 *
 *     Classes:  ChemWireframeBondBBox
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

#include "inv/ChemKit/ChemWireframeBondBBox.hpp"

//////////////////////////////////////////////////////////////////////////////
// 
// ChemWireframeBondBBox class
//
//////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Constructor
//
// Use: public

ChemWireframeBondBBox::ChemWireframeBondBBox(int32_t numBonds)  :
    ChemBondBBox(numBonds)
//
////////////////////////////////////////////////////////////////////////
{
    bondType = new short[numBonds];
    bondBBoxType = ChemBondBBox::WIREFRAME;
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Copy constructor
//
// Use: public

ChemWireframeBondBBox::ChemWireframeBondBBox(
    const ChemWireframeBondBBox &bondBBox) : ChemBondBBox(bondBBox)
//
////////////////////////////////////////////////////////////////////////
{
    bondBBoxType = ChemBondBBox::WIREFRAME;
    bondType = new short[numberOfBonds];
    for (int32_t i = 0; i < numberOfBonds; i++) {
        bondType[i] = bondBBox.bondType[i];
    }
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Copy constructor limited to numBonds
//
// Use: public

ChemWireframeBondBBox::ChemWireframeBondBBox(
    const ChemWireframeBondBBox &bondBBox, int32_t numBonds)
 : ChemBondBBox(bondBBox, numBonds)
//
////////////////////////////////////////////////////////////////////////
{
    bondBBoxType = ChemBondBBox::WIREFRAME;
    bondType = new short[numberOfBonds];
    for (int32_t i = 0; i < numberOfBonds; i++) {
        bondType[i] = bondBBox.bondType[i];
    }
}

////////////////////////////////////////////////////////////////////////
//
// Description:  
//    Destructor
//
// Use: public

ChemWireframeBondBBox::~ChemWireframeBondBBox()
//
////////////////////////////////////////////////////////////////////////
{
    if (bondType != NULL) delete [] bondType;
}
