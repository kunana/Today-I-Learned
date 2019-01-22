class myLib
{
public:
	myLib();
	~myLib();
	myLib(const myLib&);

	template<typename T>
	T conversion_const_WCHAR_Ptr(const WCHAR* str);
	
private:

};

template<typename T>
inline T myLib::conversion_const_WCHAR_Ptr(const WCHAR * str)
{

	T result;
	_bstr_t conversion(str);
	str = conversion;
	return result;

}
