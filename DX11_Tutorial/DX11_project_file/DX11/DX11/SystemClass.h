#pragma once

class InputClass;
class GraphicsClass;

class SystemClass
{
public:
	SystemClass();
	SystemClass(const SystemClass&);
	~SystemClass();

	bool intialize();
	void ShutDown();
	void Run();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM); // 응용 프로그램에 전송 될 Windows 시스템 메시지를 처리합니다. 

private:
	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();

private:
	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;

	//그래픽과 입력을 처리 할 두 객체에 대한 포인터
	InputClass* m_Input = nullptr;
	GraphicsClass* m_Graphics = nullptr;
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
static SystemClass* ApplicationHandle = 0;
