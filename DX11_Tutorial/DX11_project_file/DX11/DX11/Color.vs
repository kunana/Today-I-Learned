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

	//������ ��� ����� ���� ��ġ ���͸� 4������ �����մϴ�.
	input.position.w = 1.0f;

	//���� , ��, ���� ��Ŀ� ���� ������ ��ġ�� ����մϴ�.
	output.position = mul(input.position, worldMatrix);
	output.position = mul(output.position, viewMatrix);
	output.position = mul(output.position, projectionMatrix);

	//�ȼ� ���̴��� ����� �Է� ������ �����մϴ�.
	output.color = input.color;
	
	return output;
}
