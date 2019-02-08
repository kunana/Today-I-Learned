<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [TIL   / 2018-08-20](#til----2018-08-20)
- [Mediator Pattern, or Service Locater< C# >](#mediator-pattern-or-service-locater-c-)
- [Motivation](#motivation)
    - [이것이 바로 서비스 중개자 패턴의 핵심이다.](#%EC%9D%B4%EA%B2%83%EC%9D%B4-%EB%B0%94%EB%A1%9C-%EC%84%9C%EB%B9%84%EC%8A%A4-%EC%A4%91%EA%B0%9C%EC%9E%90-%ED%8C%A8%ED%84%B4%EC%9D%98-%ED%95%B5%EC%8B%AC%EC%9D%B4%EB%8B%A4)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# TIL   / 2018-08-20

  # Mediator Pattern, or Service Locater< C# >
 
> "개발자가 구현 하는 구체적인 클래스의 커플링 없이, 특정 서비스에 접근 할수 있는 전역 지점을 만들어 주는 것"

<br>

# Motivation

게임의 객체나 일부 시스템의 코드에서는 거의 모든 코드에서 사용되는 부분들이 있다. 예를 들어 메모리 할당이나, 물리, 로그 생성, 등과 같은 것을 말한다. 

이런 시스템은 전체 게임에서 사용할 수 있어야 하는 '서비스'로 생각 할수 있다.

예를 들어서 오디오 를 생각 해보자. 메모리 할당과 같은 저 수준의 시스템 만큼은 아니지만, 그래도 여러가지 게임 시스템들과 닿아있다. 

>+ 돌이 땅에 떨어져서 부딪힐때 ( 물리 )
>+ 스나이퍼 NPC 가 총을 쏠때 ( AI )
>+ 사용자 와 유저 인터페이스가 상호작용할때, ( UI )

와 같이 말이다. 이 시점에서, 위와 같은 시스템들은 오디오 시스템을 호출 할수 있어야 한다. 

```csharp
//정적인 클래스를 쓰기도,
AudioSystem.playSound(VERY_LOUD_SOUND);

//싱글턴을 쓸수도 있다.
AudioSystem.instance.playSound(VERY_LOUD_SOUND);
```
둘다 우리가 원하는 바를 얻을수 있지만, 그 과정에서 강한 커플링이 생기기 마련이다.

오디오 시스템을 호출하는 모든곳에서 AudioSystem 이라는 구체적인 클래스 부터, static과 같은 정적 클래스, 또는 싱글턴처럼 AudioSystem 으로 접근하는 매커니즘 까지 직접 참조하게 된다.

위와 같이 사운드를 재생하려면 무언가와 결합 해야 겠지만, 직접적으로 오디오를 구현한 구체 클래스를 가르키는 것은, 

당신이 문앞에서 우편물 하나 받으려고, 수 많은 이방인들에게 길안내를 하는 것과 다를바 없다. 

각각의 사람들에게 매번 새롭게 길안내를 해주면서 당신이 움직이는것은 정말로 고통스럽다.

더 좋은 방법이 있다.

전화번호부이다. 
우릴 필요로 하는 사람이 우리의 이름과 주소를 찾으면 되는 것이다.

우리가 이사를 가면? 전화국에 주소가 바뀌었으니 새로 업데이트 하라고 이야기 하면된다.

즉, 전화번호부 를 통해 우리를 찾을 방법을 한 곳에서 편리하게 관리할수 있는 것이다.

### 이것이 바로 서비스 중개자 패턴의 핵심이다.
 

