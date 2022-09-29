#include "LevelParser.h"

#include <fstream>

//////////////////Helper Functions////////////////////

const char* FindToken(const char* str, const std::string& token)
{
    const char* t = str;
    while (t = strstr(t, token.c_str()))
    {
        bool left = str == t || isspace(t[-1]);
        bool right = !t[token.size()] || isspace(t[token.size()]);
        if (left && right)
            return t;

        t += token.size();
    }
    return nullptr;
}

const char* FindToken(const std::string& string, const std::string& token)
{
    return FindToken(string.c_str(), token);
}

std::vector<std::string> SplitString(const std::string& string, const std::string& delimiters)
{
    size_t start = 0;
    size_t end = string.find_first_of(delimiters);

    std::vector<std::string> result;

    while (end <= std::string::npos)
    {
        std::string token = string.substr(start, end - start);
        if (!token.empty())
            result.push_back(token);

        if (end == std::string::npos)
            break;

        start = end + 1;
        end = string.find_first_of(delimiters, start);
    }

    return result;
}

std::vector<std::string> SplitString(const std::string& string, const char delimiter)
{
    return SplitString(string, std::string(1, delimiter));
}

std::vector<std::string> Tokenize(const std::string& string)
{
    return SplitString(string, " \t\n");
}


std::string GetBlock(const char* str, const char** outPosition)
{
    const char* end = strstr(str, "}");
    if (!end)
        return str;

    if (outPosition)
        *outPosition = end;
    uint32_t length = end - str + 1;
    return std::string(str, length);
}

std::string GetStatement(const char* str, const char** outPosition)
{
    const char* end = strstr(str, ";");
    if (!end)
        return str;

    if (outPosition)
        *outPosition = end;
    uint32_t length = end - str + 1;
    return std::string(str, length);
}
///////////////////////////////////////////////////////////////////

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
    //printf("%s",source.c_str());
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
   // m_LevelSource = PreProcess(source);
    
    const char* token;
    const char* metastr;

        
    metastr = source.c_str();
    while (token = FindToken(metastr,"Meta"))
        ParseMetaData(GetBlock(token,&metastr));
    
    while (token = FindToken(metastr,"Decorations"))
        ParseDecorationData(GetBlock(token,&metastr)); 

    //printf("%s",str.c_str());
    
}

void LevelParser::ParseMetaData(const std::string& block)
{
    std::vector<std::string> tokens = Tokenize(block);
    uint32_t index = 1;
    
    index++;
    std::string typeString = tokens[index++];
    std::string name = tokens[index++];

    if (const char* s = strstr(name.c_str(), ";"))
    {
        name = std::string(name.c_str(), s - name.c_str());
        name.erase(remove(name.begin(),name.end(),'\"'),name.end());
    }
    
    auto* MetaData = new LevelStruct(name);
    while (index < tokens.size())
    {
        if (tokens[index] == "}")
            break;

        std::string type = tokens[index++];
        std::string name = tokens[index++];

        // Strip ; from name if present
        if (const char* s = strstr(name.c_str(), ";"))
        {
            name = std::string(name.c_str(), s - name.c_str());
            type.erase(remove(type.begin(),type.end(),':'),type.end());
        }
        
        MetaData->AddFields(type,std::stof(name));
    }
}

void LevelParser::ParseDecorationData(const std::string& block)
{
    std::vector<std::string> tokens = Tokenize(block);
    uint32_t index = 1;

    index++;

    while (index < tokens.size())
    {
        if (tokens[index] == "}")
            break;
        
        std::string typeString = tokens[index++];
        std::string name = tokens[index++];

    
    
        
        //printf("%s",typeString.c_str());
        //printf("%s\n",name.c_str());
    }
    

    
}
