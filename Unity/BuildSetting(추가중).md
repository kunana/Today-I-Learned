<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [TIL/16-06-01](#til16-06-01)
  - [Unity](#unity)
    - [안드로이드 빌드세팅](#%EC%95%88%EB%93%9C%EB%A1%9C%EC%9D%B4%EB%93%9C-%EB%B9%8C%EB%93%9C%EC%84%B8%ED%8C%85)
      - [identification 부분](#identification-%EB%B6%80%EB%B6%84)
      - [Publishing Setting 부분](#publishing-setting-%EB%B6%80%EB%B6%84)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# TIL/16-06-01
  ## Unity
    ### BuildSetting  < C# >

### 안드로이드 빌드세팅

1. 안드로이드 SDK 에서 원하는 버전 을 설치해줌.
2. 유니티 Edit - PreFerences 에서 SDK, JDK 의 설치된 경로를 정해줌

#### identification 부분

1. Bundle identifier
com.CompanyName.ProductName
앱의 고유 ID 이며, Bundle Version 이 같다면 충돌한다.
한글이나, 맨앞에 숫자를 넣지않아야한다.

2. Version
사용자가에 외부에서 보이는 시각적인 Version

3. Bundle Version Code
내부적으로 확인하는 Version 같은 앱의 업데이트 때마다 올려줘야
충돌하지않고 잘 설치된다.

4. Minimum Api Level
최소 호환가능 안드로이드 버전
2018 년 기준 최소 4.4로 잡아줌
5. Minimum Api Level
최대 호환 가능 안드로이드 버전
Auto.

#### Publishing Setting 부분

1. Ketstore

안드로이드 시스템에서는 Key Signing 이 매우 중요하다. 구글 플레이에서는
이 키 사이닝으로 이 앱이 신뢰할수 있는 앱인지, 제작과는 누구인지 판단하는 제1의 근거가 되기 때문이며, 키사이닝이 되지않은 앱 은 안드로이드 시스템에 설치할수 없기 때문에 반드시 설치해야한다.
원하는 비밀번호를 설정후 세팅.

```
Typing Code

```
