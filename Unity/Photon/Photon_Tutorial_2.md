``` csharp
//성공적으로 서버에 접속
public void OnJoinedLobby();
//성공적으로 방에 접속
protected void OnJoinedRoom();
//성공적으로 방을 생성
protected void OnCreatedRoom();
//새 씬이 로드되었을때(Mono 함수)
protected void OnLevelWasLoaded(int level);
//
public void OnEvent(EventData photonEvent)

public void OnOperationResponse
(OperationResponse operationResponse)

public void OnStatusChanged(StatusCode statusCode)

PhotonHandler.Update()
//- 이벤트와 핸들러는 Enum.cs에 명시되어 있음.
//- 이벤트명에 ()를 붙이면 보통 처리되는 함수명이 맞음.

public enum PhotonNetworkingMessage
{
OnConnectedToPhoton
OnLeftRoom
OnMasterClientSwitched     //한 클라이언트가 떠나서, 방장 교체시
OnPhotonCreateRoomFailed
OnPhotonJoinRoomFailed
OnCreatedRoom
OnJoinedLobby
OnLeftLobby
OnDisconnectedFromPhoton
OnConnectionFail
OnFailedToConnectToPhoton
OnReceivedRoomListUpdate
OnJoinedRoom
OnPhotonPlayerConnected
OnPhotonPlayerDisconnected
OnPhotonRandomJoinFailed
OnConnectedToMaster
OnPhotonSerializeView
OnPhotonInstantiate
OnPhotonMaxCccuReached     //최대 동접(설정 및 계약된) 도달했을때
OnPhotonCustomRoomPropertiesChanged     //방 속성 변경
OnPhotonPlayerPropertiesChanged //플레이어 속성이 변경되었을때
OnUpdatedFriendList //친구 리스트 변경
OnCustomAuthenticationFailed // 인증 실패(연결이 종료되게 된다)
OnWebRpcResponse     //WebRPC가 가능할때 PUN이 호출
OnOwnershipRequest     //다른 플레이어가 PhotonView의 방장 요청할때(현재 유저가 방장인 경우)
}


//로그 레벨
public enum PhotonLogLevel
{
    ErrorsOnly,          //에러만
    Informational,     //정보만
    Full          //전부
}
```
```csharp
//RPC에서 사용하는 target 옵션. 원격 //클라이언트에서 RPC콜을 얻기 위해 사용
public enum PhotonTargets
{   
     모든 RPT를 모두에게 즉시 보내고 실행. 나중에 방에 들어온 플레이어는 이 RPC가 처리되지 않음.
    All,
   
     나를 제외한 다른 모든 클라이언트에게 RPC보냄
    Others,
        
     마스터 클라이언트(방장)에게만 RPC보냄. 주의 : 방장이 RPC가 드롭되거나 실행되기 전에 종료할 수 있음
    MasterClient,
    
        
    모두에게 보내고 실행한다. 클라이언트는 RPC를 바로 실행하지 않는다.
     새로운 플레이어는 방에 새로 합류할때, RPC를 버퍼 처리한다.(이 클라이언트가 접속 종료할 때까지)
     AllBuffered,   

    Others와 동일하지만, 버퍼되고, 바로 실행되지 않을 수 있다는 차이(생략은 없다?)
    OthersBuffered,
        
    //모두에게 서버를 통해 RPC를 보낸다(자기 포함)
     //이 클라도 서버에서 받아서 실행한다
     //이득 : 서버가 모든 클라이언트에게 RPC의 순서를 맞춰 보낼수 있다.
     AllViaServer,
        
     //모두에게 서버를 통해 RPC를 보내고(자기 포함), 나중에 합류한 플레이어를 위해 버퍼에 저장한다.
     //이 클라도 서버에서 받아서 실행한다
     //이득 : 서버가 모든 클라이언트에게 RPC의 순서를 맞춰 보낼수 있다.
    AllBufferedViaServer
}

public enum LobbyType :byte
{
    Default = 0,     //지정해서 들어오거나, 랜덤으로 들어와야 한다.
    SqlLobby = 2     //Sql의 like명령처럼 조건 검색을 통해 접속할 수 있다. bigger / less / and등의 조합이 가능
}



//클라우스 서비스 지역코드
public enum CloudRegionCode { eu = 0, us = 1, asia = 2, jp = 3, au = 5, none = 4 };



//이용 가능한 서버(내부적으로 사용됨)
public enum ServerConnection
{
    MasterServer,
    GameServer,
    NameServer
}


//간략하된 연결상태
public enum ConnectionState
{
    Disconnected,          //연결 끊어진 상태임
    Connecting,               //연결중
    Connected,               //연결됨
    Disconnecting,          //연결 끊는중
    InitializingApplication     //어플리케이션 초기화
}



//세부적인 네트워킹 상태
public enum PeerState
{
    Uninitialized,     //첫 사용으로, 초기화되 있지 않음. 아직 동작하지 않음.

    PeerCreated,    //생성되었고, 연결 가능함.

    Queued,           //잠깐동안 사용되지 않음.

    Authenticated,    //어플리케이션이 인증됨. PUN은 일반적으로, 바로 로비에 조인함.(AutoJoinLobby 가 FALSE로 초기화 안된 경우)

    JoinedLobby,      //마스터 서버의 로비안에 클라이언트가 있고, 방 리스트를 얻어올때.
                            // Join이 사용되어, 로비가 생성되거나, JoinRandom으로, 게임 플레이를 위해 방을 얻어오기 위해 사용


    DisconnectingFromMasterserver,     //연결 종료시

    ConnectingToGameserver,     //서버 연결중
   
     ConnectedToGameserver,     //게임 서버에 연결된 상태. 방생성이나, 방에 합류는 안됭 상태
        
    Joining,//방을 생성하거나 합류하는 중인 상태
        
    Joined,     //방을 생성하고, 합류하는 마지막 상태. 이 클라이언트는 이벤트를 변경하고, 다른 클라이언트에게 RPC 함수를 호출할 수 있다.
   
    Leaving,//방을 나갈때
       
    DisconnectingFromGameserver,   //마스터 서버에 재연결하거나, 게임 서버에서 떠날때
        
    ConnectingToMasterserver,      //마스터 서버에 연결중이고, 암호화가 수립되고, 앱이 인증될때
   
    QueuedComingFromGameserver,    //게임서버에서 온 것이  큐에 있음?
        
    Disconnecting,                       //PUN이 연결 종료되었음. 메시지 리턴후 곧 연결 종료된다.

    Disconnected,                         //연결이 설립되지 않았고, 연결 준비가 된 상태. PeerCreated와 유사하다
   
    ConnectedToMaster,                    //로비에 합류하는 것 없이 마스터 버서에 연결하는 마지막 상태(AutoJoinLobby가 false인 경우)
   
    ConnectingToNameServer,     //클라이언트가 네임서버에 연결되는 상태. 저수준 연결과, 암호화 설정이 포함된다. 잘 끝나면, 상태는 ConnectedToNameServer로 바뀐다.
   
     클라이언트는 네임서버에 연결되었고, 암호화가 이미 설립되었다. OpGetRegions() 함수나 ConnectToRegionMaster()를 호출할 수 있다.
    ConnectedToNameServer,
   
     네임서버에서 연결해제할때
    DisconnectingFromNameServer,
   
     포톤 서버에서 연결될때, 이 상태는 다른 연산이 호출하기 전에 즉시 발생한다.
    Authenticating
}


//연결 종료된 원인으로, OnConnectionFail()이나 OnFailedToConnectToPhoton()에서 사용됨.
public enum DisconnectCause
{        
    //논리 서버가 준비되지 않음
     ExceptionOnConnect = StatusCode.ExceptionOnConnect,    
    
    //클라이언트의 보안설정을 서버에서 연결 허락하지 않음.
     // http://doc.exitgames.com/photon-server/PolicyApp 참조
     SecurityExceptionOnConnect = StatusCode.SecurityExceptionOnConnect,    
                                                                                         
   
    //원격 서버가 동작하지 않거나, 블록된 포트 요청(라우터나 방화벽 원인)
     //DisconnectByClientTimeout로 변경해서 쓸것(요게 최신)
     TimeoutDisconnect = StatusCode.TimeoutDisconnect,    
                                                                        
     //클라이언트 타임아웃에 의해 연결종료(ACK이 너무 오래 걸림)
    DisconnectByClientTimeout = StatusCode.TimeoutDisconnect,
   
    //소켓 실패
     InternalReceiveException = StatusCode.ExceptionOnReceive,         
   
    //클라이언트가 서버에서 연결종료됨(DisconnectByServerTimeout로 쓰시오)
     DisconnectByServer = StatusCode.DisconnectByServer,
   
     //서버에 의해 타임아웃으로 연결 종료됨(ACK이 너무 길면 이렇게 됨)
    DisconnectByServerTimeout = StatusCode.DisconnectByServer,
   
     //서버가 이 클라이언트를 접속종료시킴
     예상원인 : 서버가 보내는 버퍼가 꽉 찼음.
    DisconnectByServerLogic = StatusCode.DisconnectByServerLogic,
   
     //유저수 제한에 따라 서버가 종료시킴(기브 미 결재. 띠링 띠링~)
    DisconnectByServerUserLimit = StatusCode.DisconnectByServerUserLimit,
        
     //몇몇 예외는 연결을 종료시킴
    Exception = StatusCode.Exception,
   
     //앱의 설명(subscription)이 환형지역 서버에서 허락하지 않기 때문에, 포톤 클라우드 인증 실패
    InvalidRegion = ErrorCode.InvalidRegion,
   
     현재 동시접속된 유저 (CCU) 제한이 설정을 넘었기 때문에 포턴클라우드에 인증 실패
    MaxCcuReached = ErrorCode.MaxCcuReached,
  
     //전송한 AppId가 포톤 클라우드에서 거절됨. 대쉬보드가서 AppID확인할 것
    InvalidAuthentication = ErrorCode.InvalidAuthentication,
   
     //인증 티켓이 만료됨. 다시 연결하도록 할것(인증은 티켓을 새로 발급받는 것을 포함함)
    AuthenticationTicketExpired = ErrorCode.AuthenticationTicketExpired,
}


//이 피어가 환형 룸(생성또는 합류된 방)에서 피어를 어떻게 얻는지에 대한 내부에서 사용되는 상태
internal enum JoinType
{
    CreateGame,               //게임생성
    JoinGame,               //게임합류
    JoinRandomGame,          //랜덤게임 합류
    JoinOrCreateOnDemand     //생성이나 합류 요청
}
```