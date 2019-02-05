#pragma region project include
#include "ContentManagement.h"
#include "Engine.h"
#include "Renderer.h"
#include "MoveObject.h"
#include "Macro.h"
#pragma endregion

#pragma region destructor
// destructor
CContentManagement::~CContentManagement()
{
	// remove all objects from scene list
	while (m_pSceneObjects.size() > 0)
		m_pSceneObjects.pop_front();

	// remove all objects from persistant list
	while (m_pPersistantObjects.size() > 0)
		m_pPersistantObjects.pop_front();

	// remove all objects from UI list
	while (m_pUIObjects.size() > 0)
		m_pUIObjects.pop_front();
}
#pragma endregion

#pragma region public override function
// initialize object
void CContentManagement::Init()
{
	
}

// update every frame
void CContentManagement::Update(float _deltaTime)
{
	// as long as there is a object to remove
	while (m_pRemoveObjects.size() > 0)
	{
		// get first object
		CObject* pObj = m_pRemoveObjects.front();

		// remove object pointer from list
		m_pSceneObjects.remove(pObj);
		m_pPersistantObjects.remove(pObj);
		m_pUIObjects.remove(pObj);

		// remove move object
		if(dynamic_cast<CMoveObject*>(pObj))
			m_pMoveObjects.remove((CMoveObject*)pObj);

		// delete and remove object
		m_pRemoveObjects.pop_front();
	}

	// decrease collision time
	m_currentColTime -= _deltaTime;

	// if collision time 0
	if (m_currentColTime <= 0.0f)
	{
		// if move object list not empty
		if (m_pMoveObjects.size())
		{
			// set collision list of first object
			m_pMoveObjects.front()->SetCollisionList(_deltaTime);

			// set first object to last element
			CMoveObject* pObj = m_pMoveObjects.front();
			m_pMoveObjects.remove(pObj);
			m_pMoveObjects.push_back(pObj);
		}

		// set collision time
		m_currentColTime = m_collisionTime;
	}

	// update every scene object
	for (CObject* pObj : m_pSceneObjects)
		pObj->Update(_deltaTime);

	// update every persistant object
	for (CObject* pObj : m_pPersistantObjects)
		pObj->Update(_deltaTime);

	// update every UI object
	for (CObject* pObj : m_pUIObjects)
		pObj->Update(_deltaTime);
}

// render every frame
void CContentManagement::Render()
{
	// order of rendering important

	// render every scene object
	for (CObject* pObj : m_pSceneObjects)
		pObj->Render();

	// render every persistant object
	for (CObject* pObj : m_pPersistantObjects)
		pObj->Render();

	// render every UI object
	for (CObject* pObj : m_pUIObjects)
		pObj->Render();
}
#pragma endregion

#pragma region public function
// remove object
void CContentManagement::RemoveObject(CObject * _pObject)
{
	// add object to remove list
	m_pRemoveObjects.push_back(_pObject);
}

// sort list
void CContentManagement::SortList(list<CObject*>& _pList)
{
	/// TODO:
}
#pragma endregion

#pragma region private function
// add object to list
void CContentManagement::AddObject(CObject * _pObject, list<CObject*>& _pList)
{
	// add object to list
	_pList.push_back(_pObject);

	// if object is a move object
	if (dynamic_cast<CMoveObject*>(_pObject))
	{
		// add object to move object list
		m_pMoveObjects.push_front((CMoveObject*)_pObject);

		// set collision time
		m_collisionTime = COLLISION_CHECK_TIME / m_pMoveObjects.size();
	}

	// sort list
	SortList(_pList);
}

// clean list
void CContentManagement::CleanObjects(list<CObject*> &_pList)
{
	// remove all objects from list
	while (_pList.size() > 0)
		_pList.pop_front();
}
#pragma endregion