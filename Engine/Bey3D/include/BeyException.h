#ifndef __BEY_3D_EXCEPTION_H__
#define __BEY_3D_EXCEPTION_H__

#include <exception>
#include <string>

class BeyException : public std::exception
{
public:
	BeyException(int line, const char* file) noexcept;
	const char* what() const noexcept override;
	virtual const char* GetType() const noexcept;
	int GetLine() const noexcept;
	const std::string& GetFile() const noexcept;
	std::string GetOriginString() const noexcept;

private:
	int line;
	std::string file;

protected:
	mutable std::string whatBuffer;
};

#endif // __BEY_3D_EXCEPTION_H__
