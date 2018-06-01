# TIL   / 2018-06-01
  ## Unity - Programming Pattern
    ### Mathf < C# >


> Mathf 종류 및 예제
-  
-  
-  
-  

### Mathf.Lerp
> A 부터 B 까지의  T 시간 동안 각도를 부드럽게 회전시킴

"Mathf.Lerp(float A, float B, float Time)"


```
float CurYAngle = Mathf.LerpAngle (transform.eulerAngles.y , target.eulerAngles.y, 5.0f * Time.deltaTime);

```

- Quaternion.Euler

오일러의 법칙이란 3차원 공간의 절대좌표를 기준으로, 물체가 얼마나 회전했는지를 측정하는 방식.
그러나 X,Y,Z 축을 차례로 회전하기 때문에 짐벌락이라는 회전이 멈추는 현상이 생기게 된다. 이를 해결하기 위해 쿼터니언으로 3개의 축을 한번에 회전을 시킨다.
유니티에서도 transform.Rotate 와 같은 회전을 자동을 쿼터니언 화 시켜준다.
만약 rotation 을 쓴다면 Quaternion q =  Quaternion.Euler 를 이용해서 오일러를 쿼터니언화 시켜준후 사용한다.

### 사용 예제

>카메라 추적을 통한 예제.

```
public Transform target; // 추적할 타겟의 transfoam;
    public float dist = 10.0f; // 카메라와 타겟의 일정거리
    public float height = 5.0f; // 카메라의 높이 설정
    public float smoothRotate = 5.0f;

    private Transform tr; // 카메라의 Transfoam;

    private void Awake()
    {
        target = GameObject.FindGameObjectWithTag("Player").transform;
        tr = this.gameObject.transform;
    }

    //fixedUpdate = 0.02초 간격으로 불러줌. 물리에 주로 사용
    //Update = 일반적. 일정하지않아 물리에 사용시 충돌이 안될수도 있음
    //LateUpdate = 위 두 Update 가 불러지고 나서 호출,
    // 카메라에 사용시 오브젝트가 먼저 움직이고 나서 움직여서
    // 자연스러운 효과를 낼수있다.

    private void LateUpdate()
    {
        // 부드러운 회전을 위한 Mathf.LerpAngle
        float curYAngle = Mathf.LerpAngle(tr.eulerAngles.y, target.eulerAngles.y, smoothRotate * Time.deltaTime);

        //오일러 타입을 쿼터니언 으로 전환
        Quaternion rot = Quaternion.Euler(0, curYAngle, 0);

        //카메라의 위치를 타켓 회전 각도만큼 회전후 dist만큼 띄우고
        // 높이를 올림
        //타겟 포지션 값 - (타겟의 회전을 따라잡는 rot 변수 * Z방향 * 띄울 거리) - (Y방향 * 띄울 높이)
        tr.position = target.position - (rot * Vector3.forward * dist)
            + (Vector3.up * height);

        //카메라가 타켓을 바라보게 하기
        tr.LookAt(target);

    }

```
###
> Expain shortly

설명


```
Typing Code

```
