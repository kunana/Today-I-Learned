<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [TIL   / 2018 - 07 - 18](#til----2018---07---18)
  - [Unity](#unity)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# TIL   / 2018 - 07 - 18
  ## Unity
    ### Shader < C# >

    ## 빛

    ### 빛의 종류
    > 빛의 종류에는 Ambient Light , Directional Light, Point LIght, Spot Light 가 있다.

    - 물체를 밝히기 위해서는 빛이있다. 빛도 있으면 그림자도있다.
    - 유니티에서는 이 명암을 계산하기 위해서, 빛의 강도, 방향, 색의 정보가 필요하다.

    > 1. 동적조명 (RealTime Lighting)
      - Directional, Spot ,Point Lighting 을 매프레임 실시간 업데이트.
      - 가장 기본적인 방법으로 움직이는 사물을 비추는데 적합
      - 이 동적 조명에서 방출한 빛은 일단 방출되면 반사되지않으며, 좀 더 사실적인 빛의 표현을 위해서는 전역조명(Global Illumination) 등의 기법을 사용

    > 2. 베이크드 라이트 (Pre-Computed Lighting)   
      - light map = 조명과 그림자의 실시간 연산에 따른 비용를 줄이기 위해서 미리 조명과 그림자연산이 계산되어있는 2D 텍스쳐를 만들어 입히거나, 참조용 텍스쳐맵에 보존
      - 정적인 오브젝트의 광원을 계산하여, Scene 속 지오메트리 상에 텍스쳐로서 오버라이드됨.
      - Static 의 속성이므로 게임플레이중에 변경이 불가하다.
      - Normal Map 참고

    > 1. 주변광(환경, Ambient Light)
    예를 들어 태양빛을 받았을때 그림자가 완전히 어둡지 않다. 이를 산란이나 분산에 따라 빛이 그림자에 생기는 것인데, 이름 통틀어서 주변광이라고 한다.

    -  연산이 거의 없지만 명암이 없기에 단조로워 보인다.
    - 한마디로 아무리 광원이 없어도 빛이 존재하는것.

    > 2. 직사광  - Directional Light

    - 위치는 존재하지않고 방향만 존재하는 빛.  즉, 어느 위치에서라도 일정한 방향을 가지는 빛. 태양.
    - 이 방향을 받은 존재(빛을 받은 오브젝트)만 연산을 한다.

    > 3. Point Light - 횟불이나 전구같은것.

    - 위치는 있지만 방향은 존재하지않는것.
    - 사방으로 퍼져나가는 빛, 그래서 연산이 조금 더 느림.
    - 즉, 감쇄가 이루어져서 느리기 때문인데 세가지 정도의 감쇄의 효과가 있다.

    + 감쇄 효과에 대해 추가할것.

    > 4 . Spot Light

    - 비용을 많이 먹어서 거의 안쓴다.
    - 방향 위치 모두 존재함.
    - 예를 들어 손전등 처럼 광원 가운데는 빛이 세고,  주변은 약한것이며, 멀어지면 감쇄한다
    -  각도에 따라 빛이 받는 양이 다름. 그렇기 때문에 인게임에서 플래쉬 효과를 낼때에는 이미지를 넣고 블렌드 효과를 준다.

    > 5. 자체발광.
    태양과 같은것.


    ### 빛의 속성

    > 1. Difuse = 빛의 색상

    Amibient 가 포함됨.( 빛이 받지않는 곳은 무슨색상으로 할것인지)

    > 2. Specular = 제일 밝게 반사되는 반사광이 무슨색상인지.

    - 각 물체들은 Meterial 이 있고, Meterial 에 따라서 반사가 달라짐.
    - 빛이 많아질수록 느려짐

    ### 정점 법선
    빛을 받아 반사하는 각도를 설정해야 한다. 법선은 표면의 수직인 벡터를 말한다.

    ###Texture,
    + 추가할것.
    vertex+RGB * UV
    UV == XY,
    UV좌표를 입력해서 원하는곳의 텍스쳐를 입힐수있다.
