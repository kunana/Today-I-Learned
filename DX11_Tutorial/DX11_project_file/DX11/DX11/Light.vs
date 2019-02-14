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
    

	// ?�절???�렬 계산???�해 ?�치 벡터�?4 ?�위�?변경합?�다.
    input.position.w = 1.0f;

	// ?�드, �?�??�영 ?�렬???�???�점???�치�??�​계?�합?�다.
    output.position = mul(input.position, worldMatrix);
    output.position = mul(output.position, viewMatrix);
    output.position = mul(output.position, projectionMatrix);
    
	// ?��? ?�이?�의 ?�스�?좌표�??�?�한??
	output.tex = input.tex;
    
	// ?�드 ?�렬???�?�서�?법선 벡터�?계산?�니??
    output.normal = mul(input.normal, (float3x3)worldMatrix);
	
    // 법선 벡터�??�규?�합?�다.
    output.normal = normalize(output.normal);

    return output;
}