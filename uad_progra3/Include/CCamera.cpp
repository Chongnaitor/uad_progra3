#include "CCamera.h"
#include"CFrustum.h"

bool CCamara::isAABBVisibile(AABB_2D& AABB)
{
	if (!m_cacheValid)
	{
		recalculateViewMatrix();
		recalculateViewFrustum();
	}

	// If the AABB is either completely visible (all corners inside the frustum), or intersecting (at least one corner inside the frustum)
	return (
		m_viewFrustum.isAABBVisible(AABB) == CFrustum::FRUSTUM_VISIBILITY_TEST_RESULT::INTERSECT ||
		m_viewFrustum.isAABBVisible(AABB) == CFrustum::FRUSTUM_VISIBILITY_TEST_RESULT::INSIDE
		);
}

void CCamara::RecalculateViewFrustrum()
{
	// Avoid division by zero
	if (m_frameBufferHeight > 0)
	{
		// Geometric approach
		m_viewFrustum.update(
			m_eyePos,
			m_lookAt,
			m_up,
			m_right,
			m_nearPlane,
			m_farPlane,
			m_fieldOfView,
			(float)m_frameBufferWidth / (float)m_frameBufferHeight);
	}

}
