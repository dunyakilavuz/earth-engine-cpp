#ifndef REFERENCES_H
#define REFERENCES_H

#include <string>
#include "Debug.h"

namespace eEngine
{
	class References
	{
	public:
		static float WindowWidth;
		static float WindowHeight;
		static std::string WindowTitle;
		static std::string operatingSystem();
		static std::string projectPath();
	};
}

#endif