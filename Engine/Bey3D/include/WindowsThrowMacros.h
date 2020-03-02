#ifndef __WINDOWS_THROW_MACROS_H__
#define __WINDOWS_THROW_MACROS_H__

// error exception helper
#define BEYWND_EXCEPT(hr) Window::HrException(__LINE__, __FILE__, hr)
#define BEYWND_LAST_EXCEPT() Window::HrException(__LINE__, __FILE__, GetLastError())
#define BEYWND_NOGFX_EXCEPT() Window::NoGfxException(__LINE__, __FILE__)

#endif // __WINDOWS_THROW_MACROS_H__
