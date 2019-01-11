#include "stdafx.h"
#include "ModelClass.h"

ModelClass::ModelClass()
{
}

ModelClass::ModelClass(const ModelClass &)
{
}

ModelClass::~ModelClass()
{
}

bool ModelClass::initialize(ID3D11Device * device)
{	
	//���� �� �ε��� ���۸� �ʱ�ȭ�մϴ�
	return initializeBuffer(device);
}

void ModelClass::shutDown()
{
	//���ؽ� �� �ε��� ���۸� �����մϴ�.
	shutdownBuffers();
}

void ModelClass::render(ID3D11DeviceContext * deviceContext)
{
	//�׸��⸦ �غ��ϱ� ���� �׷��� ������ ���ο� �������� �ε��� ���۸� �����ϴ�.
	renderbuffers(deviceContext);
}

int ModelClass::getIndexCount()
{	
	return m_indexCount;
}

bool ModelClass::initializeBuffer(ID3D11Device * device)
{
	//���� �迭�� ���� ���� �����մϴ�.
	m_vertexCount = 3;

	//�ε��� �迭�� �ε��� ���� �����մϴ�.
	m_indexCount = 3;

	//���� �迭�� ����ϴ�.
	VertexType* vertices = new VertexType[m_vertexCount];
	if (!vertices)
	{
		return false;
	}

	//�ε��� �迭�� ����ϴ�.
	unsigned long* indices = new unsigned long[m_indexCount];

	//���� �迭�� �����͸� �����մϴ�.
	vertices[0].position = XMFLOAT3(-1.0f, -1.0f, 0.0f);
	vertices[0].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);

	vertices[1].position = XMFLOAT3(0.0f, 1.0f, 0.0f);
	vertices[1].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
	
	vertices[2].position = XMFLOAT3(1.0f, -1.0f, 0.0f);
	vertices[2].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);

	//�ε��� �迭�� ���� �����մϴ�.
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;

	//���� ���� ������ ����ü�� �����մϴ�.
	D3D11_BUFFER_DESC vertexBufferDesc;
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(unsigned long) * m_indexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;
	
	//subresource ������ ���� �����Ϳ� ���� �����͸� �����մϴ�.
	D3D11_SUBRESOURCE_DATA verexData;
	verexData.pSysMem = vertices;
	verexData.SysMemPitch = 0;
	verexData.SysMemSlicePitch = 0;

	//���� ���� ���۸� ����ϴ�.
	if (FAILED(device->CreateBuffer(&vertexBufferDesc, &verexData, &m_vertexBuffer)))
	{
		return false;
	}

	//���� �ε��� ������ ����ü�� �����մϴ�.
	D3D11_BUFFER_DESC indexBufferDesc;




	return true;
}

void ModelClass::shutdownBuffers()
{
}

void ModelClass::renderbuffers(ID3D11DeviceContext * deviceContext)
{
}
