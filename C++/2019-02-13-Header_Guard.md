# Header_Guard

중복 정의 문제

식별자는 하나의 정의만 가질 수 있다. 따라서 변수, 함수를 두번이상 정의한 프로그램은 오류가 발생한다.

헤더파일이 두번 이상 포함 될 경우 문제가 발생 할수 있다.

### math.h
```cpp
int getSquare()
{
    return 42;
}
```

### other.h
```cpp
#include <math.h>

```

### main.cpp
```cpp
#include <math.h>
#include <other.h>
```

위 코드를 보면 main.cpp 에서 포함한 math 의 헤더 파일이 other 의 헤더에도 포함 시켜져있어서 위 코드는 컴파일 되지 않는다.

main.cpp 는 getSquare() 함수가 정의되어있는 math.h 를 복사하고, 또한 math.h 를 포함한 other.h 를 복사한다.

따라서 메인은
```cpp
int getSquare()
{
    return 42;
}

int getSquare()
{
    return 42;
}

int main()
{
    return 0;
}
```

## Header Guard
헤더 가드 라는 메커니즘을 통해 위 문제를 해결할수 있다. 헤더 가드는 조건부 컴파일 지시자를 사용한다.

```cpp
#ifndef SOME_UNIQUE_NAME
#define SOME_UNIQUE_NAME

//선언 과 정의

#endif
```

위 헤더 파일이 포함 되면 SOME_UNIQUE_NAME 가 정의 되어 있는지 확인하고, 헤더 파일을 처음 포함하면 SOME_UNIQUE_NAME 정의되어 있지않다. 그러므로 위 헤더를 포함한다.

그러나 이전에 위 파일을 포함 시켰다면 SOME_UNIQUE_NAME는 이미 정의 되어 있기 때문에 헤더 팡일 내용이 무시된다.

모든 헤더 파일에는 헤더 가드가 있어야 한다. SOME_UNIQUE_NAME 는 일반적으로 _H 가 부튼 헤더 파일의 이름을 사용한다.


## pragma once

#pragma 지시자를 이용한 단순한 헤더 가드를 지원한다.

그러나 C++ 의 공식적인 부분이 아니므로 모든 컴파일러가 지원하지 않는다. 호환성을 위해 헤더 가드를 사용하는 것이 좋다.
