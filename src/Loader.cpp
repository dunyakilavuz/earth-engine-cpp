#include "Loader.h"

using namespace eEngine::Utils;
using namespace std;

string Loader::ImportCode(std::string filePath)
{
	File *file = new File(filePath);
	return file->GetAllLines();
}