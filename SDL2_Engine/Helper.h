#pragma once

#pragma region system include
#include <string>  
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

/// <summary>
/// get parent directory of path
/// </summary>
/// <param name="_path">path</param>
/// <param name="_depth">depth to get into</param>
/// <returns>parent path</returns>
string GetParentDirectory(string _path, int _depth = 1);

/// <summary>
/// get absolute asset path
/// </summary>
/// <param name="_pPath">relative path</param>
/// <param name="_depth">depth to get into</param>
/// <returns>absolute path</returns>
string GetAssetPath(const char* _pPath, int _depth);