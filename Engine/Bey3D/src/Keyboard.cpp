#include "Keyboard.h"

bool Keyboard::KeyIsPressed(unsigned char keycode) const noexcept
{
	return keyStates[keycode];
}

std::optional<Keyboard::Event> Keyboard::ReadKey() noexcept
{
	if (!keyBuffer.empty())
	{
		Event e = keyBuffer.front();
		keyBuffer.pop();
		return e;
	}

	return {};
}

bool Keyboard::KeyIsEmpty() const noexcept
{
	return keyBuffer.empty();
}

std::optional<char> Keyboard::ReadChar() noexcept
{
	if (!charBuffer.empty())
	{
		unsigned char charCode = charBuffer.front();
		charBuffer.pop();
		return charCode;
	}

	return {};
}

bool Keyboard::CharIsEmpty() const noexcept
{
	return charBuffer.empty();
}

void Keyboard::FlushKey() noexcept
{
	keyBuffer = std::queue<Event>();
}

void Keyboard::FlushChar() noexcept
{
	charBuffer = std::queue<char>();
}

void Keyboard::Flush() noexcept
{
	FlushKey();
	FlushChar();
}

void Keyboard::EnableAutoRepeat() noexcept
{
	autoRepeatEnabled = true;
}

void Keyboard::DisableAutoRepeat() noexcept
{
	autoRepeatEnabled = false;
}

bool Keyboard::AutoRepeatIsEnabled() const noexcept
{
	return autoRepeatEnabled;
}

void Keyboard::OnKeyPressed(unsigned char keycode) noexcept
{
	keyStates[keycode] = true;
	keyBuffer.push(Event(Event::Type::Press, keycode));
	TrimBuffer(keyBuffer);
}

void Keyboard::OnKeyReleased(unsigned char keycode) noexcept
{
	keyStates[keycode] = false;
	keyBuffer.push(Event(Event::Type::Release, keycode));
	TrimBuffer(keyBuffer);
}

void Keyboard::OnChar(char character) noexcept
{
	charBuffer.push(character);
	TrimBuffer(charBuffer);
}

void Keyboard::ClearState() noexcept
{
	keyStates.reset();
}

template<typename T>
void Keyboard::TrimBuffer(std::queue<T>& buffer) noexcept
{
	while (buffer.size() > bufferSize)
		buffer.pop();
}
