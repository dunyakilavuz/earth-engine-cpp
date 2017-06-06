#include "References.h"

using namespace eEngine;
using namespace eEngine::Utils;

float References::WindowWidth = 1400;
float References::WindowHeight = 700;
std::string References::WindowTitle = "Earth Engine";

std::string References::operatingSystem()
{
	#ifdef _WIN32
    return "Windows 32-bit";
    #elif _WIN64
    return "Windows 64-bit";
    #elif __unix || __unix__
    return "Unix";
    #elif __APPLE__ || __MACH__
    return "Mac OSX";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #else
    return "Other";
    #endif
}

std::string References::projectPath()
{
    std::string os = operatingSystem();
	if(os.find("Windows") != std::string::npos)
	{
		return "C:\\Users\\dnyq\\Desktop\\earth-engine-cpp-master";
	}
	else
	{
		return "/home/dnyq/Desktop/earth-engine-cpp-master";
	}
}