#include "ShaderProgram.h"
#include "GLFunctions.h"
#include "Debug.h"

using namespace eEngine::Graphics;
using namespace eEngine::Utils;

ShaderProgram::ShaderProgram()
{
	programID = glCreateProgram();
	if(programID == 0)
		Debug::Log("Could not create shader.");
	uniforms = new Map<std::string, int>();
}

int ShaderProgram::createShader(std::string shaderCode,int shaderType)
{
	int shaderID = glCreateShader(shaderType);
	if(shaderID == 0)
	{
		Debug::Log("Error creating shader code: " + shaderID);
	}
 
	const char* shaderCodePtr = shaderCode.c_str();
	int compileStatus = 0;

	glShaderSource(shaderID,1,&shaderCodePtr,nullptr);
	glCompileShader(shaderID);
	glGetShaderiv(shaderID,GL_COMPILE_STATUS, &compileStatus);

	if(compileStatus == 0)
	{
		int infoLogLenght;
		char* infoLog = 0;
		glGetShaderiv(shaderID,GL_INFO_LOG_LENGTH,&infoLogLenght);
		glGetShaderInfoLog(shaderID,infoLogLenght,&infoLogLenght,infoLog);
		Debug::Log("Error compiling shader code: " + std::string(infoLog));
	}
	glAttachShader(programID,shaderID);
	return shaderID;
}
void ShaderProgram::createVertexShader(std::string shaderCode)
{
	vertexShaderID = createShader(shaderCode,GL_VERTEX_SHADER);
}

void ShaderProgram::createFragmentShader(std::string shaderCode)
{
	fragmentShaderID = createShader(shaderCode,GL_FRAGMENT_SHADER);
}


void ShaderProgram::Link()
{
	int linkStatus;
	glLinkProgram(programID);
	glGetProgramiv(programID,GL_LINK_STATUS,&linkStatus);

	if(linkStatus == 0)
	{
		int infoLogLenght;
		char* infoLog = 0;
		glGetProgramiv(programID,GL_INFO_LOG_LENGTH,&infoLogLenght);
		glGetProgramInfoLog(programID,infoLogLenght,&infoLogLenght,infoLog);
		Debug::Log("Error linking shader code: " + std::string(infoLog));
	}

	int validateStatus;
	glValidateProgram(programID);
	glGetProgramiv(programID,GL_VALIDATE_STATUS,&validateStatus);

	if(validateStatus == 0)
	{
		int infoLogLenght;
		char* infoLog = 0;
		glGetProgramiv(programID,GL_INFO_LOG_LENGTH,&infoLogLenght);
		glGetProgramInfoLog(programID,infoLogLenght,&infoLogLenght,infoLog);
		Debug::Log("Warning validating shader code: " + std::string(infoLog));
	}
}

void ShaderProgram::Bind()
{
	glUseProgram(programID);
}

void ShaderProgram::Unbind()
{
	glUseProgram(0);
}

void ShaderProgram::CleanUp()
{
	Unbind();
	if(programID != 0)
	{
		if(vertexShaderID != 0)
		{
			glDetachShader(programID,vertexShaderID);
		}
		if(fragmentShaderID != 0)
		{
			glDetachShader(programID,fragmentShaderID);
		}
		glDeleteProgram(programID);
	}
}

void ShaderProgram::createUniform(std::string uniformName)
{
	int uniformLocation = glGetUniformLocation(programID, uniformName.c_str());
	if(uniformLocation < 0)
	{
		Debug::Log("Could not find uniform:" + uniformName);
	}
	uniforms->put(uniformName,uniformLocation);
}

void ShaderProgram::setUniform(std::string uniformName,Matrix4x4 matrix)
{
	float sMatrix[16];
	Matrix4x4::Serialized(matrix,sMatrix);
	glUniformMatrix4fv(uniforms->get(uniformName),1,false,sMatrix);
}

void ShaderProgram::setUniform(std::string uniformName, int value)
{
	glUniform1i(uniforms->get(uniformName), value);
}

void ShaderProgram::setUniform(std::string uniformName, Vector4 vector)
{
	glUniform4f(uniforms->get(uniformName), vector.x, vector.y, vector.z, vector.w);
}