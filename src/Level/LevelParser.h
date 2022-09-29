#pragma once
#include <string>
#include <unordered_map>

class LevelStruct;
//TODO: use name SceneParser
class LevelParser
{
public:
	LevelParser() = default;
	LevelParser(const std::string& filepath);
private:
	void Load();
	std::string ReadDataFromFile(const std::string& filepath) const;
	//std::unordered_map<int,std::string> PreProcess(const std::string& source);
	
	void Parse(const std::string& source);
	void ParseMetaData(const std::string& block);
	void ParseDecorationData(const std::string& block);
private:
	//std::unordered_map<int, std::string> m_LevelSource;
	
	std::string m_FileName,m_AssetPath;


};


class LevelStruct
{

public:
	LevelStruct(const std::string& name)
		: m_Name(name),m_SizeX(0),m_SizeY(0),m_StartX(0),m_StartY(0)
	{}

	void AddFields(std::string& fieldName,float size)
	{
		if (fieldName == "SizeX")
		{
			m_SizeX = size;
		}
		if (fieldName == "SizeY")
		{
			m_SizeY = size;
		}
		if (fieldName == "StartX")
		{
			m_StartX = size;
		}
		if (fieldName == "StartY")
		{
			m_StartY = size;
		}
	}

	void TempPrintValues()
	{
		printf("Name: %s , SizeX: %f , SizeY: %f , StartX: %f ,StartY: %f ",m_Name.c_str() ,m_SizeX,m_SizeY,m_StartX,m_StartY);
	}
private:
	std::string m_Name;
	float m_SizeX;
	float m_SizeY;
	float m_StartX;
	float m_StartY;
	
	
};