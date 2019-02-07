#pragma once

#include "TexturedObject.h"
#include "Vector2.h"
#include "Rect.h"

class CAnimation
{
public:
	inline void SetAnimationObject(CTexturedObject* _object) { m_pAnimationObject = _object; }

	inline CTexturedObject* GetAnimationObject() { return m_pAnimationObject; }

	inline void SetAnimationRect(SRect _rect) { m_pAnimationRect = _rect; }

	inline SRect GetAnimationRect() { return m_pAnimationRect; }

	CTexturedObject* m_pAnimationObject;

	SRect m_pAnimationRect;
};