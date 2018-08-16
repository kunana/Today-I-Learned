# TIL   / 2018-08-13

  # Lambda Expression < C# >

<br>

>## 람다식?

+ 컬렉션에 질의를 하기위해 LINQ에서 사용하는 표현식
+ '어떤 문제를 해결하기 위한 과정을 수학적 함수를 이용하여 표현한 수식'
+ 람다식은 컴파일 과정에서 Delegate로 치환된다.
+ (매개변수) => (표현식)
+ 간결한 표현이 가능하며, 지연연산을 통해 퍼포먼스 향상을 기대할수있다.
+ 모든 요소를 순회하는 경우에는 느릴수 밖에없다.
+ 디버깅시에 호출스택 추적이 어렵다.
+ 남발하면 본인 혹은 타인이 이해하기 힘들수도있다.

<br>

>## 예제

```csharp
int[] numbers = { 1, 4, 6, 9, 8, 12, 18, 17, 11, 22 };
 
IEnumerable<int> odds = numbers.Where (n => n%2 ==1); //1번
IEnumerable<int> odds = numbers.Where ((int)n => n%2 ==1); //2번
IEnumerable<int> odds = numbers.Where (delegate(int n){return n&2 ==1;}); //3번

```
>코드설명
1. 1번식 == numbers 에 있는 수를 차례로 이동하며, 홀수인 경우 값을 반환.
2. 2번식 == 1번식을 좀더 명확하게 나타낸것이 2번식.
3. 3번식 ==  1번, 2번식이 컴파일될때 만들어지는 코드로 익명대리자(Anonymous Delegate)형태로 나타냄.

>## 예제2
``` csharp

My Delegate A;
//무명 메소드
A = delegate(int a , int b)
{
    return a +b;
}

MyDelegate A;

//람다식
A = (int a, int b) => a+b;

//같은 람다식 (컴파일러의 타입 유추로 타입 생략 가능))
A = (a,b) => a+b;
```

>## 예제3 - 메소드
```csharp 

delegate void NewDelegate(int a, int b);

static void Main(string[] args)
{   
    NewDelegate Compare = (a, b ) =>
    {
      if(a > b)
      Console.WriteLine("{0}보다 {1}가 크다" , b, a);
      else if(a < b)
      Console.WriteLine("{0}보다 {1}가 작다", b, a);
      else 
      Console.WriteLine("{0} 과 {1} 은 같다", a,b);
    }

    Compare(11, 22);
}

```