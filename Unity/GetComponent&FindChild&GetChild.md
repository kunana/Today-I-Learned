# TIL   / 2018-05-07
  ## Unity
    ### 컴포넌트 혹은 게임오브젝트를 불러오기 < C# >


> getComponent, getComponentInParent, getComponentInChild, Function 으로 불러오기
-  게임오브젝트에 있는 컴포넌트를 불러오기.
-  다른 스크립트에 있는 변수를 불러오거나 값을 할당.
-
-

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

> 다른 스크립트에 포함된 컴포넌트, 메소드, 변수 불러오기
1. 스크립트에 public gameobject = null 선언 후 인스펙터에 추가하기.
2. 게임오브젝트에 할당되어있는 Tag 찾아서 불러오기
3. 싱글톤으로 만들어진 스크립트 에서  public 으로 선언된 메소드나 변수를 불러오기
4. public static Class contents = null;  --> Start 단에서 contents = this;

+ Start에서 비활성화 된 오브젝트는 상속 되어 있는 Parent GameObject 에서 찾아서 Active 시켜야함.

1.  스크립트에 public gameobject = null 선언 후 인스펙터에 추가하기
```
// 인스펙터에서 추가하거나,
public GameObject Object = null;
  public Canvas canvas = null;
// Use this for initialization
void Start () {


}
```
2. 게임오브젝트에 할당되어있는 Tag 찾아서 불러오기
```
// 인스펙터에서 추가하거나,
public GameObject Object = null;
  public Canvas canvas = null;
// Use this for initialization
void Start () {

  Object = GameObject.FindGameObjectWithTag("Tag");

// Object 와 Objects 의 식별에 유의한다.
  GameObject[] Canvas = GameObject.FindGameObjectsWithTag("Tag");
}

```
Typing Code

```
