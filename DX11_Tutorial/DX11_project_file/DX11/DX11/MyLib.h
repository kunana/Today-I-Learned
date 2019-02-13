#pragma once

class myLib
{
public:
	myLib();
	~myLib();
	myLib(const myLib&);

	WCHAR* const_WCHAR_Ptr_WCHAR(const WCHAR* str);
	char* const_WCHAR_Ptr_char_Ptr(const WCHAR* str);
private:

};
