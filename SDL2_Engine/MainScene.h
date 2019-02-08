#pragma once

#pragma region project include
#include "Scene.h"
#pragma endregion

#pragma region forwarde decleration
class GWorld;
class GLevel01;
class GLevel02;
class CText;
#pragma endregion

/// <summary>
/// game main scene class
/// </summary>
class GMainScene : public CScene
{
public:
#pragma region contructor
	/// <summary>
	/// constructor
	/// </summary>
	GMainScene() : CScene() {}
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	~GMainScene() { }
#pragma endregion

#pragma region public override function
	/// <summary>
	/// load scene
	/// </summary>
	virtual void Load() override;

	/// <summary>
	/// clean up scene
	/// </summary>
	virtual void Clean() override;

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

private:
#pragma region private variable
	/// <summary>
	/// world
	/// </summary>
	GWorld* m_pWorld;

	/// <summary>
	/// level01
	/// </summary>
	GLevel01* m_pLevel01;

	/// <summary>
	/// level02
	/// </summary>
	GLevel02* m_pLevel02;
#pragma endregion
};