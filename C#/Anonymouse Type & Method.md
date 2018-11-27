# TIL   / 2018-11-27

  # Anonymouse Type & Method < C# >
>## 무명형식, 무명 메소드

우리는 보통 변수를 만들때 자료형을 선언하고 만들어준다.

```cs
int A = 0;
```

그러나 C# 에는 자료형이 없는 형식이 있다.
```cs
var temp = new { Age = 21, Name = "군필자"};
Console.WriteLine("{0},{1}", temp.Age, temp.Name);
```
재사용 되지 않는 ``임시변수`` 에 아주 유용하다.

무명형식은 선언과 함께 ``new 키워드로 인스턴스를 생성``해주고, ``읽기전용이기 때문에 값 변경이 불가``하다.

<br>

>### 무명 형식 예제

```cs

var tempArr = new
{
    Int = new int[] {11, 22, 33, 44, 55};
    FLOAT = new float[] {11.0f, 22.0f, 33.0f, 44.0f, 55.0f};
}

foreach(var element In tempArr.Int)
{
    Console.Write("{0}", element);
}
Console.WriteLine();

foreach(var element In tempArr.FLOAT)
{
    Console.Write("{0}", element);
}
Console.WriteLine();

//11, 22, 33, 44, 55
//11.0f, 22.0f, 33.0f, 44.0f, 55.0f
```

>### 무명 메소드 

무명 메소드는 이름이 없기 때문에 메소드를 호출하기 위해서 델리게이트 변수가 필요하다.

먼저 델리게이트 변수를 선언하고, 그 변수에다가 무명 메소드를 참조하게 하는것이다.

> ### 예제
```cs

delegate int MyDelegate(int a, int b);

public static void main()
{
    MyDelegate add;

    //무명 메소드 참조
    add = delegate(int a, int b)
    {
        return a + b;
    };
    Console.WriteLine(add(11, 22));
}
//33
```
델리게이트로 무명메소드를 참조하면 함수내에서 얼마든지 호출해서 쓸수 있다.

무명 메소드는 위와 같이 간단한 연산의 메소드를 임시적으로 써야할 때나, 

델리게이트를 다른함수에 넘겨줘서 콜백으로 사용할때도 유용하다.