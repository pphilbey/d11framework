#include "inputclass.h"

InputClass::InputClass()
{
}

InputClass::InputClass(const InputClass&)
{
}

InputClass::~InputClass()
{
}

void InputClass::Initialize()
{
    int i;

    // Initialize all keys to being released and not pressed.
    for (i = 0; i < 256; i++)
    {
        m_keys[i] = false;
    }
    return;
}

void InputClass::KeyDown(unsigned int input)
{
    // if a key is pressed then save that state in the key array
    m_keys[input] = true;
    return;
}

void InputClass::KeyUp(unsigned int input)
{
    // if a key is pressed then save that state in the key array
    m_keys[input] = false;
    return;
}

bool InputClass::IsKeyDown(unsigned int key)
{   
    // return the state of the key (pressed/not pressed)
    return m_keys[key];
}
