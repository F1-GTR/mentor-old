//---------------------------------------------------------------------------

#ifndef MConvertH
#define MConvertH

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------

void TxtToBmp ( TList * List, Graphics::TBitmap * Bitmap, TFont * Font, int left, int top );
void TxtToBmp ( TStrings * List, Graphics::TBitmap * Bitmap, TFont * Font, int left, int top );
void FilePrint ( AnsiString FileName );

#endif
