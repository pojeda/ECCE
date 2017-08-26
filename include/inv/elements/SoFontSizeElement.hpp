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
 * Copyright (C) 1990,91   Silicon Graphics, Inc.
 *
 _______________________________________________________________________
 ______________  S I L I C O N   G R A P H I C S   I N C .  ____________
 |
 |   $Revision: 22148 $
 |
 |   Description:
 |	This file defines the SoFontSizeElement class.
 |
 |   Author(s)		: Paul S. Strauss, Nick Thompson, Thad Beier
 |
 ______________  S I L I C O N   G R A P H I C S   I N C .  ____________
 _______________________________________________________________________
 */

#ifndef  _SO_FONT_SIZE_ELEMENT
#define  _SO_FONT_SIZE_ELEMENT

#include "inv/SbString.hpp"
#include "inv/elements/SoFloatElement.hpp"

//////////////////////////////////////////////////////////////////////////////
//
//  Class: SoFontSizeElement
//
//  Element storing the current font size
//
//////////////////////////////////////////////////////////////////////////////

SoEXTENDER class SoFontSizeElement : public SoFloatElement {

    SO_ELEMENT_HEADER(SoFontSizeElement);

  public:
    // Initializes element
    virtual void	init(SoState *state);

    // set the current font size
    static void		set(SoState *state, float size)
	{ SoFloatElement::set(classStackIndex, state, size); }

#ifndef IV_STRICT
    static void         set(SoState *state, SoNode *, float size)
        { set(state, size); }
#endif

    // return the current font name from the state
    static float	get(SoState *state)
	{ return SoFloatElement::get(classStackIndex, state); }

    // Returns the default font size
    static float	getDefault()	{ return 10.0; }

  SoINTERNAL public:
    // Initializes class
    static void		initClass();

  protected:
    virtual ~SoFontSizeElement();
};

#endif /* _SO_FONT_SIZE_ELEMENT */
