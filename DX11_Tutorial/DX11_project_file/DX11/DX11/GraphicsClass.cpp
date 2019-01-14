#include "stdafx.h"
#include "D3DClass.h"
#include "Cameraclass.h"
#include "ModelClass.h"
#include "ColorShaderClass.h"
#include "GraphicsClass.h"


GraphicsClass::GraphicsClass()
{
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}

bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	// Direct3D 객체 생성
	m_Direct3D = (D3DClass*)_aligned_malloc(sizeof(D3DClass), 16);
	if (!m_Direct3D)
	{
		return false;
	}

	// Direct3D 객체 초기화
	if (!m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR))
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	m_Camera = new CameraClass;
	if (!m_Camera)
	{
		return false;
	}

	m_Camera->setPosition(0.0f, 0.0f, -5.0f);

	m_Model = new ModelClass();
	if(!m_Model)
	{
		return false;
	}

	if (!m_Model->initialize(m_Direct3D->GetDevice()))
	{
		MessageBox(hwnd, L"Could not initialize the model object", L"Error", MB_OK);
		return false;
	}
	
	m_ColorShader = new ColorShaderClass;
	if (!m_ColorShader)
	{
		return false;
	}

	if (!m_ColorShader->initialize(m_Direct3D->GetDevice(), hwnd))
	{
		MessageBox(hwnd, L"Could not initialize the color Shader object", L"Error", MB_OK);
		return false;
	}

	return true;
}


void GraphicsClass::Shutdown()
{	
	if (m_ColorShader)
	{
		m_ColorShader->shutDown();
		delete m_ColorShader;
		m_ColorShader = 0;
	}

	if (m_Model)
	{
		m_Model->shutDown();
		delete m_Model;
		m_Model = 0;
	}

	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Direct3D 객체 반환
	if (m_Direct3D)
	{
		m_Direct3D->Shutdown();
		delete m_Direct3D;
		m_Direct3D = 0;
	}
}


bool GraphicsClass::Frame()
{
	// 그래픽 랜더링 처리
	return Render();
}


bool GraphicsClass::Render()
{
	// 씬을 그리기 위해 버퍼를 지웁니다
	m_Direct3D->BeginScene(0.9f, 0.9f, 0.3f, 1.0f);

	m_Camera->render();

	XMMATRIX worldMatrix, viewMatrix, projectionMatrix;
	m_Direct3D->GetWorldMatrix(worldMatrix);
	m_Camera->getViewMatrix(viewMatrix);
	m_Direct3D->GetProjectionMatrix(projectionMatrix);

	if (!m_ColorShader->render(m_Direct3D->GetDeviceContext(), m_Model->getIndexCount(), worldMatrix, viewMatrix, projectionMatrix))
	{
		return false;
	}

	// 버퍼의 내용을 화면에 출력합니다
	m_Direct3D->EndScene();

	return true;
}