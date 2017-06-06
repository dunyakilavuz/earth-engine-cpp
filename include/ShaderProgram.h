#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "Matrix4x4.h"
#include "Vector4.h"
#include "Map.h"

using namespace eEngine::Maths;
using namespace eEngine::Utils;

namespace eEngine
{
	namespace Graphics
	{
		class ShaderProgram
		{
			int programID;
			int vertexShaderID;
			int fragmentShaderID;
			Map<std::string, int> *uniforms;

		public:
			ShaderProgram();
			int createShader(std::string shaderCode,int shaderType);
			void createVertexShader(std::string shaderCode);
			void createFragmentShader(std::string shaderCode);
			void Link();
			void Bind();
			void Unbind();
			void CleanUp();

			void createUniform(std::string uniformName);
			void setUniform(std::string uniformName, Matrix4x4 matrix);
			void setUniform(std::string uniformName, int value);
			void setUniform(std::string uniformName, Vector4 vector);
			
		};
	}
}

#endif