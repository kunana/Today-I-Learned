<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [TIL   / 2016-06-01](#til----2016-06-01)
  - [Unity](#unity)
    - [Optimization](#optimization)
      - [간단 세팅](#%EA%B0%84%EB%8B%A8-%EC%84%B8%ED%8C%85)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# TIL   / 2016-06-01
  ## Unity
    ### Optimization  < C# >

(추가중)

### Optimization

(https://ijemin.com/blog/%EC%9C%A0%EB%8B%88%ED%8B%B0-2d-%EA%B2%8C%EC%9E%84-%EB%B9%8C%EB%93%9C-%EC%B5%9C%EC%A0%81%ED%99%94-%ED%8C%81/ 참조)
#### 간단 세팅

1.  Application.targetFrameRate = 60;
이상이 없다면 vSyncCount 를 Quality 설정에서 켭니다. 몇몇 안드로이드 기기에서는 60fps 이상 랜더하여 기기가 과열되는 것을 막아줍니다.
비어있는 유니티 메세지 함수들은 지우세요. Update 등의 함수 내부가 비어있어도, 호출은 계속 됩니다.
GameObject.Find() 같이 씬 전체를 검색하는 함수를 되도록 쓰지 마세요.
Update/FixedUpdate 에서는 절대 안됩니다.
사용하지 않는 게임 오브젝트는 미리 비활성화 하세요.
오브젝트를 실시간으로 파괴하는 것보다, 비활성화 하는게 비용이 싸다는 것을 알아두세요.
