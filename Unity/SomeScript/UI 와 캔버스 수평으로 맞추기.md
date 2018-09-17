
># UI 와 캔버스 수평으로 맞추기

> ## 캔버스의 PlaneDistance 를 받아 Z값을 맞추고, UI를 마우스 포지션으로.

### From To의 축이 같다는 전제하에 두벡터의 Z를 가져와서 각도를 구함
```csharp
 // z값을 캔버스 Plane Distance 값 줌
 var screenPoint = new Vector3(Input.MousePosition.x, Input.MousePosition.y, PlaneDistance); 
 transform.position = Camera.main.ScreenToWorldPoint(screenPoint);
```
<br>
