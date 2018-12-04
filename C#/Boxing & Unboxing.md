# TIL   / 2018-06-01
    ## Boxing & Unboxing < C# >
 

#### Boxing 
```cs
class TestBoxing
{
    static void Main()
    {
        int i = 123;
 
        // Boxing copies the value of i into object o.
        object o = i;  
 
        // Change the value of i.
        i = 456;  
 
        // The change in i does not effect the value stored in o.
        System.Console.WriteLine("The value-type value = {0}", i);
        System.Console.WriteLine("The object-type value = {0}", o);
    }
}
/* Output:
    The value-type value = 456
    The object-type value = 123
*/
출처: http://kimjh0727.tistory.com/entry/C-Boxing과-Unboxing의-고찰 [Open-Closed Principle]
```

object 형태의 리스트 에서 int 형 변수를 넣으면 ``AutoBoxing`` 이 되어서 object 형태로 형변환이 됨.

C# 에서 Int32 와 같은 묶어놓은 구조체를 박싱이라고 함.

박싱은 자료형을  오브젝트를 상속 받아서 쓰는것이고 오브젝트 형으로 만드는것이 박싱이고, 

언박싱은 오브젝트 형을 다른 자료형으로 만드는것을 언 박싱이라고 한다.

#### unBoxing 
```cs
List<int> mList = new List<int>

```
C, C++ 에서