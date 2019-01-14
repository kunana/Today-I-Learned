#include "stdafx.h"
#include "CameraClass.h"

CameraClass::CameraClass()
{
	m_position = XMFLOAT3(0.0f, 0.0f, 0.0f);
	m_rotation = XMFLOAT3(0.0f, 0.0f, 0.0f);
}

CameraClass::CameraClass(const CameraClass &)
{
}

CameraClass::~CameraClass()
{
}

void CameraClass::setPosition(float x, float y, float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

void CameraClass::setRotation(float x, float y, float z)
{
	m_rotation.x = x;
	m_rotation.y = y;
	m_rotation.z = z;
}

XMFLOAT3 CameraClass::getPosition()
{
	return m_position;
}

XMFLOAT3 CameraClass::getRotation()
{
	return m_rotation;
}

void CameraClass::render()
{
	XMFLOAT3 up, position, lookAt;
	XMVECTOR upVector, positionVector, lookAtVector;
	float yaw, pitch, roll;
	XMMATRIX rotationMatrix;

	//������ ����Ű�� ���͸� ����
	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;

	//XMVECTOR ����ü�� �ε�
	upVector = XMLoadFloat3(&up);

	//3D ���忡�� ī�޶��� ��ġ�� ����
	position = m_position;

	//XMVECTOR ����ü�� �ε�
	positionVector = XMLoadFloat3(&position);

	//�⺻������ ī�޶� ã���ִ� ��ġ�� ����
	lookAt.x = 0.0f;
	lookAt.y = 1.0f;
	lookAt.z = 0.0f;

	//XMVECTOR ����ü�� �ε�
	lookAtVector = XMLoadFloat3(&lookAt);

	//yaw(Y��), pitch (X ��) �� roll (Z ��) �� ȸ������ ���� ������ �����մϴ�.
	pitch = m_rotation.x * 0.0174532925f;
	yaw = m_rotation.y * 0.0174532925f;
	roll = m_rotation.z * 0.0174532925f;

	//yaw, pitch, roll ���� ���� ȸ������� ����ϴ�.
	rotationMatrix = XMMatrixRotationRollPitchYaw(pitch, yaw, roll);

	//lookAt �� up ���͸� ȸ�� ��ķ� �����Ͽ� �䰡 �������� �ùٸ��� ȸ�� �ǵ��� �մϴ�.
	lookAtVector = XMVector3TransformCoord(lookAtVector, rotationMatrix);
	upVector = XMVector3TransformCoord(upVector, rotationMatrix);

	// ȸ�� �� ī�޶� ��ġ�� ��� ��ġ�� ��ȯ�մϴ�.
	lookAtVector = XMVectorAdd(positionVector, lookAtVector);

	// ���������� �� ���� ������Ʈ �� ���Ϳ��� �� ����� ����ϴ�.
	m_viewMatrix = XMMatrixLookAtLH(positionVector, lookAtVector, upVector);

		
}

void CameraClass::getViewMatrix(XMMATRIX & viewMat)
{
	viewMat = m_viewMatrix;
}
