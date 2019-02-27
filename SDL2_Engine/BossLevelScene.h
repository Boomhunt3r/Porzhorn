#pragma once
#include "Scene.h"
#include "Level02.h"

class GBossLevelScene :	public CScene
{
public:
#pragma region contructor
	/// <summary>
	/// constructor
	/// </summary>
	GBossLevelScene() : CScene() {}
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	~GBossLevelScene() { }
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
	GLevel02* m_pLevel;
#pragma endregion
};
