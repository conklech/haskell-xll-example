#include <Rts.h>
#include <windows.h>
#include "xlcall.h"
#include "..\Excel2007XLLSDK\src\xlcall.cpp"

#include "Adder_stub.h"

int xlAutoOpen()
{
    int argc = 1;
    char* argv[] = {"", NULL}; // argv must end with NULL

    // Initialize Haskell runtime
    char** args = argv;
    hs_init(&argc, &args);
    
    XLOPER12 xProcedure;
    xProcedure.xltype = xltypeStr;
    xProcedure.val.str = (LPWSTR) L"\005adder"; // function name -- accord with Adder.def.
                                                // note length-count in first character

    XLOPER12 xTypeText;
    xTypeText.xltype = xltypeStr;
    xTypeText.val.str = (LPWSTR) L"\003JJJ"; // Returns int; takes int and int.
   
    XLOPER12 xFunctionText;
    xFunctionText.xltype = xltypeStr;
    xFunctionText.val.str = (LPWSTR) L"\005ADDER";
    
    XLOPER12 xModuleText;
    Excel12(xlGetName, (LPXLOPER12)&xModuleText, 0);

    Excel12(xlfRegister, 0, 4, (LPXLOPER12)&xModuleText, (LPXLOPER12)&xProcedure, (LPXLOPER12)&xTypeText, (LPXLOPER12)&xFunctionText);
    
    Excel12(xlFree, 0, 4, (LPXLOPER12)&xModuleText, (LPXLOPER12)&xProcedure, (LPXLOPER12)&xTypeText, (LPXLOPER12)&xFunctionText);
    return 1;
}

int xlAutoClose()
{
   hs_exit();
   return 1;
}