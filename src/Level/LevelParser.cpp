#include "LevelParser.h"

#include <fstream>

LevelParser::LevelParser(const std::string& filepath) : m_AssetPath(filepath)
{
    size_t found = filepath.find_last_of("/\\");
    m_FileName = found != std::string::npos ? filepath.substr(found + 1) : filepath;
    found = m_FileName.find_last_of(".");
    m_FileName = found != std::string::npos ? m_FileName.substr(0,found) : m_FileName;

    Load();
}

void LevelParser::Load()
{
    std::string source = ReadDataFromFile(m_AssetPath);
    //printf("%s \n",m_AssetPath.c_str());
    printf("%s",source.c_str());
    Parse(source);
}

std::string LevelParser::ReadDataFromFile(const std::string& filepath) const
{
    std::string result;
    std::ifstream in(filepath, std::ios::in | std::ios::binary);
    if (in)
    {
        in.seekg(0, std::ios::end);
        result.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&result[0], result.size());
    }
    else
    {
        printf("Could not read level file");
    }
    in.close();
    return result;
}

void LevelParser::Parse(const std::string& source)
{
}
