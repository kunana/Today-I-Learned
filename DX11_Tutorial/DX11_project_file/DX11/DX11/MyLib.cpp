#include "stdafx.h"
#include "MyLib.h"
#include <comdef.h>

myLib::myLib()
{
}

myLib::~myLib()
{
}

myLib::myLib(const myLib &)
{
}

WCHAR * myLib::const_WCHAR_Ptr_WCHAR(const WCHAR * str)
{
	_bstr_t conversion(str);
	WCHAR* origin = conversion;
	return origin;
}

char * myLib::const_WCHAR_Ptr_char_Ptr(const WCHAR * str)
{
	_bstr_t conversion(str);
	char* origin = conversion;
	return origin;
}