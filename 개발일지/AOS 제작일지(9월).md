># AOS 개발일지
>## 2018 - 07 - 01 ~  
>## 부산게임아카데미

<br>

># 9월 4일자

> ## 오늘 했던 작업 -> KTYOption.Scene

+ ## 영탁 형님이 작업했던 Option Canvas 받아서 UI 수정 및 옵션 추가 (작업중)

+ ## 명우씨와 호동씨의 미니언 AI, 맵 배치 머징이 끝나면 서버에 붙일것 (머징 완료 대기중)




> ## 버그

+ ## 챔피언 선택시간 안맞는 버그 -> RaiseEvent 로  마스터 클라이언트 한곳에서 다른클라이언트에게 전송하기

> ## 노트
```csharp
1. 포톤에서는 로비에 존재하고 있는 플레이어 리스트를 제공하지 않음. 수천가지의 경우의 수가 있어서 리스트로 만들기에는 너무 많다고 한다. 또한 안정적이며, 저비용으로 처리하기 위한 대역폭을 절약 할수 있다고 한다.  대신 

PhotonNetwork.CountofPlayersOnMaster();  // 로비에 존재하는 플레이어 수를 받아올수는 있음.

PhotonNetwork.CountOfRooms() // 생성되어 있는 방의 갯수. 이건 로비에 없어도 받아올수있음.

포톤을 이용해서 구현을 한다고 치면, 

OnjoinnedLobby() 일때 RaiseEvent 로 다른 로비에 있는 플레이어에게 플레이어 리스트 생성. 

OnjoinnedRoom() 이 불리면 씬이 전환 되기 전에 PhotonNetwork.RaiseEvent -= CurEvent;

그리고 플레이어 리스트 삭제. 비용이 많이 드는건 당연 할듯. 대안이 없을까? 


1-1. 유니티 네트워킹에서는 OnClientEnterLobby(), OnClientExitLobby() 로 플레이어 이름 받아서 만들어 주면 될듯.


1-2. UntyPark Suite 라는 API. 유료. 로드 밸런서, DB 통합 및 DB 구현 솔루션, 로비 시스템, 계정관리, 서버관리, 채팅, 친구 목록, 지리적 필터링, 플레이어 매치메이킹 등이 있다고 함.

//////////////////////////////////////////////////////////////////////////////////////////////


2. InputField 에 한글이 안쳐질때 -> 새로 만들기..... 


3. 이미 생성된 방의 마스터 클라이언트 이름을 불러오기. CustomPropertyForLobby() 를 사용
//using Photon HashTable!
//커스텀 프로퍼티 생성!
RoomOption.CustomRoomPropertis = new HashTable(){{"CustomProperty","PhotonNetwork.player.MasterClient"}};

//로비 에서 프로퍼티를 받아오기!
RoomOption.CustomRoomPropertisForLobby = new string[] {"CustomProperties"};

//커스텀 프로퍼티 받아서 할당!
HashTable hs = room.customProperties;
RoomName.Text = (string)["CustomProperty"];

//프로퍼티 Get() Set() 가능! -> 플레이어 커스텀 프로퍼티도 마찬가지!
hs ["CustomProperties"] = text;
room.SetCustomProperties (cp);
```

>## 내일 할일 

>### 작업중인 씬 => KTYOption.scene
1. UI변경
2. 환경 옵션 추가 -> 키 바인딩은 제외



>### 보류중 => AOS_Sever 전반 정무가 UI 수정 및 로비 씬 작업중
1. 만약 사람이 나가면 현재 있는 클라이언트 모두 로비로 이동 
3. 플레이어 스펠, 영웅 데이터화 후 인게임으로 넘겨주기
1. 로고 의 Shine 효과 나는 쉐이더 검색중.
5. 룬 작업?

<br>

># 9월 5일자

> ## 오늘 했던 작업 -> KTYOption.Scene

+ ## UI 사운드 테스트만 남음 -> Borderless 창모드는 윈도우 핸들을 받아야 한다고함.(보류하기로))

+ ## 마우스 커서 적용 중(게임오브젝트따라 마우스 변경은 수신 받을 스크립트를 각각 추가하는걸로 )

+ ## 명우씨와 호동씨의 미니언 AI, 맵 배치 머징이 끝나면 서버에 붙일것 (height map 다시 설정중)




> ## 버그

+ ## 챔피언 선택시간 안맞는 버그 -> RaiseEvent 로  마스터 클라이언트 한곳에서 다른클라이언트에게 전송하기

> ## 노트
```csharp
1. 마우스 커서는 원하는 이미지를 Import 할때 Sprite 가 아닌 Cursor 로 지정하여 Apply.

Cursur.SetCursor() 사용하면됨. Hotshot 이라는 파라미터는 포인터클릭 지점이 커서이미지의 어디에 해당할지 정하는것. 

2. 테두리 없는 창모드는 윈도우에서 Handle 을 받아서 적용해야함.
```

>## 내일 할일 

>### 작업중인 씬 => KTYOption.scene
1. UI 테스팅
2. 커서 수신기 달아서 원하는 게임오브젝트마다 테스트. 
3. 일찍 끝나면 미니맵 과 핑 찍는 스크립트 작성 (브로드캐스팅 나중에...?)



>### 보류중 => AOS_Sever 전반 정무가 UI 수정 및 로비 씬 작업중
1. 만약 사람이 나가면 현재 있는 클라이언트 모두 로비로 이동 
3. 플레이어 스펠, 영웅 데이터화 후 인게임으로 넘겨주기 -> 커스텀프로퍼티로 해주자.
1. 로고 의 Shine 효과 나는 쉐이더 검색중.
5. 룬 작업?


<br>

># 9월 6일자

> ## 오늘 했던 작업 -> KTYOption.Scene

+ ## UI 완료

+ ## 마우스 커서 작업 완료

+ ## 서버는 Room.Scene 까지 작업중(정무), A* 와 미니언, 월드맵 Scene 와 오늘까지 작업한 UI 머징 작업중

+ ## 챔피언이동, 미니맵(호동), 미니맵 핑 설정, RTS 이동효과 작업중


> ## 버그

+ ## 챔피언 선택시간 안맞는 버그 -> RaiseEvent 로  마스터 클라이언트 한곳에서 다른클라이언트에게 전송하기

> ## 노트
```csharp
1. RTS 이동효과는 Vector2 마우스 포지션 받아서 ScreenToWorldPosition 으로 변환 및 레이 캐스트로 해당 위치에 쏴주면 될듯.

2. 일반 터레인 맵에 쏘는 핑 신호는 월드 좌표를 받아 축척해서 미니맵으로 변환 하면 될려나. 검색 해봐야할듯

3. 핑 신호 주는건 같은 팀 플레이어를  Interesting Group 에 등록하여 따로 쏴주는걸로 해보자. 

4. 쉽게 머징하려면 prefab 과 meta 파일, 필요한 Resource 와 머징 대상 씬과의 정확한 경로가 있으면 메타파일 이 잘 작동. 

5. 첫 로그인 씬부터 마우스커서 작동할 게임오브젝트 만들고 Do not Destroy. 

6. 챔피언 이동시 사용할 A*는 레이 쏴서 타겟이 될 빈 오브젝트를 목표점에 옮겨주고, 챔피언 오브젝트는 목표점으로  A*를 사용해 가는식. 빈 오브젝트에 다른 오브젝트가 겹쳐 있을시 도착 못해서 빙빙 돌것이라고 함.

7. 개인 적인 생각이지만 협업할때, 스크립트를 넣고 인스펙터에서 끌어 넣기 보단 코드로 자동적으로 찾아주는게 여러사람 편할듯.
```

>## 내일 할일 

>### 작업중인 씬 => KTYOption.scene
1. 씬 머징 작업
2. 임시 챔피언 오브젝트 생성, 이동(A*), RTS 무빙 효과
3. 핑 신호 작업 및 시간 나면 핑 신호 동기화 준비.
 



>### 보류중 => AOS_Sever 전반 정무가 UI 수정 및 로비 씬 작업중
1. 만약 사람이 나가면 현재 있는 클라이언트 모두 로비로 이동 
3. 플레이어 스펠, 영웅 데이터화 후 인게임으로 넘겨주기 -> 커스텀프로퍼티로 해주자.
1. 로고 의 Shine 효과 나는 쉐이더 검색중.
5. 룬 작업?

<br>

># 9월 6일자

> ## 오늘 했던 작업 -> InGame.Scene

+ ## Grid + A* + Minion Scene + UI 머징완료

+ ## RTS 이동 이펙트 작업중 

+ ## 미니맵용 Line Render 작업 완료 (미니맵 만들고 나서 적용 시키기) 


> ## 버그
1. RTS 이동효과 제작중 이펙트가 한곳에 고정되서 나오는 현상 발생 (구매한 에셋 뜯어볼것.))


> ## 노트
```csharp
1.  미니맵 클릭시 월드 좌표 받아 이동 및 축척 적용 참고 글
wwww.reddit.com/r/Unity3D/comments/48ao2u/getting_world_position_from_clickable_minimap_tips/

2. RTS 이펙트는 풀링 해주기.

3. Merging Tool 사용 못해봄. 그냥 파일 옮겨서 씬에 합쳐줌. 다음에 써보기 

6. 챔피언 이동시 레이 쏴주어서 맞는 콜라이더의 태그가 터레인 일때 챔피언 오브젝트를 이동 시켜주었음.
```

>## 내일 할일 

>### 작업중인 씬 => InGame.scene
1. RTS 이동 이펙트 적용 및 풀링 적용 하기

2. 미니언은 이동 GIZMO 끄기.

3. 미니맵 적용 하기. 

4. 변경된 리스폰 스크립트 적용하기(명우씨 작업 스크립트)

>### 보류중 => AOS_Sever 전반 정무가 UI 수정 및 로비 씬 작업중
1. 만약 사람이 나가면 현재 있는 클라이언트 모두 로비로 이동 
3. 플레이어 스펠, 영웅 데이터화 후 인게임으로 넘겨주기 -> 커스텀프로퍼티로 해주자.
1. 로고 의 Shine 효과 나는 쉐이더 검색중.
5. 룬 작업?

<br>

># 9월 10일자

> ## 오늘 했던 작업 -> InGame.Scene

+ ## Minimap 커서 & 이펙트 작업 완료

+ ## 미니맵 적용 및, RTS카메라 적용, InterReactable 미니맵 적용중 (마우스 좌표가 안맞음))

+ ## 미니맵용 Line Render 미니맵 레이어로 분리


> ## 버그
1. 미니맵 Ray 사용시 이동 및 메인 카메라 이동이 되나, 마우스 커서의 좌표와 실제 레이를 쏴서 이동하는 부분이 안맞음. Ray 쏘는 부분에 마우스 좌표 부분 수정해볼것.


> ## 노트
```csharp
1.  OnPointerClick() 을 사용, ScreenPointToRectangle Ray를 사용. 코드는 추가예정

2. 각 챔피언의 오브젝트를 가지고 있는 매니저가 필요할듯. RaiseEvent할때마다 타 클라이언트에서 Sender 오브젝트를 Find 로 찾을수는 없는 노릇임

3. 챔피언 스킬은 공통적인 부분 을 가진 클래스를 상속 받아서 사용하고 챔피언 마다 스킬이 다른 부분을 Override 해서 사용. 

4. 스킬에 사용되는 모든 파티클 을 pooling 해서 하나의 GameObject 컨테이너에 보관해야할듯. 명우씨는 이후 확장성을 위해 투사체일때, 자기 자신에게만 적용될때, 투사체+자기자신 에 대한 경우에 수를 가지고 설계한다고 하셨음.

5. 스킬 동기화를 위한 설계는 모든 플레이어는 스킬매니저를 가지고 있고, 스킬매니저는  현재 전장에 사용 되는 스킬들만 캐싱하고있다가, RaiseEvent를 송수신할때, 위치값을 가지고 생성, 피격판정과 클라이언트의 팀에 따른 전장의 안개 시야 유무를 위해 Faction 변수를 넣고, 사용 할 예정. 더 좋은 설계가 있을까?

6. 챔피언 A*로 이동하는 부분은 RayCast 배열로 받아주는데, 한번만 받도록 MouseCursor.cs 에 통합해서 수정해야 할듯.

7. Fog of War 사용시 Light 부분은 Baked 해서 사용하니, 기존에 있던 건물 오브젝트나 기타 환경적인 부분의 오브젝트의 텍스쳐가 어두워지고 빛 바래지는 현상 생김. LightOrb 를 사용하여 해결. 

///////////////////////////////////////////////////////////////////필독
8. 오늘 까먹은 RPC와 RaiseEvent 의 차이점.

RPC 는 Remote Procedure Calls 의 약자로 원격 프로 시저 호출이라고함. 

PhotonView 가 있는 Object 에게만 RPC 호출이 가능하며, 

RPC는 호출즉시 전송안됨. 객체 동기화 주기가 될때까지 버퍼링되며, 전송 주기가 되야 전송함

//이런 지연을 없애기 위해 업데이트 루프를 중지하고 바로 RPC를 전송.

PhotonNetwork.SendOutgoingCommands();

RaiseEvent 는 PhotoneView 와 호출할 메소드가 필요하지만,  고유 식별자인 이벤트 코드를 사용하며, 최대 200개가 가능하다. 메소드를 포톤뷰로 부터 호출하지않는다.


//원문 -------------------------------------------------------------------------------
"RPC call on a game object tells all clients to execute a function on that game object."

"RaiseEvent is more or less detached from a GameObject. This means that you can use an object A to raise an event by using PhotonNetwork.RaiseEvent and an object B to receive this event, which is different to RPCs where you only have one object. RaiseEvent basically allows you to have a mediator for all of your custom events."


'RaiseEvent는 GameObject에서 어느 정도 분리되어 있습니다. 즉, 개체 A를 사용하여 PhotonNetwork.RaiseEvent를 사용하여 이벤트를 발생시키고 개체 B를 사용하여 하나의 개체 만있는 RPC와는 다른이 이벤트를 수신 할 수 있습니다. RaiseEvent는 기본적으로 모든 사용자 지정 이벤트에 대한 조정자를 허용합니다.'

결과적으로 좀더 정밀한 RPC라고 생각 하면 될듯? (아니면 수정...) 

RaiseEvent 또한 즉시 소켓에 쓰여지지않고 SendOutgoingCommands() 가 호출될때까지 대기한다고한다. 

이런 절차로써 메세지를 더 적은 수의 데이터로 모으고 트래픽을 절약할 수 있다고 한다.

RPC를 뜯어보면 RaiseEvent 를 사용하는 것을 알수있다.

```

>## 내일 할일 

>### 작업중인 씬 => InGame.scene
1. 마우스커서 좌표 조정

2. 미니언은 이동 GIZMO 끄기.

4. 변경된 리스폰 스크립트 적용하기(명우씨 작업 스크립트)

>### 보류중 => Login.cs
1. 로고 의 Shine 효과 나는 쉐이더 검색중.
5. 룬 작업?

<br>

># 9월 11일자

> ## 오늘 했던 작업 -> InGame.Scene

+ ## Minimap 미니맵용 커서 좌표 조정완료 -> RawImage의 좌표가 원점이 아니었음.........ㅎㅎㅎㅎ

+ ## 핑 UI 제작 완료 -> 내일은 스크립트 작업

+ ## 마우스 핑 풀링 적용하기


> ## 버그


> ## 노트
```csharp
1. 호동, 노명 -> 스킬 이펙트 작업 / 명우 -> 스킬 스크립트 작업 / 정무 -> Selection.Scene 리팩토링중

2. 근우 -> 핑 송수신 작업

3. 의식의 흐름 대로.. 

  핑은 메인 카메라용 큰 사이즈의 UI 와 미니맵용 작은 사이즈의 UI 로 나뉨. 
  
  Alt 키와 마우스 오른쪽 키 드래그 누르고 있을시 시 UI 활성화 (EventTrigger 사용) + 최초 마우스 커서위치 저장
  
  UI 원점 을 시작점, 마우스 커서가 끝점으로 하는 Line 생성. (멀어질수록 길어짐)
  
  각각 4방향의 버튼은 마우스커서를 위, 아래, 좌, 우, 중앙 위치을 판단
  
  열거형 으로 5가지의 버튼중 하나 조건을 선택  + 버튼 색 바뀌기
  
  핑은 각각 클라이언트가 10개씩 총 40개를 풀링으로 미리 생성해서 가지고있음
  
  -> 핑 신호 갯수에 대한 조건은 확인해보기


  만약 위쪽 방향으로 커서를 놓고 마우스 오른쪽 드래그를 놓았을때, 
  
  1. 선택한 위쪽 버튼의 열거형 조건 변경 (MouseOver 혹은 PointOver)
  
  2. 최초 저장한 마우스 커서 위치 -> 월드좌표로 변환 ->  메인화면에 핑 생성 
  
  3. 각각의 핑 이펙트는 미니맵용 레이어가 설정된 스프라이트? 파티클을 가지고있음. (미니맵도 같이 보일수 
  있게)
  
  4. 혹은 미니맵 스크립트에서 좌표를 받아 따로 실행.
  
  5. 송출자 는 RaiseEvent 실행. (월드 좌표값, 핑의 종류, 어느 팀인지)
  
  6. 수신자는 RaiseEvent 받아서 해당 위치에 핑 생성
  
  7. UI 비활성화
  
  8. Exit 버튼일때는 Return;
  
  9. 미니맵용 UI도 재활용 해서 사용


```

>## 내일 할일 

>### 작업중인 씬 => InGame.scene

1. 미니언은 이동 GIZMO 끄기.

1. 미니맵 스크립트 작성 (로컬 작동까지만)

1. Interest 그룹 알아보기 -> 원하는 팀에게만 쉽게 송출하기 위함

5. EventGroup 미리 설정 해보기 (최대 200개 가능)

>### 보류중 => Login.cs
1. MMO UI 에서 추가 적용할 수 있는 것은 제일 마지막에 시간나면 적용.

<br>

># 9월 11일자

> ## 오늘 했던 작업 -> InGame.Scene

+ ## 미니맵 핑 작업 중 (원점으로 부터 마우스 커서 까지 상하좌우 방향 찾아서 받아오기, 쿼터뷰 카메라 시점에 맞게 LineRender 하기.  )



> ## 버그


> ## 노트
```csharp
1. 호동, 노명 -> 스킬 이펙트 작업 / 명우 -> 스킬 스크립트 작업 / 정무 -> Selection.Scene 리팩토링중

2. 근우 -> 핑 송수신 작업

3. 의식의 흐름 대로.. 

  핑은 메인 카메라용 큰 사이즈의 UI 와 미니맵용 작은 사이즈의 UI 로 나뉨. 
  
  Alt 키와 마우스 오른쪽 키 드래그 누르고 있을시 시 UI 활성화 (EventTrigger 사용) + 최초 마우스 커서위치 저장
  
  UI 원점 을 시작점, 마우스 커서가 끝점으로 하는 Line 생성. (멀어질수록 길어짐)
  
  각각 4방향의 버튼은 마우스커서를 위, 아래, 좌, 우, 중앙 위치을 판단
  
  열거형 으로 5가지의 버튼중 하나 조건을 선택  + 버튼 색 바뀌기
  
  핑은 각각 클라이언트가 10개씩 총 40개를 풀링으로 미리 생성해서 가지고있음
  
  -> 핑 신호 갯수에 대한 조건은 확인해보기


  만약 위쪽 방향으로 커서를 놓고 마우스 오른쪽 드래그를 놓았을때, 
  
  1. 선택한 위쪽 버튼의 열거형 조건 변경 (MouseOver 혹은 PointOver)
  
  2. 최초 저장한 마우스 커서 위치 -> 월드좌표로 변환 ->  메인화면에 핑 생성 
  
  3. 각각의 핑 이펙트는 미니맵용 레이어가 설정된 스프라이트? 파티클을 가지고있음. (미니맵도 같이 보일수 
  있게)
  
  4. 혹은 미니맵 스크립트에서 좌표를 받아 따로 실행.
  
  5. 송출자 는 RaiseEvent 실행. (월드 좌표값, 핑의 종류, 어느 팀인지)
  
  6. 수신자는 RaiseEvent 받아서 해당 위치에 핑 생성
  
  7. UI 비활성화
  
  8. Exit 버튼일때는 Return;
  
  9. 미니맵용 UI도 재활용 해서 사용


```

>## 모레 할일 

>### 작업중인 씬 => InGame.scene

1. 미니언은 이동 GIZMO 끄기.

1. 미니맵 스크립트 작성 (로컬 작동까지만)

1. Interest 그룹 알아보기 -> 원하는 팀에게만 쉽게 송출하기 위함

5. EventGroup 미리 설정 해보기 (최대 200개 가능)


+ ## 마우스 핑 풀링 적용하기


>### 보류중 => Login.cs
1. MMO UI 에서 추가 적용할 수 있는 것은 제일 마지막에 시간나면 적용.

<br>

># 9월 13일자

> ## 오늘 했던 작업 -> InGame.Scene

+ ## 미니맵 핑 작업 중 (UI 제작 완료)




> ## 버그


> ## 노트
```csharp
1. 12일은 예비군 
```

>## 내일 할일 

>### 작업중인 씬 => InGame.scene

1. 미니맵 스크립트 작성 (로컬 작동까지만)

1. Interest 그룹 알아보기 -> 원하는 팀에게만 쉽게 송출하기 위함

5. EventGroup 미리 설정 해보기 (최대 200개 가능)


+ ## 마우스 핑 풀링 적용하기


>### 보류중 => Login.cs
1. MMO UI 에서 추가 적용할 수 있는 것은 제일 마지막에 시간나면 적용.

<br>

># 9월 13~15일자

> ## 오늘 했던 작업 -> InGame.Scene

+ ## 미니맵 핑 작업 중 (원점으로 부터 마우스 커서 까지 상하좌우 방향 찾아서 받아오기, 쿼터뷰 카메라 시점에 맞게 LineRender 하기.  )

> ## 버그


> ## 노트
```csharp
1. 평면 조건에서 회전 각도를 구하여 적용하였다가  RTS 카메라 가 적용된 씬에서 선을 그리니, 
UI 평면 상의 시작점과 끝점의 Z값이 맞지않아 맞추는데 2일 정도 걸린듯..

아래는 해결 코드, UI 와 수평을 이루는 가상의 Plane 을 만들어서, Ray를 쏴 부딪힘. 

plane = new Plane(-transform.forward, transform.position); // 축, 원점을 기준으로 한 가상의 평면
MousePosToRay = TargetCamera.ScreenPointToRay(Input.mousePosition); //카메라에서 마우스까지의 Ray
float distanceForEndPos = 0;
plane.Raycast(MousePosToRay, out distanceForEndPos);
endPos = MousePosToRay.origin + MousePosToRay.direction * distanceForEndPos;
```

```csharp
2. 좌표 변환 하는게 많이 헷갈린다.. 시간내서 공부 해야할듯.

3. 라인렌더러의 선을 수평으로 맞추고, UI의 높이를 캔버스와 수평으로 맞추고, UI의 중점 받아와서 월드로 바꾸어 생성하는데.. 3일 걸림.. UI 부분은 아직 한참 공부해야 겠네...ㅜㅜ
```


>## 모레 할일 

>### 작업중인 씬 => InGame.scene

1. 미니맵핑 작업중

1. Interest 그룹 알아보기 -> 원하는 팀에게만 쉽게 송출하기 위함

5. EventGroup 미리 설정 해보기 (최대 200개 가능)


+ ## 마우스 핑 풀링 적용하기


>### 보류중 => Login.cs
1. MMO UI 에서 추가 적용할 수 있는 것은 제일 마지막에 시간나면 적용.

<br>

># 9월 17일자

> ## 오늘 했던 작업 -> InGame.Scene

+ ### 미니맵 핑 작업 중 (각도 받아오기, UI 캔버스와 수평이루기, 원하는 지점에 생성, 미니맵에도 핑 표시 ,풀링적용 완료)))
 

> ## 버그
1. 에셋에 포함되어 있는 Prefab  Hirerarchy 에 안꺼내짐.. 새로 만든 Prefab은 됨. 

1. 마우스 핑이 보이지않음. 위치가 안맞는듯..? 증상만 확인함

1. 미니맵 을 위한 작은 핑 UI 를 꺼내려고 하는데, 포인터 클릭은 같이 안먹고, 업데이트에서 넣어도 중단점에서 불러지지 않음
```csharp
private void OnPointerClick(PointerEventData eventData) 
{
   if (eventData.button == PointerEventData.InputButton.Left 
   && Input.GetKeyDown(KeyCode.LeftAlt) && Input.GetMouseButtonDown(0))
   {
     SmallPing.SetActive(true);
   }
}

private void update()
{
    if (Input.GetKeyDown(KeyCode.LeftAlt) && EventSystem.current.IsPointerOverGameObject()
    && Input.GetMouseButtonDown(0))
    {
      SmallPing.SetActive(true);
    }
}
```

<br>

> ## 노트
```csharp
1. 마우스 위치를 받아 UI 를 조정, 캔버스 와 수평을 맞추기

 var screenPoint = new Vector3(Mouse.x, Mouse.y, PlaneDistance); // z값을 캔버스 Plane Distance 값 줌
 transform.position = Camera.main.ScreenToWorldPoint(screenPoint);
```

```csharp
2. UI의 중점에 핑 생성.. 

Mouse.z = Camera.main.farClipPlane; // OnEnable 에서 받아온 마우스 초기값 + Z 값
Ray ray = Camera.main.ScreenPointToRay(Mouse); // 마우스 좌표를 기준으로  스크린을투과하는 레이
RaycastHit[] hits = Physics.RaycastAll(ray);
  foreach (RaycastHit hit in hits)
  {
    if (hit.collider.gameObject.layer.Equals(LayerMask.NameToLayer("GroundLayer")))
    {
      // 타겟을 레이캐스트가 충돌된 곳으로 옮긴다.
      InitialCoordinate = hit.point; 
      MakePingSign();
    }
  }
```

```csharp
3. 마우스가 GameObject(UI) 위에 있는지 유무 체크

if(EventSystem.current.IsPointerOverGameObject()) 
```
```csharp
4. 미니맵 좌표를 월드좌표로 바꾸기 -> 코드 별도 첨부

5. 미니맵에 핑 따로 표시 -> 미니맵을 Camera Render Texture 를 써서 야매로 자식핑 만들어서 Y축 올려 하나로 만듬..
```

>## 내일 할일 

>### 작업중인 씬 => InGame.scene

1. 미니맵용 Ping UI 마저 작업하기

2. ## 마우스 핑 풀링 적용하기
1. Interest 그룹 알아보기 -> 원하는 팀에게만 쉽게 송출하기 위함

5. EventGroup 미리 설정 해보기 (최대 200개 가능)

>### 보류중 => Login.cs
1. MMO UI 에서 추가 적용할 수 있는 것은 제일 마지막에 시간나면 적용.

<br>

># 9월 18일자

> ## 오늘 했던 작업 -> InGame.Scene

+ ### 미니맵 핑 작업 중 (각도 받아오기, UI 캔버스와 수평이루기, 원하는 지점에 생성, 미니맵에도 핑 표시 ,풀링적용 완료)))
 

> ## 버그

> ## 노트

```csharp
1. 라인렌더러를 사용하여 미니맵에 표시 

하루종일 헤매다가; 

LineRender는 Screen Space - Overlay 에서 불가능 한 것을 확인,

어차피 현재 미니맵은 Camera Render 를 이용하여 보여 주기 때문에, 월드에서 선을 그려주면 되겠다 싶어서

이전에 이용한 RectTransformUtility.ScreenPointToLocalPointInRectangle() 함수와, 

IDragHandler, IPointerDown, IpointerUp 을 사용하여 시작점과 끝점을 설정해줌.

이중 드래그 가 잘 안되었는데, 파라미터 를 클릭한 포지션을 받아와서 안되던 거였음;

아래와 같이 두번째 파라미터를 바꾸어서 받아줌.
if (RectTransformUtility.ScreenPointToLocalPointInRectangle(RectTransform, eventData.Draging, eventData.pressEventCamera, out localCursor))
```
<br>

```csharp
2. UI 원점으로 부터 각도 변환

각도를 구하려면, 두 벡터와 방향이 필요.

Handler 에서 Ray를 쏴서  선을 그려주었고, 마찬가지로 각도는, 시작점과 끝점의 Vector2 를 받아서 각도를 받아줌. 그런데 -135 에서 135 까지만 받아와서 바꿔야 할듯

Ray = Camera.Main.ScreenPointToRay(Input.MousePosition);
RayCastHit hit;
if(Physhics.RaycastAll(Ray,out hit, Mathf.Infinity));

Vector3 pos = New Vector3(hit.x, Camera.Main.transform.position.y + 100, hit.z);

Vector2 StartPos = new Vector2(pos.x,pos.z);
Vector2 EndPos = new Vector2(pos.x,pos.z);

Vector2 Dir = Startpos - Endpos;
Vector2.SignedAngle(Vector3.up,dir); 
```


>## 내일 할일 

>### 작업중인 씬 => InGame.scene

1. 미니맵용 Ping UI 마저 작업하기(각도 360로 변환해서 받기, 시작점에 핑 생성)

2. ## 마우스 핑 풀링 적용하기

1. Interest 그룹 알아보기 -> 핑 끝나면 실험해보기.

5. EventGroup 미리 설정 해보기 (최대 200개 가능)

>### 보류중 => Login.cs
1. MMO UI 에서 추가 적용할 수 있는 것은 제일 마지막에 시간나면 적용.


