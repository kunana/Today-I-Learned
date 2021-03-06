////////////////////////////////////////////////////////////////////////////////
// Filename: light.vs
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
	float3 normal : NORMAL;
};

struct PixelInputType
{
    float4 position : SV_POSITION;
    float2 tex : TEXCOORD0;
	float3 normal : NORMAL;
};


////////////////////////////////////////////////////////////////////////////////
// Vertex Shader
////////////////////////////////////////////////////////////////////////////////
PixelInputType LightVertexShader(VertexInputType input)
{
    PixelInputType output;
    

	// ?μ ???λ ¬ κ³μ°???ν΄ ?μΉ λ²‘ν°λ₯?4 ?¨μλ‘?λ³κ²½ν©?λ€.
    input.position.w = 1.0f;

	// ?λ, λ·?λ°??¬μ ?λ ¬??????μ ???μΉλ₯??βκ³?°ν©?λ€.
    output.position = mul(input.position, worldMatrix);
    output.position = mul(output.position, viewMatrix);
    output.position = mul(output.position, projectionMatrix);
    
	// ?½μ? ?μ΄?μ ?μ€μ²?μ’νλ₯???₯ν??
	output.tex = input.tex;
    
	// ?λ ?λ ¬????΄μλ§?λ²μ  λ²‘ν°λ₯?κ³μ°?©λ??
    output.normal = mul(input.normal, (float3x3)worldMatrix);
	
    // λ²μ  λ²‘ν°λ₯??κ·?ν©?λ€.
    output.normal = normalize(output.normal);

    return output;
}