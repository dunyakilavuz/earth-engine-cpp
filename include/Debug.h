#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>

namespace eEngine
{
	namespace Utils
	{
		class Debug
		{
		public:
			static void Log(const char* log);
			static void Log(std::string log);
		};
	}
}


#endif 