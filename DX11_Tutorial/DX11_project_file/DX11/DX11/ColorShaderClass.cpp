#include "stdafx.h"
#include "ColorShaderClass.h"


ColorShaderClass::ColorShaderClass()
{
}

ColorShaderClass::ColorShaderClass(const ColorShaderClass &)
{
}

ColorShaderClass::~ColorShaderClass()
{
}

bool ColorShaderClass::initialize(ID3D11Device* device, HWND hwnd)
{	
	// ���� �� �ȼ����̴��� �ʱ�ȭ �մϴ�.
	return initializeShader(device, hwnd, L"../DX11/Color.vs", L"../DX11/Color.ps");
}

void ColorShaderClass::shutDown()
{	
	//���ؽ� �� �ȼ� ���̴��� ���õ� ��ü�� �����մϴ�
	shutdownShader();
}

bool ColorShaderClass::render(ID3D11DeviceContext * deviceContext, int indexCount, XMMATRIX worldMat, XMMATRIX viewMat, XMMATRIX projectionMat)
{
	//�������� ����� ���̴� �Ű������� �����մϴ�.
	if(!setShaderParameters(deviceContext, worldMat, viewMat, projectionMat));
	{
		return false;
	}

	//������ ���۸� ���̴��� �������Ѵ�.
	renderShader(deviceContext, indexCount);
	return true;
}

bool ColorShaderClass::initializeShader(ID3D11Device * device, HWND hwnd, const WCHAR* vsFileName, const WCHAR* psFileName)
{
	ID3D10Blob* errorMessage = nullptr;

	//���ؽ� ���̴� �ڵ带 �������� ���ۿ� �Ҵ��մϴ�.
	ID3D10Blob* vertexShaderBuffer = nullptr;
	if (FAILED(D3DCompileFromFile(vsFileName, NULL, NULL, "ColorVertexShader", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS,
		0, &vertexShaderBuffer, &errorMessage)))
	{	
		// ���̴� ������ ���н� �����޽����� ����Ѵ�
		if (errorMessage)
		{
			outputShaderErrorMessage(errorMessage, hwnd, vsFileName);
		}
		// ������ ������ �ƴ϶�� ���̴� ������ ã�� �� ���� ����Դϴ�
		else
		{
			MessageBox(hwnd, vsFileName, L"Missing Shader File", MB_OK);
		}
		return false;
	}
	
	//�ȼ� ���̴��� �������� ���ۿ� �Ҵ��մϴ�.
	ID3D10Blob* pixelShaderBuffer = nullptr;
	if (FAILED(D3DCompileFromFile(psFileName, NULL, NULL, "ColorPixelShader", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS,
		0, &pixelShaderBuffer, &errorMessage)))
	{
		if (errorMessage)
		{
			outputShaderErrorMessage(errorMessage, hwnd, psFileName);
		}
		else
		{
			MessageBox(hwnd, psFileName, L"Cannot Find Shader File", MB_OK);
		}
		return false;
	}

	//���ۿ��� ���ؽ� ���̴��� �����մϴ�
	if (FAILED(device->CreateVertexShader(vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(), NULL, &m_vertexShader)))
	{
		return false;
	}

	//���ۿ��� �ȼ� ���̴��� �����մϴ�
	if (FAILED(device->CreatePixelShader(pixelShaderBuffer->GetBufferPointer(), pixelShaderBuffer->GetBufferSize(), NULL, &m_pixelShader)))
	{
		return false;
	}

	//���� �Է� ���̾ƿ� ����ü�� �����մϴ�.
	//�� ������ modelClass �� ���̴��� vertexType ������ ��ġ�ؾ��մϴ�.
	D3D11_INPUT_ELEMENT_DESC polygonLayout[2];
	polygonLayout[0].SemanticName = "POSITION";
	polygonLayout[0].SemanticIndex = 0;
	polygonLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	polygonLayout[0].InputSlot = 0;
	polygonLayout[0].AlignedByteOffset = 0;
	polygonLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[0].InstanceDataStepRate = 0;

	polygonLayout[1].SemanticName = "COLOR";
	polygonLayout[1].SemanticIndex = 0;
	polygonLayout[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	polygonLayout[1].InputSlot = 0;
	polygonLayout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	polygonLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[1].InstanceDataStepRate = 0;

	//���̾ƿ� ��� ���� �����ɴϴ�.
	unsigned int numElements = sizeof(polygonLayout) / sizeof(polygonLayout[0]);

	//���� �Է� ���̾ƿ��� ����ϴ�.
	if (FAILED(device->CreateInputLayout(polygonLayout, numElements, vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(), &m_inputLayout)))
	{
		return false;
	}

	//�� �̻� ������ �ʴ� ����, �ȼ� ���̴� ���۸� �����մϴ�.
	vertexShaderBuffer->Release();
	vertexShaderBuffer = 0;

	pixelShaderBuffer->Release();
	pixelShaderBuffer = 0;

	//���� ���̴��� �մ� ��� ��� ������ ����ü�� �ۼ��մϴ�.
	D3D11_BUFFER_DESC matrixBufferDesc;
	matrixBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDesc.ByteWidth = sizeof(matrixBufferType);
	matrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDesc.MiscFlags = 0;
	matrixBufferDesc.StructureByteStride = 0;

	//��� ���� �����͸� ����� ��Ŭ�������� ���� ���̴� ��� ���ۿ� ������ �� �ְ� �մϴ�.
	if (FAILED(device->CreateBuffer(&matrixBufferDesc, NULL, &m_matrixBuffer)))
	{
		return false;
	}
	return true;
}

void ColorShaderClass::shutdownShader()
{
	if (m_matrixBuffer)
	{
		m_matrixBuffer->Release();
		m_matrixBuffer = 0;
	}

	if (m_inputLayout)
	{
		m_inputLayout->Release();
		m_inputLayout = 0;
	}

	if (m_vertexShader)
	{
		m_vertexShader->Release();
		m_vertexShader = 0;
	}

	if (m_pixelShader)
	{
		m_pixelShader->Release();
		m_pixelShader = 0;
	}

}

void ColorShaderClass::outputShaderErrorMessage(ID3D10Blob * errorMessage, HWND hwnd, const WCHAR * shaderFileName)
{	
	//���� �޽����� ���â�� ǥ���մϴ�.
	OutputDebugStringA(reinterpret_cast<const char*>(errorMessage->GetBufferPointer()));

	//���� �޽����� ��ȯ�մϴ�.
	errorMessage->Release();
	errorMessage = 0;

	//������ ������ ������ �˾� �޼����� �˷��ݴϴ�.
	MessageBox(hwnd, L"Error compiling shader", shaderFileName, MB_OK);
}

bool ColorShaderClass::setShaderParameters(ID3D11DeviceContext * deviceContext, XMMATRIX worldMat, XMMATRIX viewMat, XMMATRIX projectionMat)
{	
	//����� transpose �Ͽ� ���̴����� ����� �� �ְ� �մϴ�.
	worldMat = XMMATRIX(worldMat);
	viewMat = XMMATRIX(viewMat);
	projectionMat = XMMATRIX(projectionMat);

	// ��� ������ ������ ���� �ֵ��� ��޴ϴ�.
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	if (FAILED(deviceContext->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource)))
	{
		return false;
	}
	
	//��� ������ �����Ϳ� ���� �����͸� �����ɴϴ�
	matrixBufferType* dataPtr = (matrixBufferType*)mappedResource.pData;

	//��� ���ۿ� ����� �����մϴ�.
	dataPtr->world = worldMat;
	dataPtr->view = viewMat;
	dataPtr->projection = projectionMat;

	//��� ������ ����� Ǳ�ϴ�
	deviceContext->Unmap(m_matrixBuffer, 0);

	//���� ���̴������� ��� ������ ��ġ�� �����մϴ�.
	unsigned bufferNumber = 0;

	//���������� �������̴��� ��� ���۸� �ٲ� ������ �ٲߴϴ�.
	deviceContext->VSSetConstantBuffers(bufferNumber, 1, &m_matrixBuffer);

	return true;
}

void ColorShaderClass::renderShader(ID3D11DeviceContext * deviceContext, int indexCount)
{
	//���� �Է� ���̾ƿ��� �����մϴ�
	deviceContext->IASetInputLayout(m_inputLayout);

	//�ﰢ���� �׸� ���� ���̴��� �ȼ����̴��� �����մϴ�.
	deviceContext->VSSetShader(m_vertexShader, NULL, 0);
	deviceContext->PSSetShader(m_pixelShader, NULL, 0);

	//�ﰢ���� �׸��ϴ�.
	deviceContext->DrawIndexed(indexCount, 0 ,0);
}
