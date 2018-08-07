![](#%20TIL%20%20%20/%202018%20-%2008%20-%2007.png)
# Photon

>## Photon Tutorial 1
+ 홈페이지 (https://www.photonengine.com/ko-kr/Photon)
+ 튜토리얼 (https://doc.photonengine.com/ko-kr/pun/current/demos-and-tutorials/pun-basics-tutorial/lobby)
      


>## Photon?
+ Photon Unity Networking (PUN) 의 약자. 독립 네트워킹 엔진.
+ Unity, Unreal, Mac, Windows, Java, Corona, 플랫폼 지원
+ Free 버전은 동시접속 20명까지.
+ 플랫폼, 기기에는 영향이 없으나, 같은 지역에서만 플레이가능


>### **크로스플랫폼을  위한 체크리스트**
1. 동일한 AppID, AppVersion, Region, 클라이언트 파일
2. 이름으로 방 입장전에 동일이름이 없는지, 혹은 JoinOrCreateRoom 메소드로 체크
3. JoinRandomRoom 사용시 동일 로비를 사용하고 있는지.

#
>## 기본 사항

## 1. 접속
+ 게임 버전의 설정이며, 서로 같은 게임버전의 클라이언트끼리 통신 가능
```csharp
//게임 버전 설정
PhotonNetwork.ConnectSUsingSettings("1.0");

//특정 방 입장 
//실패하면 OnPhotonJoinRoomFailed() 로 콜백 
PhotonNetwork.JoinRoom("SomeRoom");

//랜덤 방 입장
//마찬가지로 실패시 위와 같은 함수로 콜백
PhotonNetwork.JoinRandomRoom();

//방 생성
//같은 이름의 방이 존재할때 OnPhotonCreateRoomFailed() 콜백
PhotonNetwork.CreateRoom("MyRoom");

//방 옵션의 설정
// 공개or비공개 설정 , 최대인원수, 플레이어의  UserId 파악
RoomOptions roomoption = new RoomOptions();
roomoption.isVisible = flase,
roomoption.maxPlayers = 4,
//클라이언트에서 PhotonPlayer.userID 를 사용하면 서버에서 ID 제공
roomoption.publishUserID = true;

//방의 생성 혹은 입장 및 옵션 설정
PhotonNetwork.JoinOrCreateRoom(WantedName, roomoption, TypedLobby.Default);
```

## 2. 게임 플레이

+ 로컬에 있는 인스턴스틑 networked GameObjects 로 인스턴스화 됨
+ 각 게임오브젝트는 식별되는 PhotonView 와 소유자 를 가지고 있음.
+ PhotonView 컴포넌트의 Observed 필드로 각각 동기화 가능

```csharp

```

>## 시작하기

에셋 스토어 에서 PUN 에셋 찾아 받은후에 실행시켜보면
PUN Setup이 뜬다. 
![](2018-08-07-21-53-07

