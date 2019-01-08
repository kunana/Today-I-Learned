#include "stdafx.h"
#include "InputClass.h"
#include "GraphicClass.h"
#include "SystemClass.h"

SystemClass::SystemClass()
{

}

SystemClass::SystemClass(const SystemClass& other)
{

}

SystemClass::~SystemClass()
{

}

bool SystemClass::intialize()
{
	//������ â ����, ���� ���� ���� �ʱ�ȭ
	int screenWidth = 0;
	int screenHeight = 0;

	//������ ���� �ʱ�ȭ
	InitializeWindows(screenWidth, screenHeight);

	//m_Input ��ü ����. �� Ŭ���� �� ���� ������� Ű���� �Է� ó���� ���˴ϴ�.
	m_Input = new InputClass;
	if(!m_Input)
	{
		return false;
	}
	
	//m_Input ��ü �ʱ�ȭ
	m_Input->Initialize();

	//m_Graphics ��ü ����. �� Ŭ���� �� �׷��� �������� ó���ϱ� ���� ��ü�Դϴ�.
	m_Graphics = new GraphicsClass;
	if (!m_Graphics)
	{
		return false;
	}

	//m_Graphics ��ü �ʱ�ȭ
	m_Graphics->Initialize(screenWidth, screenHeight , m_hwnd);
		
}

void SystemClass::ShutDown()
{
	//m_Graphics ��ü ��ȯ
	if (m_Graphics)
	{
		m_Graphics->Shutdown();
		delete m_Graphics;
		m_Graphics = 0;
	}

	//m_Input ��ü ��ȯ
	if (m_Input)
	{
		delete m_Input;
		m_Input = 0;
	}

	ShutdownWindows();
}

void SystemClass::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG)); // �޸� ������ 0x00 ���� ä��� ��ũ��. �ƹ��͵� ��ȯ���� ����/ ���������� memset �Լ� ȣ����.

	while (true)//����ڷ� ���� ���� �޽����� ������ ���� �޽��� ������ ���ϴ�.
	{
		//������ �޽����� ó���մϴ�.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//�� �ܿ��� Frame �Լ��� ó�� �մϴ�.
			if (!Frame())
				break;
		}
	}
}

LRESULT SystemClass::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM Iparam)
{
	switch (umsg)
	{
		// Ű�� �������°�.
		case WM_KEYDOWN:
		{
			m_Input->KeyDown((unsigned int)wparam);
			return 0;
		}
		// Ű�� �������°�.
		case WM_KEYUP:
		{
			m_Input->KeyUp((unsigned int)wparam);
			return 0;
		}

		// �׿� ��� �޽����� �⺻ó���� �ѱ�
		default:
		{
			return DefWindowProc(hwnd, umsg, wparam, Iparam);
		}
	}
}

bool SystemClass::Frame()
{
	//ESC Ű ���� �� ���� ���θ� ó���մϴ�.
	if (m_Input->IskeyDown(VK_ESCAPE))
	{
		return false;
	}

	// �׷��� ��ü�� Frame �� ó���մϴ�.
	return m_Graphics->Frame();
}

void SystemClass::InitializeWindows(int &screenWidth, int &screenHeight)
{
	//�ܺ� �����͸� �� ��ü�� ����
	ApplicationHandle = this;

	//�� ���α׷��� �ν��Ͻ��� ������
	m_hinstance = GetModuleHandle(NULL);

	//���α׷� �̸��� ����

	m_applicationName = L"Dx11Demo_02";

	//window Ŭ���� �ʱ�ȭ �� �Ʒ��� ���� ����
	WNDCLASSEX wc;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = m_hinstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground =(HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = m_applicationName;
	wc.cbSize = sizeof(WNDCLASSEX);

	//windows class ���
	RegisterClassEx(&wc);

	//����� ȭ���� �ػ󵵸� �о�ɴϴ�.
	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);

	int posX = 0;
	int posY = 0;

	// FULL_SCREEN ���� ���� ���� ȭ���� �����մϴ�.
	if (FULL_SCREEN)
	{
		//Ǯ��ũ�� ���� ���� �ߴٸ�, ����� ȭ�� �ػ󵵸� ����ũ�� �ػ󵵷� ����
		//������ 32bit�� ����
		DEVMODE dmScreenSettings;
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)screenWidth;
		dmScreenSettings.dmPelsHeight = (unsigned long)screenHeight;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		//Ǯ ��ũ������ ���÷��� ������ �����մϴ�.
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);
	}
	else
	{
		//������ ����� ��� 1280 * 720���� ������ ����
		screenWidth = 1280;
		screenWidth = 720;

		//������ â�� ����, ������ �� ��� ������.
		posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth / 2);
		posX = (GetSystemMetrics(SM_CYSCREEN) - screenHeight / 2);
	
	}

	// �����츦 �����ϰ� �ڵ��� ���մϴ�.
	m_hwnd = CreateWindowEx(WS_EX_APPWINDOW, m_applicationName, m_applicationName, 
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP, 
		posX, posY,screenWidth, screenHeight, 
		NULL, NULL, m_hinstance, NULL);

	// �����츦 ȭ�鿡 ǥ���ϰ� ��Ŀ���� ����
	ShowWindow(m_hwnd, SW_SHOW);
	SetForegroundWindow(m_hwnd);
	SetFocus(m_hwnd);
}

void SystemClass::ShutdownWindows()
{
	//Ǯ ��ũ�� ��� ���ٸ� ���÷��� ������ �ʱ�ȭ �մϴ�.
	if (FULL_SCREEN)
	{
		ChangeDisplaySettings(NULL, 0);
	}

	// â�� �����մϴ�
	DestroyWindow(m_hwnd);
	m_hwnd = NULL;

	//���α׷� �ν��Ͻ��� �����մϴ�
	UnregisterClass(m_applicationName, m_hinstance);
	m_hinstance = NULL;

	//�ܺ� ������ ������ �ʱ�ȭ
	ApplicationHandle = NULL;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch (umessage)
	{
		// ������ ���Ḧ Ȯ���մϴ�
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}

		// �����찡 �������� Ȯ���մϴ�
		case WM_CLOSE:
		{
			PostQuitMessage(0);
			return 0;
		}

		// �� ���� ��� �޽������� �ý��� Ŭ������ �޽��� ó���� �ѱ�ϴ�.
		default:
		{
			return ApplicationHandle->MessageHandler(hwnd, umessage, wparam, lparam);
		}
	}
}