/*
 * ChemLabelPath.h
 *
 *	This file defines the ChemLabelPath class.
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

#ident "$Revision: 22148 $"

#ifndef __CHEM_LABEL_PATH_H__
#define __CHEM_LABEL_PATH_H__

#include "inv/misc/SoBase.hpp"
#include "inv/SoPath.hpp"

#include "inv/ChemKit/MFVec2i.hpp"
#include "inv/ChemKit/ChemPath.hpp"

class ChemSelection;

class CHEMKIT_DLL_API ChemLabelPath : public ChemPath {

  public:
    // Constructor
    ChemLabelPath();

    // Copy constructor
    ChemLabelPath(const ChemLabelPath &chemPath);

    // Create a new ChemLabelPath which is a copy of "this"
    ChemLabelPath *copy() const;

    // Returns type identifier for ChemLabelPath instance
    virtual SoType  getTypeId() const;
    
    // Returns type identifier for ChemLabelPath class
    static SoType   getClassTypeId()    { return classTypeId; }

    // Methods to access the private data
    SbBool setPath(SoPath *path, const MFVec2i *labelIndex);

    const MFVec2i &getLabelIndex() const;

    // Comparison operator: returns TRUE if all nodes in paths are identical
    int   operator ==(const ChemPath &chemPath) const;
    SbBool equals(const ChemPath &chemPath) const;

SoINTERNAL public:
    // Initialize the class
    static void initClass();
    
  protected:
    // Destructor
    ~ChemLabelPath();

    virtual SbBool  readInstance(SoInput *in, unsigned short flags);

  private:
    SbBool makeIndices(const MFVec2i &currentIndex,
                       MFVec2i &newIndex, int32_t end_indicator,
                       int32_t numberOfItems);

    static SoType  classTypeId;
    static void    *createInstance();

    MFVec2i labelIndex;

friend class ChemLabelPathList;
friend class ChemSelection;
};

#endif /* !__CHEM_LABEL_PATH_H__ */
