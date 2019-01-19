#pragma once

class LightShaderClass : public AlignedAllocationPolicy<16>
{
private:
	struct MatrixBufferType
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
	};

	struct LightBufferType
	{
		XMFLOAT4 diffuseColor;
		XMFLOAT3 lightDirection;
		float padding; // 구조체가 createBuffer 함수 요구 사항에 대해 16의 배수가 되도록 여분의 패딩을 추가
	};
public:
	LightShaderClass();
	LightShaderClass(const LightShaderClass&);
	~LightShaderClass();
	
	bool initialize(ID3D11Device* device, HWND hwnd);
	void shutdown();
	bool Render(ID3D11DeviceContext*, int, XMMATRIX worldmat, XMMATRIX viewMat, XMMATRIX projectionMat,
		ID3D11ShaderResourceView*, XMFLOAT3 lightDir, XMFLOAT4 diffuseColor);
private:
	bool initializeShader(ID3D11Device* device, HWND hwnd, WCHAR* vsFilename, WCHAR* psFileName);
private:
};
 