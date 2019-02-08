<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [TIL   / 2018-08-13](#til----2018-08-13)
- [Interface < C# >](#interface--c-)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# TIL   / 2018-08-13

  # Interface < C# >

>## Interface 
+ 메소드, 이벤트, 인덱서, 속성이 쓰이고, 필드는 포함할수없다.
+ 인터페이스의 모든 멤버는 public 이 기본설정
+ 몸통이 없는 추상 멤버라서 꼭 상속받은 후에 구현을 빠짐없이 할것!
+ C# 은 다중 클래스 상속이 불가능 하며, 인터페이스는 다중 상속이 가능!  
```csharp
interface Interfacename
{
    void something();
}
```
>## 예제1 - 기본적인 사용법
> 참고 :  http://blog.eairship.kr/148 
```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
    
    //인터페이스 A,B 정의
    interface IMyInterface_A
    {
        void print();
    }
 
    interface IMyInterface_B
    {
        void print();
    }
    
    // 메인클래스 : 인터페이스 상속
    class MyClass : IMyInterface_A, IMyInterface_B
    {
        static void Main(string[] args)
        {
            MyClass mc = new MyClass();
             
            IMyInterface_A interfaceA = mc;
            IMyInterface_B interfaceB = mc;
            
            interfaceA.print();
            interfaceB.print();
 
        }
    
    //인터페이스 구현부
        void IMyInterface_A.print()
        {
            Console.WriteLine("IMyInterface_A.print() 호출.");
        }
 
        void IMyInterface_B.print()
        {
            Console.WriteLine("IMyInterface_B.print() 호출.");
        }
    }
/// 결과
/// IMyInterfaceA.print() 호출.
/// IMyInterfaceB.print() 호출.
```

>## 예제2 - 부모 인터페이스와 자식 인터페이스
+ 인터페이스가 인터페이스를 상속해서 사용가능
```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
    
    //부모 인터페이스
    interface ParentInterface
     {
         void ParentMethod(string str);
     }

    //자식 인터페이스 : 부모인터페이스
    interface SubInterface : ParentInterface{
         void SubMethod(string str, int i);
     }

    // 클래스 : 자식인터페이스 상속
     class MyClass : SubInterface
     {  
         // 부모 인터페이스 메소드 구현
         public void ParentMethod(string str)
         {
             Console.WriteLine(str +"ParentInterface.ParentMethod() Call!");
         }

        // 자식 인터페이스 구현
         public void SubMethod(string str, int count)
         {
            for (int i = 0; i < count; i++)
            {
               Console.WriteLine(str + " SubInterface.SubMethod() " + i + " call!");
            }
 
         }
     }

     class Program
     {
         static void Main(string[] args)
         {
             MyClass mc = new MyClass();

             mc.ParentMethod("Interface");
             mc.SubMethod("Inherits, 3");
         }
     }

/// 결과
///Interface ParentInterface.ParentMethod() call!
///Inherits SubInterface.SubMethod() 0 call!
///Inherits SubInterface.SubMethod() 1 call!
///Inherits SubInterface.SubMethod() 2 call!
///Inherits SubInterface.SubMethod() 3 call!
```