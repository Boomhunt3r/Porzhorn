#pragma once

/// <summary>
/// 2D vector class
/// </summary>
struct SVector2
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_x">x value</param>
	/// <param name="_y">y value</param>
	SVector2(float _x = 0.0f, float _y = 0.0f)
	{
		X = _x;
		Y = _y;
	}
#pragma endregion

#pragma region public primitive variable
	/// <summary>
	/// x value
	/// </summary>
	float X;

	/// <summary>
	/// y value
	/// </summary>
	float Y;
#pragma endregion

#pragma region operator
	/// <summary>
	/// vector 2 + vector 2
	/// </summary>
	/// <param name="_vec">vector 2 to add</param>
	/// <returns>new vector 2</returns>
	SVector2 operator + (SVector2 _vec)
	{
		return SVector2(X + _vec.X, Y + _vec.Y);
	}

	/// <summary>
	/// vector 2 * vector 2
	/// </summary>
	/// <param name="_value">float to multiply</param>
	/// <returns>new vector 2</returns>
	SVector2 operator * (float _value)
	{
		return SVector2(X * _value, Y * _value);
	}
#pragma endregion
};