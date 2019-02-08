<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [TIL   / 2018-11-27](#til----2018-11-27)
- [Delegate < C# >](#delegate--c-)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# TIL   / 2018-11-27

  # Delegate < C# >
>## 델리게이트

델리게이트는 메소드를 참조하는 변수이다.

C++ 의 함수 포인터와 비슷하기 하다고한다. 난 안써봐서 모르겠지만..

아무튼 예제를 보자

> 1.참조할 메소드와 동일한 타입의 델리게이트 타입을 선언.

```cs
//델리게이트                // 참조할 함수타입(매개변수)
delegate void typeA(int); //  void methodA(int)
delegate float typeA(float); //  float methodB(float)
delegate string typeA(int); //  string methodC(int)
delegate void typeA(int); //  void methodD(int)
```

> 2.선언한 델리게이트 타입생성

```cs
typeA delegate0;
typeB delegate1;
typeC delegate2;
typeD delegate3;

delegate0 = new typeA(methodA);
delegate1 = new typeB(methodB);
delegate2 = new typeC(methodC);
delegate3 = new typeD(methodD);
```

> 3.예제 프로그램

```cs
delegate int MyDelegate(int a, int b);

public int Plus(int a, int b) {return a + b;}
public int Minus(int a, int b) {return a - b;}

Mydelegate calculate;

calculate = new MyDelegate(Plus);
Console.WriteLine("2 + 3 = {0}", calculate(2, 3));
//2 + 3 = 5

calculate = new MyDelegate(Minus);
Console.WriteLine("2 - 3 = {0}", calculate(2, 3));
//2 - 3 = -1
```

> ### 콜백 메소드

콜백이란 메소드 A를 호출할때 B 메소드를 넘겨주어서,

A 메소드 안에서 B메소드를 호출하도록 하는것을 말하며, 

이때 
A 메소드를 콜백 메소드라고 한다.

이과정에서 매개변수로 받은 델리게이트로 B 메소드를 호출한다.

```cs
delegate int MyDelegate(int a, int b,);

public int Plus(int a, int b) {return a + b;}
public int Minus(int a, int b) {return a - b;}
public int mulitply(int a, int b) {return a * b;}

public void calculate(int a, int b, MyDelegate dele);

MyDelegate Plus = new MyDelegate(Plus);
MyDelegate Minus = new MyDelegate(Minus);
MyDelegate mulitply = new MyDelegate(mulitply);

calculate(2, 3, plus));
calculate(2, 3, Minus));
calculate(2, 3, mulitply));
//5
//-1
//6
```
> ### 델리게이트 일반화

특정 타입을 선언하지않고, 일반화 하여서 어떤타입의 메소드일지라도 참조 가능하게 만듬

```cs
delegate <T> MyDelegate(T a, t b,); // 타입 T 로 선언

//각각 다른 자료형
public int Plus(int a, int b) {return a + b;}
public float Plus(float a, float b) {return a + b;}
public double Plus(double a, double b) {return a + b;}

public void calculate(int a, int b, MyDelegate dele);

MyDelegate <int> Plus_Int = new MyDelegate<int>(Plus);
MyDelegate <float> Plus_Float = new MyDelegate<float>(Plus);
MyDelegate <double> Plus_Double = new MyDelegate<double>(Plus);

calculate(2, 3, plus)); // int
calculate(2, 3, plus)); // float
calculate(2, 3, plus)); // double
```

> ### 델리게이트 체인

참조할 함수를 여러개를 추가해서 순서대로 불러주는 역할을 함.

델리게이트 변수에 += 로 추가해주고, -= 로 빼준다.

```cs
delegate void delegateChain();

public void methodA(() => Console.WriteLine("1번"));
public void methodB(() => Console.WriteLine("2번"));
public void methodC(() => Console.WriteLine("3번"));

delegateChain delChain;
delChain += methodA;
delChain += methodB;
delChain += methodC;

delChain();
//1번
//2번
//3번

delChain -= methodB;
delChain();

//1번
//3번
```