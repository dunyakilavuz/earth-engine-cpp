#include "File.h"

using namespace eEngine::Utils;
using namespace std;

File::File(std::string filePath)
{
    this->filePath = filePath;
    ifstream myFile(filePath.c_str());
    string line;

    if(myFile.is_open())
    {
        while(getline(myFile,line))
        {
            lines << line << '\n';
        }
        myFile.close();
    }
    else
    {
        Debug::Log("Failed to open file.");
        Debug::Log(filePath);
    }

    myFile.close();
}

string File::GetLine(int index)
{
    string line;
    int count = 0;
    while(getline(lines,line,'\n'))
    {
        if(count == index)
        {
            return line;
        }
        count++;
    }
    return "";
}

string File::GetAllLines()
{
    return lines.str();
}

void File::InsertLine(int index, string line)
{

}
