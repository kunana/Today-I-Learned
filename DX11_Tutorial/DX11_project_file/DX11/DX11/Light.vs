////////////////////////////////////////////////////////////////////////////////
// Filename: Light.vs
////////////////////////////////////////////////////////////////////////////////


/////////////
// GLOBALS //
/////////////
cbuffer MatrixBuffer
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
};


//////////////
// TYPEDEFS //
//////////////
struct VertexInputType
{
    float4 position : POSITION;
    float2 tex : TEXCOORD0;
    float3 nomal : NORMAL;
};

struct PixelInputType
{
    float4 position : SV_POSITION;
    float2 tex : TEXCOORD0;
	float3 nomal : NORMAL;
};


////////////////////////////////////////////////////////////////////////////////
// Vertex Shader
////////////////////////////////////////////////////////////////////////////////
PixelInputType LightVertexShader(VertexInputType input)
{
    PixelInputType output;
    

	// ������ ��� ����� ���� ��ġ ���͸� 4 ������ �����մϴ�.
    input.position.w = 1.0f;

	// ����, �� �� ���� ��Ŀ� ���� ������ ��ġ�� ??����մϴ�.
    output.position = mul(input.position, worldMatrix);
    output.position = mul(output.position, viewMatrix);
    output.position = mul(output.position, projectionMatrix);
    
	// �ȼ� ���̴��� �ؽ�ó ��ǥ�� �����Ѵ�.
    output.tex = input.tex;
    
	//���� ��Ŀ� ���ؼ��� ���� ���͸� ����մϴ�
	output.normal = mul(input.normal, (float3x3)worldMatrix);

	//���� ���͸� ����ȭ �մϴ�
	output.normal = normalize(output.normal);

    return output;
}