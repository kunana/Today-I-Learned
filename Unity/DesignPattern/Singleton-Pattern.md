# TIL   / 2018-06-01
  ## Unity - Programming Pattern
    ### Singleton < C# >


> 싱글톤패턴은 인스턴스가 사용될때 똑같은 인스턴스를 만들어 내는것이 아닌, 동일 인스턴스를 사용하게끔 하는 것.

- 하나만 사용되는 객체를 만들때, 프로그램상 동일한 커넥션 객체를 만들때,
- 유니티에서는 씬에 게임매니져와 같은 객체 생성후 DontDestroyOnLoad 를 호출, 씬 변경시에도 디스트로이를 막아주는 형태로 구현할수도 있음
- 커플링이 되어 복잡도가 올라갈수도 있다.
-  

### 싱글톤예제1
> 인스턴스를 불러오는 형식, instance 를 호출시..메모리관리에 나쁘다 라는 말이 있으나 아직 정보를 찾지 못함(추가바람)

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



```

### 싱글톤 예제 2
> 싱글톤 클래스만 MonoBehaviour 를 상속 받고, 나머지 클래스 들은 싱글톤을 상속받음

제일처음에 MonoBehaviour where T : MonoBehaviour 는 자기자신의 <T>, 타입을 MonoBehaviour 로 정의해줌.



```
public class Singleton <T> : MonoBehaviour where T : MonoBehaviour
{
  private static T _instance;
  public static instance
  {
    get
    {
      if(_instance == null)
      {
        _instance = FindObjectofType (typeof(T)) as T;
        if(_instance == null)
        {
          Debug.LogError("There is no active SingletonClass object");
        }
      }
        return _instance;
    }
  }
}

// 다른클래스에서의 상속할때
public class Player : Singleton<Player>
{

}

// 상속 후 사용 할때
public class Enemy : Singleton<Enemy>
{

  private Player playerClass;

  void Start()
  {
    PlayerClass = Player.instance;
  }

  void update()
  {
    PlayerClass.move();
  }
}

```

### 싱글톤 예제3

> 유니티내에서 게임 매니져를 만들어주고,  다른씬에서도 삭제되지않고 사용가능하도록 만든것, (사용해봐야함)

```
using UnityEngine;
using System.Collections;

public class GameManagerExample : MonoBehaviour
{
    private static GameManagerExample instance = null;
    private void Awake()
    {
        if (instance == null)
            instance = this;
        else if (instance != this)
        {
            Destroy(gameObject);
        }

        DontDestroyOnLoad(gameObject);

        InitGame();
    }
    public void InitGame()
    {

    }
}
```
