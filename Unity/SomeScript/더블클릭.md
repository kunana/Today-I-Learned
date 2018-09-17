```csharp

//클릭한 마지막 시간 저장
private float timeOfLastClick;
//더블 클릭을 가능한 최초클릭 이후 시간
private const float ClickDeltaForDoubleclick = 0.2f;


    // called by InputToEvent.
    // we use a short timeout to detect double clicks.
    // on double click, the networked object gets destroyed (on all clients).
    private void OnClick()
    {
        if (!this.photonView.isMine)
        {
            // this networkView (provided by Photon.MonoBehaviour) says the object is not ours.
            // so this client can't destroy it.
            return;
        }
        
        //더블클릭코드
        if (Time.time - this.timeOfLastClick < ClickDeltaForDoubleclick)
        {   
            //Do SomeThing
            // double click => destory in network
            PhotonNetwork.Destroy(gameObject);
        }
        else
        {
            this.timeOfLastClick = Time.time;
        }
    }
```