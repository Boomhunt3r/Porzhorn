#pragma region project include
#include "MoveObject.h"
#include "Engine.h"
#include "Renderer.h"
#include "ContentManagement.h"
#include "Physic.h"
#include "Macro.h"
#pragma endregion

#pragma region public override function

float gravityTimer;

// update every frame
void CMoveObject::Update(float _deltaSeconds)
{
	// if my position is too far away from camera
	if (RENDERER->GetCamera().X > m_position.X + SCREEN_WIDTH ||
		RENDERER->GetCamera().X < m_position.X - SCREEN_WIDTH ||
		RENDERER->GetCamera().Y > m_position.Y + SCREEN_HEIGHT ||
		RENDERER->GetCamera().Y < m_position.Y - SCREEN_HEIGHT
		)
	{
		return;
	}

	// check gravity movement down
	CheckCollision(_deltaSeconds, SVector2(0.0f, 1.0f), CPhysic::s_Gravity, true);

	// check collision with collision list
	CheckCollision(_deltaSeconds, m_movement, m_speed, false);

	// update parent
	CTexturedObject::Update(_deltaSeconds);
}

// render every frame
void CMoveObject::Render()
{
	CTexturedObject::Render();
}
#pragma endregion

#pragma region public function
// fill collision list with near collidable objects
void CMoveObject::SetCollisionList(float _deltaSeconds)
{
	// if my position is too far away from camera
	if (RENDERER->GetCamera().X > m_position.X + SCREEN_WIDTH ||
		RENDERER->GetCamera().X < m_position.X - SCREEN_WIDTH ||
		RENDERER->GetCamera().Y > m_position.Y + SCREEN_HEIGHT ||
		RENDERER->GetCamera().Y < m_position.Y - SCREEN_HEIGHT
		)
	{
		return;
	}

	// calculate position to move to
	SVector2 nextPos = m_position + m_movement * m_speed * _deltaSeconds;

	// calculate rect to move to
	SRect rect = m_rect;
	rect.x = nextPos.X;
	rect.y = nextPos.Y;

	// clear list of collision objects in range
	m_pCol.clear();

	// through all scene objects
	for (CObject* pObj : CTM->GetSceneObjects())
	{
		// if current object is textured object min and not self
		if ((CTexturedObject*)pObj && pObj != this)
		{
			// if collision type is none continue
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
				continue;

			// range rect to check if in distance
			SRect rangeRect = rect;
			rangeRect.x -= m_speed * 1.5f;
			rangeRect.y -= m_speed * 1.5f;
			rangeRect.w = m_speed * 3.0f + m_rect.w;
			rangeRect.h = m_speed * 3.0f + m_rect.h;

			// if current object collides (is in range) with this
			if (CPhysic::RectRectCollision(rect, rangeRect))
				// add current object to collision list
				m_pCol.push_front((CTexturedObject*)pObj);
		}
	}

	// through all persistant objects
	for (CObject* pObj : CTM->GetPersistantObjects())
	{
		// if current object is textured object min and not self
		if ((CTexturedObject*)pObj && pObj != this)
		{
			// if collision type is none continue
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
				continue;

			// range rect to check if in distance
			SRect rangeRect = rect;
			rangeRect.x -= m_speed * 1.5f;
			rangeRect.y -= m_speed * 1.5f;
			rangeRect.w = m_speed * 3.0f + m_rect.w;
			rangeRect.h = m_speed * 3.0f + m_rect.h;

			// if current object collides (is in range) with this
			if (CPhysic::RectRectCollision(rect, rangeRect))
				// add current object to collision list
				m_pCol.push_front((CTexturedObject*)pObj);
		}
	}
}
#pragma endregion

#pragma region private function
// check collision with collidable objects list
void CMoveObject::CheckCollision(float _deltaSeconds, SVector2 _movement, float _speed, bool _useGravity)
{
	// if gravity used but gravity false return
	if ((_useGravity && !m_gravity) || m_colType == ECollisionType::NONE)
		return;

	// moveable default true
	m_moveable = true;

	// remove from timer
	if (_useGravity)
		gravityTimer -= _deltaSeconds;

	// grounded default false
	if (_useGravity && gravityTimer <= 0)
	{
		m_grounded = false;
		gravityTimer = _deltaSeconds * 5;
	}

	// calculate position to move to
	SVector2 nextPos = m_position + _movement * _speed * _deltaSeconds;

	// if gravity used
	if (_useGravity)
	{
		// increase fall time
		m_fallTime += _deltaSeconds;

		// calculate position to move to
		nextPos = m_position + _movement * _speed * m_fallTime * _deltaSeconds;
	}

	// calculate rect to move to
	SRect rect = m_rect;
	rect.x = nextPos.X;
	rect.y = nextPos.Y;

	// if gravity not used reset collision target
	if (!_useGravity)
		m_pColTarget = nullptr;

	// through all collision objects in range
	for (CTexturedObject* pObj : m_pCol)
	{
		// if current object is textured object min
		if (pObj != this)
		{
			// get rect from object
			SRect objRect = ((CTexturedObject*)pObj)->GetRect();
			objRect.x = pObj->GetPosition().X;
			objRect.y = pObj->GetPosition().Y;

			// if collision type is none continue
			if (pObj->GetColType() == ECollisionType::NONE)
				continue;

			// set moveable by checking collision
			m_moveable = !CPhysic::RectRectCollision(rect, objRect);

			// if gravity not used set collision target
			if (!_useGravity && !m_moveable)
				m_pColTarget = pObj;

			if (pObj->GetColType() == ECollisionType::COL)
				continue;

			// if not moveable cancel collision check
			if (!m_moveable)
				break;
		}
	}

	// if still moveable set new position
	if (m_moveable)
	{
		// set next position
		m_position = nextPos;
	}

	// if not moveable and gravity true reset fall time and set grounded
	else if (_useGravity)
	{
		m_fallTime = 0.0f;
		m_grounded = true;
	}
}
#pragma endregion