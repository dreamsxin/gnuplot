/*
 * $Id: wd2d.h,v 1.6 2017-06-27 19:06:11 markisch Exp $
 */

/*
Copyright (c) 2017 Bastian Maerkisch. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are
permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice, this list of
      conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright notice, this list
      of conditions and the following disclaimer in the documentation and/or other materials
      provided with the distribution.

THIS SOFTWARE IS PROVIDED BY Bastian Maerkisch ``AS IS'' AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef WD2D_H
#define WD2D_H

// Enable if you want to use Direct2D 1.1 (Windows 8 and Windows 7 Platform Update)
//#define HAVE_D2D11

#ifndef HAVE_D2D11
# define DCRENDERER
#endif

#include <windows.h>
#include "wgnuplib.h"


#ifdef __cplusplus
extern "C" {
#endif

extern HRESULT d2dInit(LPGW lpgw);
extern HRESULT d2dResize(LPGW lpgw, RECT rect);
extern void d2dReleaseRenderTarget(LPGW lpgw);
extern void d2dCleanup(void);

#ifdef DCRENDERER
extern void drawgraph_d2d(LPGW lpgw, HDC hdc, LPRECT rect);
#else
extern void drawgraph_d2d(LPGW lpgw, HWND hwnd, LPRECT rect);
#endif

void InitFont_d2d(LPGW lpgw, HDC hdc, LPRECT rect);

#ifdef __cplusplus
}
#endif

#endif
