<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [Photon](#photon)
- [](#)
  - [1. 접속](#1-%EC%A0%91%EC%86%8D)
  - [2. 게임 플레이](#2-%EA%B2%8C%EC%9E%84-%ED%94%8C%EB%A0%88%EC%9D%B4)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

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

>## 1. 로비 

+ 서버접속, 방 접속, 방 생성에 대하여
+ Using IPunCallbacks, IPunObservable Interfaces
+ Using Photon.PunBehaviour

에셋 스토어 에서 PUN 에셋 찾아 받은후에 실행시켜보면 PUN Setup이 뜬다.

포톤 홈페이지에서 가입을 한후 Appid 를 입력 해준다.

새로운 씬을 만들고 
Launcher 라는 이름의 GameObject와 Launcher.cs 를 만들어 주어 할당해주자.

스크립트를 작성해서 넣어주자.

> ## Launcher.cs

```csharp
using UnityEngine;
 
public class Launcher : Photon.PunBehaviour
{
    
    private string _gameVersion = "1";  //클라이언트의 버전. 유저는 클라이언트 버전으로 구분됨

    public PhotonLogLevel Loglevel = PhotonLogLevel.Full; // 인스펙터용 전역변수 Full은 모든로그, 구조 파악 후 Informational
    public byte MaxPlayersPerRoom = 4; // 최대 플레이어
    private void Awake()
    {
        
        PhotonNetwork.logLevel = Loglevel;  //전역변수 로그레벨 할당
 
        PhotonNetwork.autoJoinLobby = false;    //로비의 자동접속여부. 로비의 리스트를 보기위해 false 한다.
                                                //True 접속 가능 로비 접속후 OnJoinedLobby()는 호출    
                                                
        PhotonNetwork.automaticallySyncScene = true;    //마스터 클라이언트와 같은 씬으로 동기화 여부
                                                        //True 면 마스터 클라이언트는 LoadLevel()을 호출가능
                                                        //모든 플레이어가 같은 씬으로 이동됨.
    }
    private void Start()
    {
        Connect();
    }
    public void Connect()
    {   
        // 만약 마스터 서버에 접속 후 로비에 들어갔다면,
        if (PhotonNetwork.connected)
            PhotonNetwork.JoinRandomRoom();//사용 가능한 룸에 참여, 룸이 없으면 OnPhotonRandomJoinFailed() 호출
        else
            PhotonNetwork.ConnectUsingSettings(_gameVersion); //앱이 네트워킹 되기위한 시작점
    }

    //최초 마스터 서버 접속 후 OnConnectedToMaster() 호출
    public override void OnConnectedToMaster()
    {
        Debug.Log("DemoAnimator/Launcher: OnConnectedToMaster() was called by PUN");
        //마스터 접속시 바로 랜덤한 방에 들어감
        PhotonNetwork.JoinRandomRoom();
    }
    
    public override void OnDisconnectedFromPhoton() //연결이 끊켰을때의 콜백
    {
        Debug.Log("DemoAnimator/Launcher: OnDisconnectedFromPhoton() was called by PUN");
    }
    //방접속에 실패했을때 콜백
    public override void OnPhotonRandomJoinFailed(object[] codeAndMsg)
    {
        Debug.Log("DemoAnimator/Launcher: OnPhotonRandomJoinFailed() was called by PUN. No random room available, " + "so we create one.\nCalling: PhotonNetwork.CreateRoom(null, new RoomOption() {maxPlayers = 4},null)");
        //접속 실패시 자동으로 방을 만든다.
        PhotonNetwork.CreateRoom(null, new RoomOptions() { maxPlayers = MaxPlayersPerRoom }, null);
    }
    public override void OnJoinedRoom()  //방에 들어갔을때
    {
        Debug.Log("DemoAnimator/Launcher: OnJoinedRoom() called by PUN. Now this client is in a room.");
    }
}
```

이제 재생 버튼을 누르면 많은 콘솔 로그가 뜨며, 

아무 에러 없이 마스터에 접속했다고(포톤 클라우드로 접속한다면,) 로그가 뜰 것이다.

만약 인터넷이 연결 되어있지 않다면, 

"Connect() to 'ns.exitgames.com' failed: System.Net.Sockets.SocketException: No such host is known".

알려진 호스트가 없다고 에러를 발생시킨다. 

 > ## Using IPunCallbacks and IPunObservable Interfaces
 
 PUN 에서 지원하는 인터페이스로 여러 콜백들을 심어준다.

 >> ## Using Photon.PunBehavior

 PUN 에서 각종 프로퍼티와 Override 해주기 위한 가상의 메소드를 사용할수 있다.
 인터페이스 처럼 모든 콜백을 심지않아 실용적이다.