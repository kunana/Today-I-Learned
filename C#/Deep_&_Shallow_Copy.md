<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [TIL   / 2018-08-20](#til----2018-08-20)
- [Deep & Shallow Copy < C# >](#deep--shallow-copy--c-)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# TIL   / 2018-08-20

  # Deep & Shallow Copy < C# >

<br>

>## Assign
생성된 객체를 다른 변수로 참조할 경우 assign 한다 라고 한다.
```csharp
class World
{
    string world = "My World";
}

World newWorld1 = new World();
World newWorld2 = new World1;
```
1. 두 클래스는 같은 Object의 주소 값을 가지게 된다.
2. 이때 newWorld2 의 멤버의 값을 바꾸면 newWorld1 멤버의 값도 바뀌게 될것이다.
3. 물론 변경 가능한 (mutable)일때만, 숫자나, 문자열, 클래스 와 같은 immutable 객체가 아닐때만.

<br>

>## Copy
- 객체의 복사라고 함은, 기존 객체와 같은 값을 가지는 새로운 객체를 만드는것이다
- 객체는 멤버(필드)를 가진다. 멤버는 값 형식, 혹은 참조 형식일수 있다.
- 객체가 가진 값 형식(Value Type) 과 참조 형식(Reference Type)의 복제 방식에 따라 깊은 복사 혹은 얕은 복사로 나뉜다.

<br>

>## 얕은 복사 (Shallow Copy)
1. 단순 복사
2. 객체가 가진 멤버의 값들을 새로운 객체로 복사를 하는데, 만일 객체가 참조타입의 멤버를 가지고 있다면 참조값만 복사된다. 
3. Object 클래스의 MemberwiseClone() 메서드를 이용해서 얕은 복사를 해보자.
```csharp
// MemberwiseClone()

//사용할 클래스
class Earth
{
    public string name; //Value Type 의 멤버
    public int coordinate;
     
    public Human human; //Reference Type 의 멤버

    
    public object Shallow_Copy() //C# 의 모든 데이터 타입은 object를 상속 받는다.
    {   
        //얕은복사 Method
        return this.MemberwiseClone(); //protected Type
    }
}
class Human // 참조형식의 클래스
{
    public string name;
    public int age {get; set;};
}


static void Main(string[] args) //메인
{
    
    Earth earth = new Earth(); //원본 Object(class Earth)
    earth.name = "지구"
    earth.coordinate = 42;
    earth.human = new Human();
    earth.human.name = "철수"
    earth.human.age = 10;

    
    Earth mars = (Earth)earth.Shallow_Copy(); //얕은 복사된 객체
    mars.Name = "화성";  
    mars.coordinate = 82;
    mars.human.name = "영희" //(객체안 참조타입 멤버는 참조값이 복사됨)
    mars.human.age = 22;

    Write(earth);
    Write(mars);
}
void Write(Earth earth)
{
    Console.WriteLine(string.format("이름 : {0}, 좌표 : {1}, 사람이름: {2}, 나이 : {3}", 
    earth.name, earth.coordinate, earth.human.name, earth.human,age));
}
//결과 
//"이름 : 지구, 좌표 : 42, 사람이름: 영희, 나이 : 22";
//"이름 : 화성, 좌표 : 82, 사람이름: 영희, 나이 : 22";

```
mars 는 새로운 객체 이지만, 원본 객체에 있는 참조 형식은 복사되지 않고,

새로운 값을 복사해도 참조 형식은 원본값 까지 변경되어진다.
```
얕은 복사 (단순 복사) - MSDN

단순 복사본은 원본 개체와 같은 형식의 새로운 인스턴스를 만든 다음 원본 개체의 비정적 필드를 복사합니다. 필드가 값 형식인 경우 필드의 비트별 복사가 수행됩니다. 필드가 참조 형식인 경우 참조는 복사되지만 참조되는 개체는 복사되지 않습니다. 따라서 원본 개체 안의 참조와 복제 안의 참조가 동일한 개체를 가리킵니다
```

<br>

>## 깊은 복사
1. 전체 복사
2. 객체가 가진 모든 멤버가 복사됨.
3. 객체가 참조 타입을 가지고 있을때, 전혀 다른 객체가 되도록 복사.
4. 깊은 복사를 위한 인터페이스, ICloneable() 의 Clone() Method 를 사용해보자
```csharp 
// interface ICloneable, Clone()

//ICloneable 을 상속 해주자.
//자신의 멤버값을 그대로 대입후 새로운 Earth 객체를 생성후 반환 해준다.
//이때 참조 멤버인 Human 객체 또한 new 로 완전히 새로운 객체로 생성하는것이 핵심!
public object Clone()
{
    
    Earth earth = new Earth();          //원본 Object(class Earth)
    earth.name = this.name;
    earth.coordinate = this.coordinate;
    earth.human = new Human();          //참조타입은 새로 생성하는게 중요!
    earth.human.name = this.earth.human.name;
    earth.human.age = this.earth.human.age;

    return earth;
}


static void Main(string[] args) //메인
{
    
    Earth earth = new Earth();  //원본 Object(class Earth)
    earth.name = "지구"
    earth.coordinate = 4242;
    earth.human = new Human();
    earth.human.name = "짱아"
    earth.human.age = 5;

    
    Earth mars = (Earth)earth.Clone();  // 깊은 복사
    mars.Name = "화성";
    mars.coordinate = 82;
    mars.human.name = "영희" // 전혀 다른 객체 이므로 새로운 값이 할당
    mars.human.age = 22;

    Write(earth);
    Write(mars);
}
void Write(Earth earth)
{
    Console.WriteLine(string.format("이름 : {0}, 좌표 : {1}, 사람이름: {2}, 나이 : {3}", 
    earth.name, earth.coordinate, earth.human.name, earth.human,age));
}
//결과 
//"이름 : 지구, 좌표 : 4242, 사람이름: 짱아, 나이 : 5";
//"이름 : 화성, 좌표 : 82, 사람이름: 영희, 나이 : 22";
```
얕은 복사와 달리 참조 형식 또한 전혀 다른 새로운 객체가 되는 것을 볼수있다.
```
ICloneable 의 Clone() 메서드로만 반드시 깊은 복사를 수행해야 하는 것은 아니다..

하지만 .NET 프레임워크와 호환성을 가질수 있다. 

깊은 복사를 가질 클래스가 .NET 프레임워크의 다른 클래스나 다른 프로그래머가 작성한 코드와 

호환되도록 하고 싶다면 ICloneable을 상속하도록 하는 것이 좋다.
```

<br>

>## 프로토 타입 패턴
+ 복사와 관련된 대표적인 디자인 패턴중 하나로, 복사를 통한 객체 생성을 지원,

+ 객체 생성 과정의 캡슐화 및 객체생성의 편리성을 제공하는 기법이다.

```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
    
namespace CSharp_ProtoType_Pattern
{
    abstract class ProtoType
    {
        private string _id;

        public Prototype(string id)
        {
            this._id = id;
        }
        public string Id
        {
            get { _id; }
        }

        public abstract Prototype Clone();
    }

    class ConcretePrototype1 : Prototype
    {
        public ConcretePrototype1(string id) : base(id)
        {

        }

        public override Clone()
        {
            return (Prototype)this.MemberwiseClone();
        }
    } 

    class ConcretePrototype 2 : Prototype
    {
        public ConcretePrototype1(string id) : base(id)
        {

        }

        public override Clone()
        {
            return (Prototype)this.MemberwiseClone();
        }
    } 
    
    class Program {
        static void Main()
        {
            ConcretePrototype1 p1 = new ConcretePrototype1("I");
            ConcretePrototype1 c1 = (ConcretePrototype1)p1.Clone();
            Console.WriteLine("Cloned: {0}", c1.Id);
 
            ConcretePrototype2 p2 = new ConcretePrototype2("II");
            ConcretePrototype2 c2 = (ConcretePrototype2)p2.Clone();
            Console.WriteLine("Cloned: {0}", c2.Id);
 
            Console.ReadKey();
        }
    }    
}
```
