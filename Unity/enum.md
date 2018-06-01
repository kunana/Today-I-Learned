# TIL   / 2018-06-01
  ## Unity - Programming Patten
    ### 열거형 < C# >


> 상수의 일종으로 const 대신에 enum 을 사용한다.

- 열거형은 const 와 다르게 값을 입력하지 않아도 자동으로 0,1,2,3.. 이 대입 된다. 즉, 첫번째 값을 대입하면 자동으로 1씩 더한 수가 들어가게 된다.
- 위 설명과 같이 선언된 열거형은 구분이외의 목적은 따로없다.
- 같은 종류에 속하는 여러개 상수를 선언할때, 단숭히 종류를 구별 하기 위해 상수가 필요하다면, 열거형을 사용하는 것이 좋다.
-  

### 열거형 기본 예제
> 아래와 같이 열거형을 선언한 후 열거형 타입의 변수 선언 및 할당을 한다.


```
enum state
{
  Idle,
  Walk,
  Chase,
  Attack,
  Dead
};

State state = State.Idle; // State 열거 타입의 변수(state) 선언
```

```


### C#
> Expain shortly

설명


```
Typing Code

```
> http://itmining.tistory.com/30 참조
