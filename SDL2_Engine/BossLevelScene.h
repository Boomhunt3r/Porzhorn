#pragma once
#pragma region project include
#include "Scene.h"
#include "Level02.h"  
#include "Music.h"
#pragma endregion


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
	/// Boss level
	/// </summary>
	GLevel02* m_pLevel;

	/// <summary>
	/// Background music
	/// </summary>
	CMusic* m_pBackground;
#pragma endregion
};
