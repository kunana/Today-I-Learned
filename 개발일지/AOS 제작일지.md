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



>### 내일 할일 
### 작업중인 씬 => Selection.scene

챔피언 골랐을때, 다른 클라이언트에 해당 플레이어리스트 프리팹에
이름 뜨도록 동기화
-> 생성되지않은 프리팹에 포톤뷰 를 넣어서 쓰면 illegal error.

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