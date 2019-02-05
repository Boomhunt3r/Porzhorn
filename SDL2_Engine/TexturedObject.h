#pragma once

#pragma region project include
#include "Object.h"
#include "Rect.h"
#pragma endregion

#pragma region forward decleration
class CTexture;
#pragma endregion

/// <summary>
/// textured object class
/// </summary>
class CTexturedObject :	public CObject
{
public:

#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position</param>
	/// <param name="_size">size (x = width)</param>
	CTexturedObject(SVector2 _pos = SVector2(), SVector2 _size = SVector2());

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pFileName">relative path file name</param>
	/// <param name="_pos">position</param>
	/// <param name="_size">size (x = width)</param>
	CTexturedObject(const char* _pFileName, SVector2 _pos = SVector2(), SVector2 _size = SVector2());
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	virtual ~CTexturedObject() {}
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
	/// get angle
	/// </summary>
	/// <returns>angle of texture</returns>
	inline float GetAngle() { return m_angle; }

	/// <summary>
	/// get rect
	/// </summary>
	/// <returns>rect</returns>
	inline SRect GetRect() { return m_rect; }

	/// <summary>
	/// set rect
	/// </summary>
	/// <param name="_angle">angle to set</param>
	inline void SetRect(float _angle) { m_angle = _angle; }

	/// <summary>
	/// set texture is rendered in world
	/// </summary>
	/// <param name="_inWorld">rendered in world</param>
	inline void SetInWorld(bool _inWorld) { m_inWorld = _inWorld; }

	/// <summary>
	/// get source rect
	/// </summary>
	/// <returns>source rect of texture</returns>
	inline SRect GetSrcRect() { return m_srcRect; }

	/// <summary>
	/// set source rect
	/// </summary>
	/// <param name="_srcRect">source rect to set</param>
	inline void SetSrcRect(SRect _srcRect) { m_srcRect = _srcRect; }

	/// <summary>
	/// set rect
	/// </summary>
	/// <param name="_rect">new rect</param>
	inline void SetRect(SRect _rect) { m_rect = _rect; }

	/// <summary>
	/// get mirror
	/// </summary>
	/// <returns>mirror</returns>
	inline SVector2 GetMirror() { return m_mirror; }

	/// <summary>
	/// set mirror
	/// </summary>
	/// <param name="_mirror">mirror to set</param>
	inline void SetMirror(SVector2 _mirror) { m_mirror = _mirror; }

	/// <summary>
	/// get texture
	/// </summary>
	/// <returns>texture</returns>
	inline CTexture* GetTexture() { return m_pTexture; }

	/// <summary>
	/// set texture
	/// </summary>
	/// <param name="_pTexture">texture to set</param>
	inline void SetTexture(CTexture* _pTexture) { m_pTexture = _pTexture; }
#pragma endregion

protected:
#pragma region protected primitive variable
	/// <summary>
	/// angle of texure
	/// </summary>
	float m_angle;

	/// <summary>
	/// texture is rendered in world
	/// </summary>
	bool m_inWorld = true;
#pragma endregion

#pragma region protected variable
	/// <summary>
	/// rect of texture
	/// </summary>
	SRect m_rect;

	/// <summary>
	/// source rect of texture
	/// </summary>
	SRect m_srcRect;

	/// <summary>
	/// mirror
	/// x != 0 mirror horizontal
	/// y != 0 mirror vertical
	/// </summary>
	SVector2 m_mirror;
#pragma endregion

#pragma region protected pointer
	/// <summary>
	/// texture
	/// </summary>
	CTexture* m_pTexture = nullptr;

	/// <summary>
	/// collision target reference
	/// </summary>
	CTexturedObject* m_pColTarget = nullptr;
#pragma endregion
};