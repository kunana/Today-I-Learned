<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [TIL   / 2018-04-19](#til----2018-04-19)
  - [C](#c)
    - [기본 양식](#%EA%B8%B0%EB%B3%B8-%EC%96%91%EC%8B%9D)
    - [설명](#%EC%84%A4%EB%AA%85)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# TIL   / 2018-04-19
  ## C#
    ### Get, Set < C# >



> 객체지향언어에서의 캡슐화(정보은닉) 을 위해, 혹은 확장성의 증가,

- 클래스나 구조체 내의 변수를 클래스/구조체 속에서만 사용하게 끔 private 으로 선언하였을시, 이 함수를 사용하여 여러함수에서 읽기전용/쓰기전용, 혹은 읽기/쓰기 로 사용할수있다.
- 디버그에 용이하다
- 변경 전에 유효성을 검사하는 용도로. 혹은 데이터 변경시에 이벤트 발생이나, 원하는 값만 입력하게끔 하거나, 다른 코드를 수행할수 있다.
- 함수로 하여금 다른 클래스에서도 활용할수있다.

### 기본 양식
> 전역에서 만들어줌

```
class  ClassName
{
  private DataType _var;
  public DataType var;
  {
      get
      {
        return _var;
      }
      set
      {
        _var = value;
      }
  }

}
```

> Ex)

```
class  Student
{
  private int _Age;  // field
  public DataType Age; // property
  {
      get {return _Age;}
      set {_Age = value;}
  }
}

class Program
{
  static void Main()
  {
    Student student = new Student();
    student.Age = 15;

    Console.WriteLine("나이는 + student.Age");
  }
}

```
### 설명

private 으로 Field  (객체의 내부정보),
퍼블릭으로 Property  (내부정보를 외부로 노출해 주는 방식)

먼저 get 접근자를 보자면, 필드의 값을 읽어준다.
>get접근자를 불러 줌으로써 필드의 값을 리턴받는다.
```
// get 접근자
Student student = new Student();

System.Console.Write(student.Age);
```

Set 접근자는 반환형식이 void 메서드와 비슷하다.
아래의 value 는 유니티의 var 와 같이 암시적인 매개 변수를 사용한다.
또한 값을 할당할때에는 Property 값에 할당을 해준다.

```
Student student = new Student();

student.Age = 19;
System.Console.Write(student.Age);
```

### 인스턴스, 정적 및 읽기 전용속성의 예제

> 키보드에서 직원 이름을 받고 NumberOfEmployees를 1만큼 증가한 다음 직원 이름과 번호를 표시한다.

```
public class Employee
{
    public static int NumberOfEmployees;
    private static int _counter;  // field
    private string _name;  //field

    // A read-write instance property:
    public string Name
    {
        get { return _name; }
        set { _name = value; }
    }

    // A read-only static property:
    public static int Counter
    {
        get { return _counter; }
    }

    // A Constructor:
    public Employee()
    {
        // Calculate the employee's number:
        _counter = ++_counter + NumberOfEmployees;
    }
}

class TestEmployee
{
    static void Main()
    {
        Employee.NumberOfEmployees = 107;
        Employee e1 = new Employee();
        e1.Name = "철수";

        System.Console.WriteLine("Employee number: {0}", Employee.Counter);
        System.Console.WriteLine("Employee name: {0}", e1.Name);
    }
}
/* Output:
    Employee number: 108
    Employee name: 철수
*/

```

### 파생클래스에서의 사용
>
```
public class Employee
{
    private string name;
    public string Name
    {
        get { return name; }
        set { name = value; }
    }
}

public class Manager : Employee
{
    private string name;

    // Notice the use of the new modifier:
    public new string Name
    {
        get { return name; }
        set { name = value + ", Manager"; }
    }
}

class TestHiding
{
    static void Main()
    {
        Manager m1 = new Manager();

        // Derived class property.
        m1.Name = "John";

        // Base class property.
        ((Employee)m1).Name = "Mary";

        System.Console.WriteLine("Name in the derived class is: {0}", m1.Name);
        System.Console.WriteLine("Name in the base class is: {0}", ((Employee)m1).Name);
    }
}
/* Output:
    Name in the derived class is: John, Manager
    Name in the base class is: Mary
*/
```

- 다음은 앞의 예제에서 중요한 사항입니다.

파생 클래스의 Name 속성은 기본 클래스의 Name 속성을 숨깁니다. 이러한 경우 new 한정자는 파생 클래스의 속성 선언에 사용됩니다.

```
public new string Name
```

- (Employee) 캐스트는 기본 클래스의 숨겨진 속성에 액세스하는 데 사용됩니다.
```
((Employee)m1).Name = "Mary";
```
