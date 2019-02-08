<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [TIL   / 2018 -05-09](#til----2018--05-09)
  - [Unity](#unity)
  - [3D 이론 + DirectX](#3d-%EC%9D%B4%EB%A1%A0--directx)
    - [PixelShader & Vertex Shader](#pixelshader--vertex-shader)
    - [float4 & float4x4 (Matrix, 행렬)](#float4--float4x4-matrix-%ED%96%89%EB%A0%AC)
- [Z - BUFFER](#z---buffer)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# TIL   / 2018 -05-09
  ## Unity
    ### DirectX 와 Unity3D < C# >

1.   PixelShader(픽셀쉐이더) 와 VertexShader(정점 쉐이더)에 대해 + 파이프라인
2.  4x4 Matrix(행렬) 과 CONST BUFFER (상수버퍼)
3.  빛의종류 와 빛의 속성

+ 참고 (https://kblog.popekim.com/2011/12/02-part-1.html)

## 3D 이론 + DirectX

### PixelShader & Vertex Shader
> 쉐이더란 화면에 출력할 픽셀의 위치와 색상을 계산하는 함수
 픽셀쉐이더란 픽셀의 농담, 색조, 명암을 결정한다.(RGBA값)
 정점쉐이더는 정점들의 위치를 좌표로 변환, 공간변환해준다.

>  3D_PipeLine

![3dpipeline](./Pic/GPUPipeLIne.jpg)

1.  3D 모델은 폴리곤(다각형) 으로 구성하는것이 표준, 삼각형들의 집합으로 여러가지 도형들을 나타낸다.
2. 삼각형은 3개의 정점으로 이루어짐 (Vertex, 꼭짓점)
3.  VertexShader는 정점들의 위치를 좌표로 변환하는 것이며, 모든 정점을 <공간변환> 하는것이며  정점의 수만큼 실행된다.  이 VertexData 들을 3개씩 그룹지으면 삼각형을 만들수있다. (시계방향으로 그려줌)
 4. 화면을 구성하는것은 많은 수의 Pixel이며, 이 Pixel을 어디에 몇개나 그려야 하는지를 Rasterizer(래스터라이저) 가 해준다.
5. 래스터라이저가 만든 삼각형에 PixelShader 가 화면에 출력할 최종 색상을 계산하는 것임.

> <공간변환>

1. 한 물체의 중심을 원점으로 삼고, 시작으로 직교하는 벡터를 만듬,
원점 부터 물체의 표면까지의 거리를 재면 x,y,z (벡터) 가 나옴  = Local Space
2. 한 공간을 중심을 원점으로 삼고, 벡터를 만들어서 공간안의 물체들의 벡터 까지 거리를 잼
= World Space

3. 카메라 렌즈의 중앙을 원점으로 삼고,  벡터를 만듬.
카메라의 위치에 따라 여러물체들이 보이거나 보이지않음, = View Space

4. 사람의 눈과 같이 카메라의 화각에 따라, 멀리바라볼수록 물체를 바라보는 범위가 넓어지고, 크기가 작아짐,  = Orthogonal Projection
5. 정점의 위치벡터에 공간 행렬을 곱한다.
6.
물체공간 ----------> 월드공간 --------> 뷰공간 ---------> 투영공간
--------ⅹ월드행렬-------------ⅹ뷰행렬----------ⅹ투영행렬


### float4 & float4x4 (Matrix, 행렬)

-  float4: 4개의 성분을 가지는 벡터 데이터형
- float4x4: 4 X 4 행렬 데이터형
- mul(): 곱하기 함수. 거의 모든 데이터형을 변수로 받음.
- POSITION: 정점위치 시맨틱. 정점데이터 중 위치정보만을 불러옴.

- float4 는 (X, Y, Z, W) 를 가지는 벡터,


```
// 정점데이터에서 위치정보를(POSITION) 을 mPosition 에 대입
struct VS_INPUT
{
    float4 mPosition : POSITION;
};

// 위에 월드행렬, 뷰행렬, 투영행렬은 각 정점마다 값이 변하지않으니, 전역변수로 선언해서 사용
float4x4 gWorldMatrix;
float4x4 gViewMatrix;
float4x4 gProjectionMatrix;
```

> 이론적인 부분 (DirectX)

다이렉트 X에서 카메라와 카메라의 일정 화각이 있고, 오브젝트가 있다고 하자.
유니티의 경우 오브젝트의 오더레이어에 따라서 보이는 순서가 결정되지만
다이렉트 X는 일일히 설정  해줘야한다. 그렇지 않으면 기본값으로 제일 뒤에있는 오브젝트 부터 그려진다.
이를 Z-buffer , 혹은 depth-buffer 라고 한다.
UI의 경우 Z버퍼를 끄고 세팅, 오브젝트의 경우 Z버퍼를 켜고 설정해줘야 오브젝트가 UI를 가리는 경우가 생기지 않는다.
즉 여러가지 오브젝트들이 겹치는 경우가 있기에 그에따라 Z-buffer 를 켜거나 꺼줘야한다.

# Z - BUFFER
각프레임마다 깊이 버퍼를 측정해줘야 되기때문 하드웨어에서 는 깊이버퍼라는 것을 지원 해준다.
화면의 픽셀과 거리를 추적하는 데 쓰는 버퍼이며 깊이 버퍼도 텍스쳐 이다.

> 이동행렬, 크기행렬, 회전행렬
