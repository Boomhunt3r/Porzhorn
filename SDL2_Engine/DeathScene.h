#pragma once
#pragma region project include
#include "Scene.h"  
#pragma endregion


class GDeathScene :public CScene
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	GDeathScene() : CScene() {}
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	virtual ~GDeathScene() { }
#pragma endregion

#pragma region public function
	/// <summary>
	/// load scene
	/// </summary>
	virtual void Load() override;

	/// <summary>
	/// clean scene
	/// </summary>
	virtual void Clean() override;

	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaSeconds">time since last frame</param>
	virtual void Update(float _deltaSeconds) override;

	/// <summary>
	/// render every frame
	/// </summary>
	virtual void Render() override;
#pragma endregion
};

