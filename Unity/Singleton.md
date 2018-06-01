# TIL   / date
  ## Unity - Programming Patten
    ### Singleton < C# >


> 싱글톤패턴은 인스턴스가 사용될때 똑같은 인스턴스를 만들어 내는것이 아닌, 동일 인스턴스를 사용하게끔 하는 것.

- 하나만 사용되는 객체를 만들때, 프로그램상 동일한 커넥션 객체를 만들때,
- 유니티에서는 씬에 게임매니져와 같은 객체 생성후 DontDestroyOnLoad 를 호출, 씬 변경시에도 디스트로이를 막아주는 형태로 구현함.
-  
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
    private int Number = 0;


```

### C#
> Expain shortly

설명


```
Typing Code

```
