#ifndef LOADER_H
#define LOADER_H

#include "File.h"

namespace eEngine
{
    namespace Utils
    {
        class Loader
        {
        public:
            static std::string ImportCode(std::string filePath);
        };
    }
}


#endif