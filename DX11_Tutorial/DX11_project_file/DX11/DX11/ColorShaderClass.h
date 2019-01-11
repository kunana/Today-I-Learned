#pragma once

class ColorShaderClass : public AlignedAllocationPolicy<16>
{
private:
	struct matrixBufferType
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
	};

public:
	ColorShaderClass();
	ColorShaderClass(const ColorShaderClass&);
	~ColorShaderClass();

	bool initialize(ID3D11Device* device, HWND hwnd);
	void shutDown();
	bool render(ID3D11DeviceContext* deviceContext, int indexCount, XMMATRIX worldMat, XMMATRIX viewMat, XMMATRIX projectionMat);

private:
	bool initializeShader(ID3D11Device* device, HWND hwnd, const WCHAR* vsFileName, const WCHAR* psFileName);
	void shutdownShader();
	void outputShaderErrorMessage(ID3D10Blob* errorMessage, HWND hwnd, const WCHAR* shaderFileName);

	bool setShaderParameters(ID3D11DeviceContext* deviceContext, XMMATRIX worldMat, XMMATRIX viewMat, XMMATRIX projectionMat);
	void renderShader(ID3D11DeviceContext* deviceContext, int indexCount);

private:
	ID3D11VertexShader* m_vertexShader = nullptr;
	ID3D11PixelShader* m_pixelShader = nullptr;
	ID3D11InputLayout* m_inputLayout = nullptr;
	ID3D11Buffer* m_matrixBuffer = nullptr;
};
