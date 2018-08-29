> ## 기본적인 RPC 사용법

```csharp

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

//Photon.PunBehaviour 상속. 
//this.PhotonView.RPC() 로 사용가능
//PhotonView 컴포넌트가 있어야함
public class RPC : Photon.PunBehaviour {

    private Text ChatBox;
    private GameObject Box;

    //버튼 클릭시
    public void OnClick_Send()
    {   
        ///함수명(string),원하는 타겟, 파라미터
        this.photonView.RPC("Msg", PhotonTargets.All, "Hello World!"); //모든클라이언트가 즉시 RPC실행. 나중에 들어온 플레이어는 실행안함, 지연없음

        this.photonView.RPC("Msg", PhotonTargets.Others, "Hello World!"); //현재클라이언트를 제외한 나머지. 나중에 들어온 플레이어는 실행안함, 지연없음

        this.photonView.RPC("Msg", PhotonTargets.MasterClient, "Hello World!"); //마스터클라이언트에게만. 마스터 접속끊어질때를 유의., 지연없음

        this.photonView.RPC("Msg", PhotonTargets.AllBuffered, "Hello World!"); //Buffered.  나중에 들어온 플레이어도  RPC를 받음, 지연없음

        //서버를 거쳐 RPC실행. RPC가 순서대로 실행되어야 할때 사용. 숏컷사용안함
        //예를 들어 레이싱 게임에서 누가 먼저 완주했는지를 호출해야할때.
        //숏컷이란 네트워크상의 문자열 전송은 비효율적이기 때문에, 문자열을 줄여서 전송함
        //스크립트상의 RPC를 감지하고 목록을 컴파일함. 각 메소드는 리스트를 통해 ID를 얻고 아래와 같이 string으로 메소드 호출.
        //백엔드 상에서는 ID로 메소드 호출
        //RPC 목록은 PhotonServerSettings 에서 관리
        this.photonView.RPC("Msg", PhotonTargets.AllViaServer, "Hello World!");


        //다른 단일플레이어에게 사용가능
        PhotonPlayer[] other = PhotonNetwork.otherPlayers;
        foreach (var player in other)
        {
            this.photonView.RPC("Msg", player, "Hello World!"); 
        }

        //RPC는 호출즉시 전송안됨. 객체 동기화 주기가 될때까지 버퍼링되며, 전송 주기가 되야 전송함
        //이런 지연을 없애기 위해 업데이트 루프를 중지하고 바로 RPC를 전송.
        PhotonNetwork.SendOutgoingCommands();

        //특정 플레이어가 나가면 RPC를 제거하여 버퍼를 줄임
        PhotonNetwork.RemoveRPCs(other[1]);

        //특정그룹의 RPC를 제거
        PhotonNetwork.RemoveRPCsInGroup(0);

        

    }

    //다른 클라이언트에게 보내고자 하는 함수는 PunRPC를 달아주자.
    [PunRPC]
    private void Msg(string MSG)
    {
        ChatBox.text += "/n " + MSG;
    }

    //로컬 생성 방법
    //RPC로 다른클라이언트도 생성하고, 이 오브젝트를 통해 PhotonView를 사용하기 위해 ViewID를 꼭 할당해준다.
    [PunRPC]
    private void MakeNewOne()
    {
        GameObject OBJ = Instantiate(Box, transform, false);
        var Id = OBJ.AddComponent<PhotonView>();
        Id.ViewId = 5;
    }

    //서버를 통하여 생성, Resources 폴더에 해당 이름의 프리팹이 있어야함
    private void MakeNewTwo()
    {
        PhotonNetwork.Instantiate(Box.ToString(), Vector3.zero, Quaternion.identity, 0);
    }

    //씬이 소요하고 있는 프리팹 마지막 남은 플레이어가 나갈때 까지 존재
    //마스터 클라이언트가 제어가능
    private void MakeNewThree()
    {
        PhotonNetwork.InstantiateSceneObject(Box.ToString(), Vector3.zero, Quaternion.identity, 0 ,null);

        //룸 이벤트 버퍼를 자동으로 제거할까? 위 코드 (인스턴스화) 의 대안
        PhotonNetwork.autoCleanUpPlayerObjects = true;
    }

}

```