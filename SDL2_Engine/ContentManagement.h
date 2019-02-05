#pragma once

#pragma region system include
#include <list>
#pragma endregion

#pragma region project include
#include "MoveObject.h" 
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

/// <summary>
/// content management system
/// </summary>
class CContentManagement : public CObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CContentManagement() {}
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	~CContentManagement();
#pragma endregion

#pragma region public override function
	/// <summary>
	/// initialize object
	/// </summary>
	virtual void Init() override;

	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	virtual void Update(float _deltaTime) override;

	/// <summary>
	/// render every frame
	/// </summary>
	virtual void Render() override;
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get scene objects
	/// </summary>
	/// <returns>list with all scene objects</returns>
	inline list<CObject*> GetSceneObjects() { return m_pSceneObjects; }

	/// <summary>
	/// add object to scene object list
	/// </summary>
	/// <param name="_pObject">object to add</param>
	inline void AddSceneObject(CObject* _pObject) { AddObject(_pObject, m_pSceneObjects); }

	/// <summary>
	/// get persistant objects
	/// </summary>
	/// <returns>list with all persistant objects</returns>
	inline list<CObject*> GetPersistantObjects() { return m_pPersistantObjects; }

	/// <summary>
	/// add object to persistant object list
	/// </summary>
	/// <param name="_pObject">object to add</param>
	inline void AddPersistantObject(CObject* _pObject) { AddObject(_pObject, m_pPersistantObjects); }

	/// <summary>
	/// get UI objects
	/// </summary>
	/// <returns>list with all UI objects</returns>
	inline list<CObject*> GetUIObjects() { return m_pUIObjects; }

	/// <summary>
	/// add object to UI object list
	/// </summary>
	/// <param name="_pObject">object to add</param>
	inline void AddUIObject(CObject* _pObject) { AddObject(_pObject, m_pUIObjects); }

	/// <summary>
	/// clean scene objects
	/// </summary>
	inline void CleanSceneObjects() { CleanObjects(m_pSceneObjects); }

	/// <summary>
	/// clean persistant objects
	/// </summary>
	inline void CleanPersistantObjects() { CleanObjects(m_pPersistantObjects); }

	/// <summary>
	/// clean ui objects
	/// </summary>
	inline void CleanUIObjects() { CleanObjects(m_pUIObjects); }
#pragma endregion

#pragma region public function
	/// <summary>
	/// remove object
	/// </summary>
	/// <param name="_pObject">object to remove</param>
	void RemoveObject(CObject* _pObject);

	/// <summary>
	/// sort list
	/// </summary>
	/// <param name="_pList">list reference</param>
	void SortList(list<CObject*> &_pList);
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// time until collision check
	/// </summary>
	float m_collisionTime;

	/// <summary>
	/// current collision time
	/// </summary>
	float m_currentColTime;
#pragma endregion

#pragma region private pointer
	/// <summary>
	/// list of all scene objects
	/// </summary>
	list<CObject*> m_pSceneObjects;

	/// <summary>
	/// list of all persistant objects
	/// </summary>
	list<CObject*> m_pPersistantObjects;

	/// <summary>
	/// list of all UI objects
	/// </summary>
	list<CObject*> m_pUIObjects;

	/// <summary>
	/// list of all moveable objects
	/// </summary>
	list<CMoveObject*> m_pMoveObjects;

	/// <summary>
	/// list of all objects to remove
	/// </summary>
	list<CObject*> m_pRemoveObjects;
#pragma endregion

#pragma region private function
	/// <summary>
	/// add object to list
	/// </summary>
	/// <param name="_pObject">object to add</param>
	/// <param name="_pList">list to add into</param>
	void AddObject(CObject* _pObject, list<CObject*> &_pList);

	/// <summary>
	/// clean list
	/// </summary>
	/// <param name="_pList">list to clean</param>
	void CleanObjects(list<CObject*> &_pList);
#pragma endregion
};