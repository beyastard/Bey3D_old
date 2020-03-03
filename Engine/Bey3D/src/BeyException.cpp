#include "BeyException.h"
#include <sstream>


BeyException::BeyException( int line,const char* file ) noexcept
	: line( line ), file( file )
{}

const char* BeyException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl << GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* BeyException::GetType() const noexcept
{
	return "Bey3D Exception";
}

int BeyException::GetLine() const noexcept
{
	return line;
}

const std::string& BeyException::GetFile() const noexcept
{
	return file;
}

std::string BeyException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl << "[Line] " << line;
	return oss.str();
}
