#pragma once

#include <fstream>
using namespace std;


/////////////
// LINKING //
/////////////
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include "DDSTextureLoader.h" // DDS 파일을 더 빠르게 불러옴
using namespace DirectX;

///////////////////////////
//  warning C4316 처리용  //
///////////////////////////
#include "AlignedAllocationPolicy.h"

#define D3D_DEBUG_INFO