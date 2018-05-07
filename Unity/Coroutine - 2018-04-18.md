# TIL   / 2018-04-18
  ## Unity
    ### Coroutine < C# >



1. 코루틴은 실행을 일시중지 하고 Untiy에 제어권한을 반환 한후 다음 프레임에서 중단 했던 위치에서 계속 할수 있는 함수 와 같다.

2. 함수를 호출하면 값이 반환하기 전에 실행이 완료됨. 즉, 함수의 액션이 하나의 프레임 업데이트 내에서 발생해야 한다는 것을 의미함.

3. 따라서 절차식 애니메이션이나, 시간 간격을 두고 실행하는 함수 만들었을때를 고려해야 한다.

4. 물론 Update 함수에 추가하여 사용하는것이 가능하지만. Couroutine 이 편리하다고함.

5.  Update 가 Coroutine 보다 2배이상 빠르다고 한다. (https://sunhyeon.wordpress.com/2012/11/20/376/) 참고
    따라서  매 프레임마다 불러올때는 Update를 사용하고 그렇지 않다면 Couroutine 사용하자.

### C#
>아래는 시간에 따라 점차적으로 알파값을 줄이는 함수이다.
코루틴을 사용하면 코루틴의 동안 모든 변수 혹은 파라미터가 올바르게 보존된다.

```
//알파값을 을 줄이는 함수.

IEnumerator Fade(){
  for (float f = 1f; f >=0; f-=0.1f)
  Color c = renderer.material.color;
  c.a = f;
  renderer.marerial.color = c;
  yield return null;

// 실행 할때는 StartCoroutine("함수명");

void Update()
{
  if (Input.GetKeyDown("f"))
  {
    StartCoroutine("Fade");
  }
}
```

### WaitForSeconds

```
// 0.1초의 지연시간을 준다.

IEnumerator Fade()
{
  for (float f = 1f; f >= 0; f -= 0.1f)
  {
    Color c = renderer.material.color;
    c.a = f;
    renderer.material.color = c;
    yield return new WaitForSeconds(.1f);
  }
}
```
코루틴에 시간지연을 도입하여 사용할수도 있다.
아래와 같은 방법은 효과를 전파하는 ( 스플래쉬 데미지 와 같은 ) 방법으로 사용할수도 있지만,  유용한 최적화 이기도 하다.

Update 함수는 초당 여러번 호출이 되기때문에 자주 반복할 필요가 없는 경우 코루틴에 넣을수 있다.

### (추가 설명)
1.  Update 함수는 매프레임 마다 호출되며 60fps 의 경우라면 초당 60번이 호출이 된다.

2.  만약 하나의 프레임 에 한하는 코드라면 Update 에 사용하면 되겠지만, 몇초 이상 을 적용해야 하는 코드라면 (예를 들어 오브젝트를 생성하는 경우라면, ) 후에 성능에 따라 프레임이 떨어질수 밖에없다.


>예를 들어 적이 근처에 있을경우 플레이어에게 알람을 주는 경보가 있다고 하자,
```
Function ProximityCheck()
{
  for (int i =0; i < enemies.Length; i++)
  {
    if (Vector3. Distance(transform.position,
          enemies[i].transform.position)) < dangerDistance)
          {
            return true;
          }

    return false;
  }
}
```

 >이 함수를 Update 함수에 넣고 실행하면 상당한 오버헤드가 발생할수도 있다.
 이를 최적화 하기 위해서 코루틴을 사용하여 10분의 1초마다 호출되도록 하자.

```
 IEnumerator DoCheck()
 {
   for(;;)
    ProximityCheck;
    yield return new WaitFor Seconds(.1f);
 }
```

### 나의 경우

디펜스 게임을 만드는 도중 일정시간 동안 데미지를 주는 코드를 짜던 도중 코루틴을 사용하게 되었다.

>C#의 문법으로 사용함.

```
//트리거에 적이 들어와서 발사체 "Fire"와 닿았을때, 화염이펙트 생성
딜레이 함수에 코루틴 적용//

private void OnTriggerEnter2D(Collider2D collision)
   {
       if (collision.tag == "Fire")
       {
           Instantiate(FlameEffect, transform.position, Quaternion.identity, transform);
           StartCoroutine(Delay());
       }
   }

//1초간 기다렸다가, Hp바와 적의 Hp를 감소 시킨다.

   IEnumerator Delay()
   {
       yield return new WaitForSeconds(1);
       Hpbar Hp = this.GetComponentInChildren<Hpbar>();
       Damage(1);
       Hp.HpMinus(1);
       yield return new WaitForSeconds(1);
       Damage(1);
       Hp.HpMinus(1);
       yield return null;
   }
```

### IEnumerator & Yield

### 추가설명
코루틴

싱글쓰레드를 쓰면
애니메이션과 같은
애니메이션을 쓸수가 없다

그렇기 위해서 쓰레드를 사용한다

동시에 여러가지 일을 하는것이다.
쓰레드로 쓰면 풀보다는 속도는 느릴수도 있지만
예를 들어서 파일을 다운받을때, 다운진행률을 표시를 하고 받는작업을 동시에 하는 것이다.

하지만 매우 큰 단점이 있는데,
예를 들어서 파일을 열어놓고 수정하면  한자원을 같이 사용하기 때문에 충돌이 난다.

게임의 경우에도 많은 자원중에 한 자원을 쓰면 충돌이 나기 때문에 안전장치가 필요하다
크리티컬 섹션 과 같은.

쓰레드로 쓰면 어떤 자원이 언제 접근할지 모르기 때문에 난이도가 올라갈수밖에 없다.

유니티에서는 코루틴이 있다.
예를 들어서 일정 부분을 먼저 사용하고 이후 후에 다른 작업을 쓴다.

우리가 만든 로드 제이슨을 보자.
이때 자원이 많으면 사람들이 지루하기에
코루틴을 써서 로딩화면을 만들어 본다.

yield return 을 실행하면
업데이트 한프레이 돌고 리턴까지 실행을 한다.

쓰레드랑은 조금 다르게
자원을 나누어서 순서에 따라 작업을 하는것,
