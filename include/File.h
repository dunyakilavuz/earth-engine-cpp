 #ifndef FILE_H
 #define FILE_H

 #include <sstream>
 #include <string>
 #include <fstream>
 #include <iostream>
 #include "Debug.h"

namespace eEngine
{
    namespace Utils
    {
        class File
        {
            std::string filePath;
            std::stringstream lines;
        public:
            File(std::string filePath);
            std::string GetLine(int index);
            std::string GetAllLines();
            void InsertLine(int index,std::string line);
        }; 
    }
}


 #endif