#pragma once
#include <string>

//TODO: use name SceneParser
class LevelParser
{
public:
	LevelParser() = default;
	LevelParser(const std::string& filepath);
private:
	void Load();
	std::string ReadDataFromFile(const std::string& filepath) const;

	void Parse(const std::string& source);
private:

	std::string m_FileName,m_AssetPath;
};


