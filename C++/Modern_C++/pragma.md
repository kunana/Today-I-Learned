> ### #pragma once 
  
  컴파일러에게 한번만 컴파일 하라고 알려준다. 

> ### #pragma comment()

```cpp
#pragma comment( comment-type , comment string)
```
1. comment-type : complier, exestr, lib, linker, user 등
2.설정방법 :
   1. subsystem 설정방법.
    ```cpp
	#pragma comment(linker, "/subsystem:windows")
    #pragme comment(linker, "/subsystem:console")
   	```
   2. section 의 설정(공유메모리사용) 
    ```cpp
	#pragma comment(linker, "SECTION :.SHAREDATA, RWS") 
    #pragma data_seg("SHAREDATA")//와 함께 사용하여 공유 메모리를 생성한다. 위의 명령어 대신 def 파일안에 아래와 같이 해 주어도 된다.
	```
       
    SECTIONS
    SHAREDATA READ WRITE SHARED

    3. 명시적인 라이브러리 링크
	```cpp
	pragma comment(lib, "Mylib.lib")
	```    
	예를 들어 프로젝트 속성 -> link 탭에서 Mylib.lib 를 링크해주어야 할때,
	위와 같이 명시적으로 링크 시켜줄 수 있다.


> ### pragma a data_seg()

 ```cpp
#pragma data_seg( "section-name"), "section-class"
 ```

DLL 에서 Data 를 공유할때 사용하며, 사용할때 반드시 섹션을 설정해주어야한다.

```cpp
#pragma data_seg("SHARED_DATA")
int x;
int y;
CSharedClass sharedClass = {0};
#pragma data_seg();
```

> ### pragma a warning
  
```cpp
#pragma warning( warning-specifier : warning-number-list [; warning-specifier : 
                           warning-number-list...] )
#pragma warning( push[,n] )
#pragma warning( pop )	
 ```

```cpp
#pragma warning(disable:4998)
```

> ### pragma message()

컴파일 중에 메시지를 뿌려줌

```cpp
#pragma message("Hello World!")
```
