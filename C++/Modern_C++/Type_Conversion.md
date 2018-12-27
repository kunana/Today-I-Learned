
> 형변환시 고려사항


큰 자료형에서 작은 자료형으로 형변환을 할 경우 일부가 잘려나갈 수 있다.

```cpp
#include "stdafx.h"
#include <iostream>
 
using namespace std;
 
int _tmain(int argc, _TCHAR* argv[])
{
    float number1 = 55.55;
    int number2 = (int)number1;
    bool number3 = (bool)number1;
    cout << number2 << "\n";
    return 0;
}
``` 

> 명시적 형변환
```cpp
float number1 = 55.55;
int number2 = (int)number1;
bool number3 = (bool)number1;
```
변환할 자료형을 명시((int))해준다.
 

> 묵시적 형변환
```cpp
float number1 = 55.55;
int number2 = number1;
bool number3 = number1;
```
그냥 대입한다.
 

명시적 형변환과 묵시적 형변환의 차이점
* 결과적인 차이는 없다
* 명시적 형변환의 경우 `내부적으로 임시변수를 생성에 대입하는 방식`으로 성능 저하를 일으킬 수 있다.
* 묵시적 형변환의 경우 데이터 손실에 대한 경고가 발생한다.
 

[출처](http://myblog.opendocs.co.kr/archives/1249)