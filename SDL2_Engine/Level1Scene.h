#pragma once

#pragma region project include
#include "Scene.h"
#include "Level01.h"
#pragma endregion

class CMusic;

#pragma region forwarde decleration
class CText;
#pragma endregion

/// <summary>
/// game main scene class
/// </summary>
class GLevel1Scene : public CScene
{
public:
#pragma region contructor
	/// <summary>
	/// constructor
	/// </summary>
	GLevel1Scene() : CScene() {}
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	~GLevel1Scene() { }
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
	GLevel01* m_pLevel;

	CMusic* m_pBackground;
#pragma endregion
};
