#include "graphicsclass.h"

GraphicsClass::GraphicsClass()
{
    m_Direct3D = nullptr;
}

GraphicsClass::GraphicsClass(const GraphicsClass&)
{
}

GraphicsClass::~GraphicsClass()
{
}

bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
    bool result;

    // create direct3d object
    m_Direct3D = new D3DClass;
    if (!m_Direct3D) 
    {
        return false;
    }
    // init the d3d object
    result = m_Direct3D->Initialize(
        screenWidth, screenHeight,
        VSYNC_ENABLED,
        hwnd,
        FULL_SCREEN,
        SCREEN_DEPTH,
        SCREEN_NEAR);
    if (~result)
    {
        MessageBox(hwnd, L"Could not initialize Direct3D", L"Error", MB_OK);
        return false;
    }
}

void GraphicsClass::Shutdown()
{
    if (m_Direct3D)
    {
        m_Direct3D->Shutdown();
        delete m_Direct3D;
        m_Direct3D = nullptr;
    }
    return;
}

bool GraphicsClass::Frame()
{
    bool result;

    result = Render();
    if (!result)
    {
        return false;
    }
    return true;
}

bool GraphicsClass::Render()
{
   // clear the buffer to begin the scene
    m_Direct3D->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);
    m_Direct3D->EndScene();

    return true;
}
