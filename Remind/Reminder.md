<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [stringstream](#stringstream)
- [wchar_t](#wchar_t)
- [const wchar* -> char*  ( _bstr_t )](#const-wchar---char---_bstr_t-)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

이 문서는 내가 공부하면서 새로 배운것들, 혹은 깊이 있게 공부하지 못해서 `뭐였더라..` 가 나온 것들 을 간단하게 정리하는 문서이다.


> # S

## stringstream
___


> # W

##  wchar_t
___
`wchar_t` 는 와이드 문자를 저장하기 위한 자료형. 보통 영문 알파벳은 1바이트로 표현하지만, **유니코드는 2바이트 이상** 으로 표현하기 때문에 `wchar_t`로 저장해야 한다.  

**유니코드를 사용하려면 모든 입출력 함수를 바꿔주어야 한다. 또한 모든 문자는 2바이트**

기본 입출력 함수에 w를 붙이면 대부분은 다되는듯? 대신 2바이트(윈도우에서) 라는것을 염두할것.
```cpp
#include <iostream>
#include <wchar.h>
#include <tchar.h>
#include <locale.h>

using namespace std;

int main()
{   
        // 유니코드
	wchar_t wchar1[100] = L"아옳옳옳옳"; 
        // tchar.h 사용해야함. 멀티바이트 <-> 유니코드 호환
	wchar_t wchar2[100] = _T("아옳옳옳옳"); 
	wchar_t wchar3[100] = L"ⓣ없ⓔ맑은ⓘ™";

	std::cout << wchar1 << endl; //008FFB40
	std::cout << wchar2 << endl; //008FFA70
	std::cout << wchar3 << endl; //008FFA70

	//wcout << wchar1 << endl; //출력안됨
	//wcout << wchar2 << endl; //출력안됨
	//wcout << wchar3 << endl; //출력안됨

        // 전체 C 로케일을 한국으로, 
	_wsetlocale(LC_ALL, L"Korean"); 

	wcout << wchar1 << endl; //아옳옳옳옳
	wcout << wchar2 << endl; //아옳옳옳옳
	wcout << wchar3 << endl; //ⓣ없ⓔ맑은ⓘ™

//--------------------------------------------------------------
//	LC_ALL		전체 C 로케일을 선택한다.
//	LC_COLLATE	C 로케일의 데이터 정렬 범주를 선택합니다.
//	LC_CTYPE	C 로케일의 문자 분류 범주를 선택합니다.
//	LC_MONETARY	C 로켈의 통화 형식화 범주를 선택합니다.
//	LC_NUMERIC	C 로케일의 숫자 형식 범주를 선택합니다.
//	LC_TIME		C 로케일의 시간 형식 카테고리를 선택합니다.
//--------------------------------------------------------------

}
```

## const wchar* -> char*  ( _bstr_t )
___

요즘 다이렉트 X 를 배우고 있는데, 쉐이더 파일 경로 불러오는 데서 

const wchar* 를 char* 로 형변환 할줄 모르겠어서 계속 헤맴..

`comdef.h` 를 인클루드 해주고, const WCHAR 를 `_bstr_t` 타입으로 할당후, 바꿔주면 된다.

`wchar_t` 도 마찬가지 

```cpp
#include <comdef.h>
void main()
{
	const WCHAR* wc = L"dh으아아아아ⓔ맑 \n";
	_bstr_t b(wc);
	char* c = b;
	printf("%s", c);
}
```