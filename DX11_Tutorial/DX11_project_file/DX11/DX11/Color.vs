/////////////
//  Global //
/////////////
cbuffer MatrixBuffer
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
};


/////////////
// Typedef //
/////////////

struct vertexInputType
{
	float4 position : POSITION;
	float4 color : COLOR;
};

struct pixelInputType
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
};

//////////////////////////
// Vertex Shader		//
//////////////////////////
pixelInputType colorVertexShader(vertexInputType input)
{
	pixelInputType output;

	//적절한 행렬 계산을 위해 위치 벡터를 4단위로 변경합니다.
	input.position.w = 1.0f;

	//월드 , 뷰, 투영 행렬에 대한 정점의 위치를 계산합니다.
	output.position = mul(input.position, worldMatrix);
	output.position = mul(output.position, viewMatrix);
	output.position = mul(output.position, projectionMatrix);

	//픽셀 쉐이더가 사용할 입력 색상을 저장합니다.
	output.color = input.color;
	
	return output;
}
