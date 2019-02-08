<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [TIL   / 2018-05-07](#til----2018-05-07)
  - [Unity](#unity)
    - [C](#c)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# TIL   / 2018-05-07
  ## Unity
    ### 컴포넌트 혹은 게임오브젝트를 불러오기 < C# >


> getComponent, getComponentInParent, getComponentInChild, Function 으로 불러오기
-  게임오브젝트에 있는 컴포넌트를 불러오기.
-  다른 스크립트에 있는 변수를 불러오거나 값을 할당.
-  상속되어 있는 경우 어떤 GameObject에 상속되어있는지 확인할것.
-  GameObject.FInd 의 경우는 씬 전체에서 찾는다. 특히 Update 단에서 Find 는 매프레임마다 호출되기때문에 주의, 특히 모바일에서는 더더욱 주의

### C#
> Start 나 Awake 단에서 불러올 컴포넌트를 미리 할당해준다.

```
// 예제 코드
// 이 스크립트가 포함된 게임 오브젝트 안의 컴포넌트 중에서 Transform 을 추출하여 myTranform 에 저장.
Void Start()
{
  Transform myTranform = getComponent<Transform>();

  Transform myTranform = gameobject.getComponent<Transform>();

  Transform myTranform = (Transform).getComponent("Transform")();

  Transform myTranform = (Transform).getComponent(typeof(Transform));
}
```

> 다른 스크립트에 포함된 컴포넌트, 메소드, 변수 불러오기
1. 스크립트에 public gameobject = null 선언 후 인스펙터에 추가하기.
2. 게임오브젝트에 할당되어있는 Tag 찾아서 불러오기
3. 싱글톤으로 만들어진 스크립트 에서  public 으로 선언된 메소드나 변수를 불러오기
4. public static Class contents = null;  --> Start 단에서 contents = this;

+ Start에서 비활성화 된 오브젝트는 상속 되어 있는 Parent GameObject 에서 찾아서 Active 시켜야함.

1.  스크립트에 public gameobject = null 선언 후 인스펙터에 추가하기

```
// 아래 스크립트를 추가한 후에 인스펙터에서 추가하거나,
public GameObject Object = null;
  public Canvas canvas = null;


void Start () {
}
```

2. 게임오브젝트에 할당되어있는 Tag  혹은 이름으로 찾아서 불러오기

```

public GameObject Object = null;
  public Canvas canvas = null;

void Start () {

  Object = GameObject.FindGameObjectWithTag("Tag");

  Object - GameObject.Find("Name");

// Object 와 Objects 의 식별에 유의한다. Objects 는 배열로 불러준다.
  GameObject[] Canvas = GameObject.FindGameObjectsWithTag("Tag");
}
```
3.  부모 게임오브젝트에 상속되어 있는 게임오브젝트 속 컴포넌트 찾기.

```
void Start () {
      //게임오브젝트 이름으로 찾기
      var Parents = GameObject.Find("Parent");

      // 태그로 찾기

      var Parents_Tag = GameObject.FindGameObjectWithTag("Parent");

      //부모오브젝트에서 자식오브젝트 찾기
      var Child = this.gameObject.GetComponentInChildren<Transform>();
      var Child_GameObject = Parents.GetComponent<Transform>();
      var Child_0 = Parents.transform.GetChild(0);

      // 활성화 되어있는 오브젝트에서만 찾아주기에 주의
      var Child_1 = Parents.transform.Find("Child_1");

      //자식오브젝트에서 부모 컴포넌트 찾기
      var Parents_GetComponents = this.gameObject.GetComponentInParent<Transform>();



      //(추가) Start 단에서 비활성화된 오브젝트일때, 만약 부모객체가 있다면, 부모객체를 먼저 찾은뒤에 엑티브.
      var ActiveChild = GameObject.FindGameObjectWithTag("Parent").transform.Find("Child");

      ActiveChild.gameObject.SetActive(true);

      // 부모객체가 없다면?  하지만 성능저하의 가능성이 크므로 주의.
      var inActiveChild = GameObject.FindGameObjectsofTypeAll(Type typename);
}
```
3. 싱글톤으로 만들어진 스크립트 에서  public 으로 선언된 메소드나 변수를 불러오기
```
public class test : MonoBehaviour {
    public test instance
    {
        get
        {
            if(_instance == null)
            {
                _instance = new test();
            }
            return  _instance;
        }
        set
        {
            _instance = value;
            Number = 1;
        }
    }
    private test _instance = null;
    private int Number = 0;

	void Update () {

        test newTest = new test();
        var getNumber = newTest.instance.getNumber();

	}

	int getNumber()
    {
        return Number;
    }
}
```

4. public static Class contents = null;  --> Start 단에서 contents = this;

```
public test contents = null;
    private int Number = 0;

	void Start () {

        contents = this;

	}

    void Update()
    {
       var GetNumber = test.contents.getNumber();
    }
    int getNumber()
    {
        return Number;
    }
```

5. 메인 카메라의 경우
