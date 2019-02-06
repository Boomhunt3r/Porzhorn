#pragma once
#include "TexturedObject.h"
class CAnimation : public CTexturedObject
{
public:

#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position</param>
	/// <param name="_size">size (x = width)</param>
	CAnimation(SVector2 _pos = SVector2(), SVector2 _size = SVector2());

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pFileName">relative path file name</param>
	/// <param name="_pos">position</param>
	/// <param name="_size">size (x = width)</param>
	CAnimation(const char* _pFileName, SVector2 _pos = SVector2(), SVector2 _size = SVector2());
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	virtual ~CAnimation() {}
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

private:
	const int WALKING_ANIMATION_FRAMES = 4;
};
#pragma endregion

