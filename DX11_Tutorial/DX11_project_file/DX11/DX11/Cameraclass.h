#pragma once

class CameraClass
{
public:
	CameraClass();
	CameraClass(const CameraClass&);
	~CameraClass();

	void setPosition(float x, float y, float z);
	void setRotation(float x, float y, float z);

	XMFLOAT3 getPosition();
	XMFLOAT3 getRotation();
	
	void render();
	void getViewMatrix(XMMATRIX& viewMat);

private:
	XMFLOAT3 m_position;
	XMFLOAT3 m_rotation;
	XMMATRIX m_viewMatrix;
};
