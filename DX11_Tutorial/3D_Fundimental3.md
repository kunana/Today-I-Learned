<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [TIL   / 2018 -05-09](#til----2018--05-09)
  - [Unity](#unity)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# TIL   / 2018 -05-09
  ## Unity
    ### DirectX< C# >

> GPU 파이프라인 
GPU 는 병렬로 분산 처리 하기 때문에 픽셀 에 대한 처리를 빠르게 할수 있다.


> 삼각형 그리기

 1. GPU에 렌더링 한다. 
 2. 삼각형의 세 꼭지점을 만든다. 
 3. 정점을 비디오 메모리에 저장한다. 
 4. GPU에 정점을 읽는 방법을 알려준다.
 5. 삼각형을 렌더링 한다.

> shader 로드

 1. shader 파일에서 두 개의 셰이더를 로드한다.
 2. 로드 후 컴파일 한다. 
 3. 두 셰이더를 셰이더 개체로 캡슐화 한다. 
 4. 두 셰이더를 활성 셰이더로 설정한다.
 

> 1. 틀과 버텍스, 픽셀 쉐이더, 버텍스 버퍼를 가져옴

![](/img/2018-11-28-15-27-22.png)


> Flexible Vertex foam
> 
![](/2018-11-28-15-28-51.png)
vertex 를 정의할때 점의 속성(X,Y,Z,W) 을 지정해주어야함

![](/img/2018-11-28-15-40-40.png)
일단은 위치와 컬러만 지정해주자

![](/img/2018-11-28-15-34-16.png)

렌더링 속도를 향상시키기 위해 각 정점에 저장된 정보를 선택할 수 있다. 입력 레이아웃은 GPU가 데이터를 적절하고 효율적으로 구성 할 수 있도록 버텍스 구조체의 레이아웃을 포함하는 객체다.

![](/img/2018-11-28-15-34-43.png)

 구조체의 내용과 그릴 내용을 일치시킨다. 

 Position의 x,y,z 값 § Color 값. § 위와 같이 적용 후 Direct3D에 입력시킨다.

![](/img/2018-11-28-15-45-05.png)

이후 렌더프레임 함수에서 렌더 해주고,

![](/img/2018-11-28-15-46-17.png)

WinMain 함수에서 RenderFrame() 함수를 불러준다.
 

> 사각형 그리기

버텍스를 그리는 순서 참고.

![](![](/img/2018-11-28-17-11-35.png)%20.png)