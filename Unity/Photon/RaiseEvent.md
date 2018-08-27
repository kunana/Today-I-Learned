```csharp
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//특정이벤트를 보기 쉽게 명명
enum Events
{
    ChangeColor = 0,
}

///<summary>
///특정그룹에게 특정 이벤트를 실행
///포톤 자체가 많은양의 데이터를 보내기에 부적절하다고 함.
///클래스를 직렬화 해서 보내지는지 확인 필요
///안되면 Json 으로 직렬화 해서 사용.
///</summary>
[RequireComponent(typeof(SpriteRenderer), typeof(PhotonView))]
public class RaiseEvent : Photon.MonoBehaviour
{
    private SpriteRenderer ren;

    private void Awake()
    {
        ren = GetComponent<SpriteRenderer>();
    }

    private void OnEnable()
    {
        PhotonNetwork.OnEventCall += PhotonNetwork_OnEventCall; // 이 스크립트가 존재하는 순간부터 이벤트콜. 
    }

    private void PhotonNetwork_OnEventCall(byte eventCode, object content, int senderId) // 이벤트 수신 함수
    {
        Events events = (Events)eventCode; //Enum 이벤트 캐싱

        if (events == Events.ChangeColor) // 명명된 이벤트가 맞다면
        {
            object[] datas = content as object[]; //전송받을 데이터 

            if (datas.Length == 4) // 데이터가 정해진 포맷인지 확인
            {
                if ((int)datas[0] == base.photonView.viewID) // ID를 비교해 자신의 ID의 객체만 실행 하도록.
                    ren.color = new Color((float)datas[0], (float)datas[1], (float)datas[2]); //object 이기에 원하는 타입으로 캐스트 후 색 변경
            }
        }
    }

    private void Update()
    {
        if (base.photonView.isMine)
        {
            if (Input.GetKeyDown(KeyCode.Space))
                ColorChange();
        }
    }
    void ColorChange()
    {
        float r, g, b;
        r = Random.Range(0, 1f);
        g = Random.Range(0, 1f);
        b = Random.Range(0, 1f);

        object[] datas = new object[] { base.photonView.isMine, r, b, g };

        RaiseEventOptions op = new RaiseEventOptions() //포톤옵션을 설정
        {
            CachingOption = EventCaching.DoNotCache,    //캐시하지않음
            Receivers = ReceiverGroup.All,  //모두

            //CachingOption = EventCaching.AddToRoomCache, //서버의 캐시에 있다가 새플레이어가 오면 이벤트를 받음 순서대로.
            //CachingOption = EventCaching.AddToRoomCacheGlobal, //룸의 이벤트 캐시에 있음 이 이벤트는 캐시에서 제거 되지않음
            //CachingOption = EventCaching.DoNotCache, // 캐시하지 않음
            //CachingOption = EventCaching.RemoveFromRoomCacheForActorsLeft, //특정플레이어가 나가면 캐시를 지움
            //CachingOption = EventCaching.RemoveFromRoomCache,
            //Receivers = ReceiverGroup.All, //받는 클라이언트;
        };

        //원하는 이벤트 명, 실제 보낼 데이터, 신뢰할만한 수신인가, 옵션
        PhotonNetwork.RaiseEvent((byte)Events.ChangeColor, datas, false, op);
    }
}


```