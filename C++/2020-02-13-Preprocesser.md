# Preprocesser


Preprocesser(전처리기)는 프로그램을 컴파일 할때 컴파일 직전 실행 되는 별도의 프로그램이다. 전처리기가 실행 되면 각 코드 파일에서 지시자를 찾는다. 

지사자는 `#` 으로 시작해서 줄바꿈으로 끝나는 코드다

단순히 텍스트를 조작하는 치환 역학 혹은 디버깅에돋 도움을 주고, 헤더 파일의 중복 포함도 방지해주는 기능을 가진다.

## INCLUDE 

`#Include` 는 include 된 파일의 내용을 지시자의 위치에 복사한다.

`<>` 는 컴파일러와 함께 제공되는 헤더파일을 include 할때 사용한다. 

`" "` 는 소스 파일이 있는 디렉터리에서 헤더 파일을 include 하도록 전처리기 에게 지시한다. 일반적으로 이와 같은 방법으로 자신이 작성한 헤더파일을 include한다.

## Macro

`#define` 지시자를 통해 매크로를 만들수 있다.

매크로는 객체와 유사한 매크로 와 함수와 유사한 매크로 가 있다.

함수와 유사한 매크로는 함수처럼 작동한다.

객체와 유사한 매크로는 아래와 같이 두가지 방법중 하나로 정의한다.

```cpp
#define identifier
#define identifier sub_text
```
두번째 지시자는 identifier 가 나올때 sub_text 로 대체된다. 일반적으로 식별자는 공백을 나타내는 밑줄을 사용하여 대문자로 모두 입력한다.

```cpp
#define MY_NUM_IS_9

cout << MY_NUM_IS_9 << endl;
// "9"
```

## Conditional comlpilation

조건부 컴파일 전처리 지시자를 사용하면 컴파일 할 조건이나 컴파일 하지 않을 조건을 지정할 수 있다.

`#ifdef` 지시자를 사용하면 전처리기 가 이전에 `#` 이 정의 되었는지 아닌지 확인하고, 정의 되었다면 `#ifdef` `#endif` 사이의 코드가 컴파일 된다.

```cpp
#define Adele

#ifdef Adele
cout << "Hello It's Me" << endl;
#endif
```

`#ifndef` 는 식별자가 아직 정의되지 않았는지 확인한다.
