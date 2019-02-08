<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [From To의 축이 같다는 전제하에 두벡터의 Z를 가져와서 각도를 구함](#from-to%EC%9D%98-%EC%B6%95%EC%9D%B4-%EA%B0%99%EB%8B%A4%EB%8A%94-%EC%A0%84%EC%A0%9C%ED%95%98%EC%97%90-%EB%91%90%EB%B2%A1%ED%84%B0%EC%9D%98-z%EB%A5%BC-%EA%B0%80%EC%A0%B8%EC%99%80%EC%84%9C-%EA%B0%81%EB%8F%84%EB%A5%BC-%EA%B5%AC%ED%95%A8)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->


># UI 와 캔버스 수평으로 맞추기

> ## 캔버스의 PlaneDistance 를 받아 Z값을 맞추고, UI를 마우스 포지션으로.

### From To의 축이 같다는 전제하에 두벡터의 Z를 가져와서 각도를 구함
```csharp
 // z값을 캔버스 Plane Distance 값 줌
 var screenPoint = new Vector3(Input.MousePosition.x, Input.MousePosition.y, PlaneDistance); 
 transform.position = Camera.main.ScreenToWorldPoint(screenPoint);
```
<br>
