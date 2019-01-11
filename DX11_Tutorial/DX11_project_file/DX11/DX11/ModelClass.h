#pragma once
class ModelClass : public AlignedAllocationPolicy<16>
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT4 color;
	};

public:
	ModelClass();
	ModelClass(const ModelClass&);
	~ModelClass();

	bool initialize(ID3D11Device* device);
	void shutDown();
	void render(ID3D11DeviceContext* deviceContext);

	int getIndexCount();

private:
	
	bool initializeBuffer(ID3D11Device* device);
	void shutdownBuffers();
	void renderbuffers(ID3D11DeviceContext* deviceContext);

private:
	ID3D11Buffer* m_vertexBuffer = nullptr;
	ID3D11Buffer* m_indexBuffer = nullptr;
	int m_vertexCount = 0;
	int m_indexCount = 0;
};