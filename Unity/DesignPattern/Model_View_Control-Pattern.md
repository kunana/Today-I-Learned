<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [TIL   / 2018-06-01](#til----2018-06-01)
  - [Unity - Programming Pattern](#unity---programming-pattern)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# TIL   / 2018-06-01
  ## Unity - Programming Pattern
    ### Model_View_Control-Pattern < C# >

 # Model View Contorl Pattern< C# >
 
> "개발자가 구현 하는 구체적인 클래스의 커플링 없이, 특정 서비스에 접근 할수 있는 전역 지점을 만들어 주는 것"

<br>

### Resources.Load

리소스 로드에는 비용이 꽤나 든다. 예를 들어서 SpriteRenderer 에 이미지를 넣을때, 스프라이트 렌더러를 생성하고, 이미지를 Resources.load 를 업데이트 때나 불러준다면? 프레임을 저하시킬 것이다.

#### 비용을 줄이기 위해선?

1. Resources.load 를 할 리소스를 미리 캐싱해서 사용한다.

2. Texture DB 를 만든다.
> 
> [MVC] Unity with MVC: How to Level Up Your Game Development
<br>(https://www.toptal.com/unity-unity3d/unity-with-mvc-how-to-level-up-your-game-development)

프로그래머의 첫시작은 대개 'Hello World' 부터 배우기 시작한다. 
