/*
 * SFAtomSpec.c++
 *
 *     Classes:  SFAtomSpec
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

#include "inv/ChemKit/SFAtomSpec.hpp"
#include "inv/ChemKit/ChemBaseData.hpp"
// --> lod
#include "inv/ChemKit/ChemLOD.hpp"
// <-- lod
#include "inv/ChemKit/ChemDisplay.hpp"

//////////////////////////////////////////////////////////////////////////////
//
// SFAtomSpec class
//
//////////////////////////////////////////////////////////////////////////////

// Use standard definitions of all required methods, but we have to
// redefine all the rest to keep track of references and auditors.


SO_SFIELD_REQUIRED_SOURCE(SFAtomSpec);


////////////////////////////////////////////////////////////////////////
//
// Description:
//    Constructor
//
// Use: public

SFAtomSpec::SFAtomSpec()
//
////////////////////////////////////////////////////////////////////////
{
    // Make sure we create a NULL value
    value.setValue(NULL, NULL, -1);
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Destructor
//
// Use: public

SFAtomSpec::~SFAtomSpec()
//
////////////////////////////////////////////////////////////////////////
{
    ChemBaseData *chemData;
    ChemDisplay  *chemDisplay;
    int32_t       theAtom;

    value.getValue(chemData, chemDisplay, theAtom);

    if (chemData != NULL) {
        chemData->removeAuditor(this, SoNotRec::FIELD);
        chemData->unref();
    }
    if (chemDisplay != NULL) {
        chemDisplay->removeAuditor(this, SoNotRec::FIELD);
        chemDisplay->unref();
    }
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Sets value from an SbAtomSpec.
//
// Use: public

void
SFAtomSpec::setValue(const SbAtomSpec &atomSpec)
//
////////////////////////////////////////////////////////////////////////
{
    ChemBaseData *chemData = NULL;
    ChemDisplay  *chemDisplay = NULL;
    int32_t       theAtom;

    atomSpec.getValue(chemData, chemDisplay, theAtom);
    setVal(chemData, chemDisplay, theAtom);
    valueChanged();
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Sets value from the 3 components. (Convenience function)
//
// Use: public

void
SFAtomSpec::setValue(ChemBaseData *chemData, ChemDisplay *chemDisplay,
    int32_t theAtom)
//
////////////////////////////////////////////////////////////////////////
{
    setVal(chemData, chemDisplay, theAtom);
    valueChanged();
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Equality test
//
// Use: public

int
SFAtomSpec::operator ==(const SFAtomSpec &atomSpec) const
//
////////////////////////////////////////////////////////////////////////
{
    // The getValue() checks to see if any flags are dirty
    // so we can update if necessary before the comparison.
    return (getValue() == atomSpec.getValue());
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Changes the values without doing other notification stuff
//
// Use: private

void
SFAtomSpec::setVal(ChemBaseData *chemData, ChemDisplay *chemDisplay,
    int32_t theAtom)
//
////////////////////////////////////////////////////////////////////////
{
    // The logic here is similar to that for SoSFNode::setVal.
    // Essentially we need to add and remove auditors so that
    // the ChemBaseData and ChemDisplay nodes can be kept track of
    // correctly and read/written correctly.
    if (chemData != NULL) {
        chemData->ref();
    }
    if (chemDisplay != NULL) {
        chemDisplay->ref();
    }

    ChemBaseData *oldChemData = NULL;
    ChemDisplay  *oldChemDisplay = NULL;
    int32_t       oldAtom = -1;

    value.getValue(oldChemData, oldChemDisplay, oldAtom);

    if (oldChemData != NULL) {
        oldChemData->removeAuditor(this, SoNotRec::FIELD);
        oldChemData->unref();
    }
    if (oldChemDisplay != NULL) {
        oldChemDisplay->removeAuditor(this, SoNotRec::FIELD);
        oldChemDisplay->unref();
    }

    if (chemData != NULL) {
        chemData->ref();
        chemData->addAuditor(this, SoNotRec::FIELD);
    }
    if (chemDisplay != NULL) {
        chemDisplay->ref();
        chemDisplay->addAuditor(this, SoNotRec::FIELD);
    }

    value.setValue(chemData, chemDisplay, theAtom);

    if (chemData != NULL) {
        chemData->unref();
    }
    if (chemDisplay != NULL) {
        chemDisplay->unref();
    }
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Reads value from file. Returns FALSE on error.
//
// Use: private

SbBool
SFAtomSpec::readValue(SoInput *in)
//
////////////////////////////////////////////////////////////////////////
{
    SoBase *base;
    SbName name;
    char   c;

    ChemBaseData *chemData = NULL;
    ChemDisplay  *chemDisplay = NULL;
    int32_t       theAtom = -1;

    value.setValue(chemData, chemDisplay, theAtom);

    // Read the parentheses   
    if (! in->isBinary()) {  
        if (! (in->read(c) && c == '(')) return FALSE;
    }

    // Get the ChemBaseData node
    if (in->read(name)) {
        if (name != "NULL") {
            in->putBack(name.getString());
            if (! SoBase::read(in, base, SoNode::getClassTypeId())) {
                return FALSE;
            }
            chemData = (ChemBaseData *)base;
        }
    }
    else {
        return FALSE;
    }

    // Get the ChemDisplay node
    if (in->read(name)) {
        if (name != "NULL") {
            in->putBack(name.getString());
            if (! SoBase::read(in, base, SoNode::getClassTypeId())) {
                return FALSE;
            }
            chemDisplay = (ChemDisplay *)base;
        }
    }
    else {
        return FALSE;
    }

    // Get theAtom
    if (!in->read(theAtom)) return FALSE;

    
    // Read the close parentheses
    if (! in->isBinary()) {
        if (! (in->read(c) && c == ')')) return FALSE;
    }

    setVal(chemData, chemDisplay, theAtom);
    return TRUE;
}
    
////////////////////////////////////////////////////////////////////////
//   
// Description:
//    Overrides SoField::countWriteRefs() to maintain write-references
//    in the ChemBaseData and ChemDisplay nodes.
//
// Use: private
            
void
SFAtomSpec::countWriteRefs(SoOutput *out) const
//
////////////////////////////////////////////////////////////////////////
{
    // Do standard counting for field
    SoField::countWriteRefs(out);

    ChemBaseData *chemData = NULL;
    ChemDisplay  *chemDisplay = NULL;
    int32_t       theAtom = -1;
        
    value.getValue(chemData, chemDisplay, theAtom);
    if (chemData != NULL) {
        chemData->writeInstance(out);
    }
    if (chemDisplay != NULL) {
        chemDisplay->writeInstance(out);
    }
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Writes value of field to file.
//
// Use: private

void
SFAtomSpec::writeValue(SoOutput *out) const
//
////////////////////////////////////////////////////////////////////////
{
    ChemBaseData *chemData = NULL;
    ChemDisplay  *chemDisplay = NULL;   
    int32_t       theAtom = -1;
    
    value.getValue(chemData, chemDisplay, theAtom);
    
    // Write out the parentheses
    if (! out->isBinary()) out->write("( ");
    
    // Write out the ChemBaseData
    if (chemData != NULL) {
        int referenceId = 0;//out->findReference(chemData);
        out->write("USE");
        if (! out->isBinary()) out->write(' ');
    
        SbString t;
        const SbName &myName = chemData->getName();
        if (myName.getLength() != 0) {
            t += myName.getString();
        }
        t += "+";
        t += SbString(referenceId);
        out->write(t.getString());
    }
    else {
        out->write("NULL");
    }
    if (! out->isBinary()) out->write(' ');
    
    // Write out the ChemDisplay
    if (chemDisplay != NULL) {
        int referenceId = 0;//out->findReference(chemDisplay);
        out->write("USE");
        if (! out->isBinary()) out->write(' ');

        SbString t;
        const SbName &myName = chemDisplay->getName();
        if (myName.getLength() != 0) {
            t += myName.getString();
        }
        t += "+";
        t += SbString(referenceId);
        out->write(t.getString());
    }
    else {
        out->write("NULL");
    }
    if (! out->isBinary()) out->write(' ');
    
    // Write out theAtom
    out->write(theAtom);
    
    // Write out the parentheses
    if (! out->isBinary()) out->write(" )");
}

////////////////////////////////////////////////////////////////////////
// 
// Description:
//    Update a copied field to use the copy of each node if there is
//    one.
//
// Use: internal

void
SFAtomSpec::fixCopy(SbBool copyConnections)
// 
////////////////////////////////////////////////////////////////////////
{
    ChemBaseData *chemData = NULL;
    ChemBaseData *chemDataCopy = NULL;
    ChemDisplay  *chemDisplay = NULL;   
    ChemDisplay  *chemDisplayCopy = NULL;   
    int32_t       theAtom = -1;
    
    value.getValue(chemData, chemDisplay, theAtom);

    if (chemData != NULL) {
        chemDataCopy = (ChemBaseData *)
            SoFieldContainer::findCopy(chemData, copyConnections);
    }
    if (chemDisplay != NULL) {
        chemDisplayCopy = (ChemDisplay *)
            SoFieldContainer::findCopy(chemDisplay, copyConnections);
    }

    if ((chemDataCopy != NULL) || (chemDisplayCopy != NULL)) {
        setVal(chemDataCopy, chemDisplayCopy, theAtom);
    }
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Override this to also check the stored node.
//
// Use: internal, virtual
 
SbBool
SFAtomSpec::referencesCopy() const
//
////////////////////////////////////////////////////////////////////////
{
    // Do the normal test, and also see if the stored node is a copy
    if (SoSField::referencesCopy()) {
        return TRUE;
    }

    ChemBaseData *chemData = NULL;
    ChemDisplay  *chemDisplay = NULL;   
    int32_t       theAtom = -1;
    
    value.getValue(chemData, chemDisplay, theAtom);

    if ((chemData != NULL) &&
        (SoFieldContainer::checkCopy(chemData) != NULL)) {
        return TRUE;
    }
    if ((chemDisplay != NULL) &&
        (SoFieldContainer::checkCopy(chemDisplay) != NULL)) {
        return TRUE;
    }

    return FALSE;
}
