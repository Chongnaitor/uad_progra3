#pragma once
#include "CVector3.h"
#include "AABB_2D.h"
#include "MathHelper.h"
#include "CFrustum.h"
class CCamara {
private:
	float m_fov;
	CVector3 Position;
	CVector3 LookAt;
	CVector3 Up;
	CVector3 Right;
	bool isAABBVisibile(AABB_2D& AABB);
	void RecalculateViewFrustrum();
	CVector3 m_worldUp,
		m_eyePos,
		m_lookAt,
		m_up,
		m_right;
	bool m_cacheValid;
	int m_frameBufferWidth,
		m_frameBufferHeight;

	float m_fieldOfView,
		m_nearPlane = 0.5,
		m_farPlane = 1000;

	MathHelper::Matrix4 m_projectionMatrix,
		m_viewMatrix;
	CFrustum m_viewFrustum;

	void update(float deltaTime);

	void moveForward(float deltaMove); //mover la camara sobre vector lookAt 

		void moveUp(float deltaMove);  //mover la camara sobre vector up 

		void strafe(float deltaMove);//mover la camara sobre vector right 

		void orbitAroundLookAt(float deltaMove);//punto extra 



	//get para proj y view matrix 
	//get para m_eyePos, m_lookAt, m_Up 


	void recalculateViewMatrix();
	void recalculateViewFrustum();
	



}; 
   