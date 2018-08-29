># AOS 개발일지
>## 2018 - 07 - 01 ~  
>## 부산게임아카데미

># 7월초 시작 부터 8월 22일 까지의 일지


># 8월 22일자

> ### 오늘 했던 작업
1. 사용자 정의 게임 씬 작업 완료
2. 챔피언 선택 씬 작업 시작
로비 씬 부터 사용자 선택 씬, 챔피언 선택 씬 까지 사용하는 코드, 컴포넌트가 거의 똑같아서 무난하게 진행

>### 내일 할일 
### 작업중인 씬 => 챔피언 선택룸
1. 우리팀이 무조건 왼편 리스팅 되도록 
2. 챔피언 선택시. 다른사람 클릭 못하게
3. 영웅 선택은 한번만 되도록
4. 선택 시간 끝났을때, 선택한 챔피언의 아트 가 나오게.
5. 추가로 5초의 정비시간 추가 (원래는 스킨 선택 시간.)
6. 시간 끝나면 게임 시작
7. 만약 사람이 나가면 현재 있는 방 삭제 후 로비로 이동
8. 스펠 선택창,스펠 1,2 선택시 바로 미리보기 화면으로 적용되도록
9. 스펠 순서 변경
10. 상대방이 선택한 챔피언 스펠 실시간으로 보여주기
11. 내가 챔피언 고를때 챔피언 아트 바뀌기

># 8월 23일자

> ### 오늘 했던 작업
1. 우리팀이 무조건 왼편 뷰포트에 리스트업, 적팀은 오른쪽에 리스트업

 -> 생성 되어진 프리팹을 할당 안해줘서 헤매다가 발견함...
2. 추가로 5초의 정비시간 추가 (원래는 스킨 선택 시간.)
3. 시간 끝나면 게임 시작

>### 내일 할일 
### 작업중인 씬 => Selection.scene

챔피언 선택할때 각 팀 별로 RPC를 전송해야하는데, 그룹화 전에 RPC부터가 잘 안되었음. 스위치 전환도 잘 안되었고.
그래서 다른 작업도 다 밀려버림

1. 챔피언 선택시. 다른사람 클릭 못하게
2. 영웅 선택은 한번만 되도록
3. 선택 시간 끝났을때, 선택한 챔피언의 아트 가 나오게.
4. 만약 사람이 나가면 현재 있는 방 삭제 후 로비로 이동
5. 스펠 선택창,스펠 1,2 선택시 바로 미리보기 화면으로 적용되도록
6. 스펠 순서 변경
7.  상대방이 선택한 챔피언 스펠 실시간으로 보여주기
8.  내가 챔피언 고를때 챔피언 아트 바뀌기

># 8월 24일자

> ### 오늘 했던 작업
어제 못한 RPC 작업하면서 테스타 하다보니, Room.scene 에서 다른 팀으로 이동하는걸 동기화 안한걸 발견..

1. Room.Scene 에서 팀변경 시 다른 클라이언트에서도 동기화 완료
2. Selection.Scene 에서 팀별로 챔피언 선택 RPC 동기화 완료

#### ChampionButton.cs
-> 팀별로 주고 받는 구간은 RaiseEvent 로 그룹을 지정해서 주는 방법도 있었으나, 익숙 치가 않아서, 일단 포튼 플레이어 배열을 팀별로 가지고 만들고, PhotonMessageInfo() 라는 RPC 파라미터 로 RPC Sender를 확인 할수있어서 Sender 와 로컬 클라이언트의 팀이 같으면 메세지를 받는걸로 하였음.

#### SelectListing.cs
-> Selection.Scecne 에서 자신이 팀이 왼편에 오도록 정렬할때 버그 발생함. CurrentTeam 과 각 플레이어들의 PunTeam.Team을 구분하는 데, PhotonPlayer 가 가지고 있는 PunTeam.Team 의 코드상으로 같으나 구분 못하는거 보니 CurrentTeam이 Null 이 뜨는듯.
-> 스타트 부터 로컬 플레이어 리스트 를 먼저 생성한 다음, 그뒤에 로컬 이외의 플레이어 리스트를 가지고 for 문을 돌려서 로컬플레이어와 비교후 팀 분배.



> ## 내일 할일  
> ## 작업중인 씬 => Selection.scene

+ 챔피언 골랐을때, 다른 클라이언트에 해당 플레이어리스트 프리팹에
이름 뜨도록 동기화
-> 생성되지않은 프리팹에 포톤뷰 를 넣어서 쓰면 illegal error.

<br>

> ## -> 생성되지 않은 프리팹을 쓸때 포톤뷰를 넣고 프리팹 자체를 Observed Components 에 넣어준다 (8월 27일)
> ## 혹은  아래와 같이 ViewID를 할당해준다
```csharp
//PhotonNetwork.AllocateViewID() 메소드를 사용
// 새로운 viewID를 할당해야 하며 이 viewID를 통해 메시지를 전달

void SpawnPlayerEverywhere()
{
    // You must be in a Room already

    // Manually allocate PhotonViewID
    int id1 = PhotonNetwork.AllocateViewID();

    PhotonView photonView = this.GetComponent<PhotonView>();
    photonView.RPC("SpawnOnNetwork", PhotonTargets.AllBuffered, transform.position, transform.rotation, id1, PhotonNetwork.player);
}

public Transform playerPrefab; //set this in the inspector

[RPC]
void SpawnOnNetwork(Vector3 pos, Quaternion rot, int id1, PhotonPlayer np)
{
    Transform newPlayer = Instantiate(playerPrefab, pos, rot) as Transform;

    // Set player's PhotonView
    PhotonView[] nViews = newPlayer.GetComponentsInChildren<PhotonView>();
    nViews[0].viewID = id1;
}
```


에 넣어주고  RPC 사용

-> RPC로 함수 콜해서 바로 컴포넌트 찾으면 OverFlow. 255넘어서 그런듯.

-> 생성되어있는 게임오브젝트에서 RPC 콜 하거나, RaiseEvent 사용해보기.

-> 주말간 RaiseEvent, RPC, OnserializePhotonView 숙달하기.

1. 선택 시간 끝났을때, 선택한 챔피언의 아트 가 나오게.
2. 만약 사람이 나가면 현재 있는 방 삭제 후 로비로 이동
3. 스펠 선택창,스펠 1,2 선택시 바로 미리보기 화면으로 적용되도록
4. 스펠 순서 변경
5.  상대방이 선택한 챔피언 스펠 실시간으로 보여주기
6.  내가 챔피언 고를때 챔피언 아트 바뀌기

<br>

># 8월 27일자

> ### 오늘 했던 작업 -> Selection.scene

> ## RPC 를 이용한 동기화 작업
> 
버튼이 활성/비활성 과 로컬플레이어가 선택하는 챔피언 이름 동기화 중,
버튼 활성/비활성만 되고, 챔피언 이름 동기화가 안되는 버그 발생.

> ## 1.PhotonTarget.All
> 
-> Sends the RPC to everyone else and executes it immediately on this client. Player who join later will not execute this RPC

+ 업데이트 단에서 버튼의 ADDListener를 호출 해버림. 그리고 타겟은
위 옵션을 이용해서 RPC를 사용, StackOverFlow 발생.
호출스택을 사용하여 찾아냄 

+ 모든 대상에게 RPC를 보내서 RPC 함수 호출이 재귀가 되어서 버튼 클릭 한번 동안 업데이트 만큼 (한번 클릭에 71번만큼) 호출. 거기다가 로컬플레이어도 같이 RPC를 받아서 재귀함수 발생. 스택 오버플로우가 발생됨. 

+ AddListener 를 스타트로 옮겨 한번만 실행되도록 하고, 재귀가 안되도록 로컬플레이어는 따로 처리 후, 다른 플레이어만 RPC를 호출

> ## 2.로컬플레이어를 제외한 다른 플레이어 중, 
> 
-> 로컬플레이어와 같은팀에게만 RPC 호출 사용
``` csharp
 for (int i = 0; i < PhotonNetwork.otherPlayers.Length; i++)
 {
   if(PhotonNetwork.player.GetTeam().Equals
   (PhotonNetwork.otherPlayers[i].GetTeam()))
   {
    this.photonView.RPC("switchRPC", PhotonNetwork.otherPlayers[i]);
    this.photonView.RPC("Sync", PhotonNetwork.otherPlayers[i]);
   }
 }
```
+ 버튼 스위치는 호출 되나 챔피언 이름 동기화가 활성화 되지않음.
원인을 찾지 못함. 둘중 하나라도 해보자해서, 챔피언 이름 동기화 RPC만 실행. 디버그 조차도 안됨.

> ## 3.PhotonTargets.AllViaServer

 서버를 통하여, 플레이어 전체에게 호출해보자.  
> 
-> Sends the RPC to everyone (including this client) through the server.

-> This client executes the RPC like any other when it received it from the server.

-> Benefit: The server's order of sending the RPCs is the same on all clients.
> 
``` csharp
 for (int i = 0; i < PhotonNetwork.otherPlayers.Length; i++)
 {
   this.photonView.RPC("switchRPC", PhotonTargets.AllViaServer);
   this.photonView.RPC("Sync", PhotonTargets.AllViaServer);
 }
```
+ 버튼 스위치, 챔피언 이름 동기화 둘다 잘 호출됨. 
byte[] 라서 그런지 한글이 표시 안되었지만 영어로 수정. 잘 동작함.

>## 4. 원래 하던대로 해보자.
```csharp
public void Onclick_Button()
{ 
  //로컬 플레이어
  CurPlayerPrefab = GameObject.Find(PhotonNetwork.player.NickName).gameObject;
  selectlisting = CurPlayerPrefab.GetComponent<SelectListing>();
  selectlisting.ApplyChampion(this.gameObject.name);
  Switch();
  //다른 플레이어 동기화
  for (int i = 0; i < PhotonNetwork.otherPlayers.Length; i++)
  {
    if(PhotonNetwork.player.GetTeam().Equals(PhotonNetwork.otherPlayers[i].GetTeam()))
    {
      this.photonView.RPC("switchRPC", PhotonNetwork.otherPlayers[i]);
      this.photonView.RPC("Sync", PhotonNetwork.otherPlayers[i]);
    }
  }
}
```
+ 잘 동작함... 왜인지 모르겠는데 잘 동작함..

> ## 예외처리 팁 -> 에러메시지 검색.
``` csharp
try
{
    //Somethin that might wrong
}
catch(e)
{
    var xcb = "http://stackoverflow.com/search?q\[c#]+"+e.message;
    window.open(xcb, '_blank');
}
```

>## 내일 할일 
### 작업중인 씬 => Selection.scene

1. 챔피언 선택완료시 그림동기화, 선택 시간 동기화
1. 선택 시간 끝났을때, 선택한 ㄴ챔피언의 아트 가 나오게.
2. 만약 사람이 나가면 현재 있는 방 삭제 후 로비로 이동
3. 스펠 선택창,스펠 1,2 선택시 바로 미리보기 화면으로 적용되도록
4. 스펠 순서 변경
5.  상대방이 선택한 챔피언 스펠 실시간으로 보여주기
6.  내가 챔피언 고를때 챔피언 아트 바뀌기
7.  위 작업 끝나면 UI 변경.

># 8월 27일자

> ## 오늘 했던 작업 -> Selection.scene

+ ## 챔피언 그림 PointerOver 시 그림 바뀌게 -> EventTrigger 사용 하여 완료

+ ## RPC 챔피언 그림, 이름 동기화 완료 -> 챔피언 선택시간 안 맞는 버그 발생

+ ## 챔피언 선택시 챔피언 아트 나오게 함

+ ## 타이틀 씬 교체중 -> 기본적 회원가입, 로그인 이외 추가적인 기능은 더 살펴봐야할듯

+ ## 스펠 선택 및 동기화 작업중 -> 기본적 할당 및 순서 변경은 완료. 동기화는 Raise Event 작업중

+ ## 인스턴스화 안된 프리팹 의 ViewID 를 할당하는 법 찾아야할듯. RPC.md 에서 작성한대로 해봐도  ViewID 가 0.

+ ## 로고 수정

+ ## 로고 의 Shine 효과 나는 쉐이더 검색중.

> ## 버그

+ ## 챔피언 선택시간 안맞는 버그 -> RaiseEvent 로  마스터 클라이언트 한곳에서 다른클라이언트에게 전송하기

+ ## RaiseEvent 송수신 무반응 -> ViewID 할당 해주는 방법 찾기


>## 내일 할일 
### 작업중인 씬 => Selection.scene

1. 만약 사람이 나가면 현재 있는 로비로 이동
5. 상대방이 선택한 챔피언 스펠 실시간으로 보여주기
3. 플레이어 스펠, 영웅 데이터화 후 인게임으로 넘겨주기
7. 위 작업 끝나면 UI 변경.
5. 룬 작업?

>## 내일 할일 
### 작업중인 씬 => Selection.scene

1. 챔피언 선택완료시 그림동기화, 선택 시간 동기화
1. 선택 시간 끝났을때, 선택한 ㄴ챔피언의 아트 가 나오게.
2. 만약 사람이 나가면 현재 있는 방 삭제 후 로비로 이동
3. 스펠 선택창,스펠 1,2 선택시 바로 미리보기 화면으로 적용되도록
4. 스펠 순서 변경
5.  상대방이 선택한 챔피언 스펠 실시간으로 보여주기
6.  내가 챔피언 고를때 챔피언 아트 바뀌기
7.  위 작업 끝나면 UI 변경.

<br>

># 8월 28일자

> ## 오늘 했던 작업 -> Selection.scene

+ ## 챔피언 선택시 동기화 리팩토링 

-> RPC Sender 클라이언트에 대한 필요없는 재귀함수 없도록 로컬과 동기화 함수 분리 알아보기 쉽도록 만듬

+ ## 스펠 동기화 작업중 

-> 실시간으로 보여주는 작업은 완료, 이미 생성된 스펠 버튼 에 대한 다중 클라이언트 공유 문제는, 로컬 / 동기화 함수를 구분 하여 사용해줄것.

+ ## RaiseEvent 무반응 해결

-> 1. 예제를 보고 따라치니, Start() 시 비활성화 되어있는 게임 오브젝트의 스크립트에 OnEnable() 단에 수신기를 넣어서 무반응 -> Start() 단에 넣어서 바로 구독 하도록 만듬

-> 2. 특정 스펠 버튼을 클릭하였을때 활성화 되는 bool 함수가 true 일때, 스펠과, 스펠 이미지를 할당하는 것인데, RaiseEvent 에는 플레이어의 이름과, 팀, 선택된 함수만 보내 주었는데, 새로운 변수를 만들어서 타 클래스의 버튼 클릭 유무를 받아와서 어떤 버튼이 클릭되었는지를 받아서 해당 버튼의 bool 함수를 활성화 시켜줌.
```csharp
//Event 구독을 위해서는 특정 이벤트 수신함수를 구독 하여야함

//수신 함수를 더하여 준다.
private void Start()
{
  PhotonNetWork.OnEventCall += PhotonNetwrok_OnRaiseEvent();
}

// 구독 해제를 할때는 빼주기.
private void OnDisable()
{
  PhotonNetWork.OnEventCall = PhotonNetwrok_OnRaiseEvent();
}
```
+ ## 작업했던 클라이언트 넘겨줌 -> 정무가 UI 및 부가적인 기능 추가예정.

+ ## 인스턴스화 안된 프리팹 의 ViewID 를 할당하는 법
-> 알고보니 ' PhotonNetwork.ViewID = {get; set;} '

-> 플레이어 프리팹을 생성할때 800~999번 대까지 랜덤 함수 할당해줌
``` csharp
var PlayerObj = Instanciate(PlayerPrefab, tranform, false);
var Pl_PhotonView = getComponent<PhotonView>();
Pl_PhotonView.ViewID = Random.Range(800, 999);
```


> ## 버그

+ ## 챔피언 선택시간 안맞는 버그 -> RaiseEvent 로  마스터 클라이언트 한곳에서 다른클라이언트에게 전송하기

+ ## 스펠버튼 공유화 버그, 버튼 AddListener 무반응 -> 이미 생성된 스펠 버튼 에 대한 다중 클라이언트 공유 문제는, 로컬 / 동기화 함수를 구분 하여 사용해줄것.


> ## 노트
```
1. 오늘 북미서버로 리그오브레전드를 플레이해봄. 170 ~ 195ms 정도의 핑이 나오고, 체감상 약 0.5초 정도 반응이 늦는듯하다. 

일례로 중국에서는 자신들의 서버의 핑을 최적화 해주는 것에 대한 포상금을 부여 할 정도라고 한다.

인게임 작업에 들어가면 RaiseEvent를 최대한 활용하여 에센셜한 정보만 전달하여 패킷을 최소화 하는것에 노력해야 겠다.

과거 연구에 따르면 온라인 게임 지연 시간이 100 ~ 200ms 사이일 경우, 약간의 지연(lag)을 감지할 수 있고, 

최대 300ms 내에서는 좀 더 심한 지연을 감지하게 되는데… 지연 시간이 1,000ms(1초)일 때는 주의력이 다른 

곳으로 전환되기 시작해 게임 일시 중단, 게임 나가기 및 재연결 시도 등의 다른 행동을 하기 시작한다.

패킷 최소화 및 서버 최적화 에 대한 조금 더 자세한 공부가 필요할듯. 


2. 서로 같이 하는 작업에서는 귀찮더라도 코드를 깔끔하고 보기 좋게 할 필요를 느낀다. 

마음 먹어도 쉽지는 않지만, 남한테 보여주면 부끄럽다.


3. 각각의 클래스 마다 디버그 함수를 만들어야 겠다.

혹은  계속해서 재활용해서  전역적으로 쓸수있는 디버그 함수를 만들어서 로깅을 해야겠다.  Null체크 도 포함해서.

내가 헤매는 대다수의 버그들은 대부분 호출스택을 통해서 찾아 낼수가 있었다.

현재 생각하고 있는 포맷은 

[함수의 대략적인 처리내용 + 게임오브젝트 + 클래스]

```


>## 내일 할일 
### 작업중인 씬 => Selection.scene

1. 스펠버튼 공유 풀기 및 AddListener 무반응 문제 해결하기 -> AddListener 가 무반응. 공유풀기는 로컬과 동기화 함수 구분 할것.
1. 만약 사람이 나가면 현재 있는 클라이언트 모두 로비로 이동 
3. 플레이어 스펠, 영웅 데이터화 후 인게임으로 넘겨주기
1. 로고 의 Shine 효과 나는 쉐이더 검색중.
5. 룬 작업?
7. 위 작업 끝나면 UI 변경 -> 정무에게 인계