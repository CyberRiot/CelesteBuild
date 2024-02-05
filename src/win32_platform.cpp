#include "schnitzel_lib.h"
#include <windows.h>
#include "platform.h"

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

// ##################################################################################
//                                Windows Globals
// ##################################################################################
static HWND window;

// ##################################################################################
//                                Platform Implementations
// ##################################################################################
LRESULT CALLBACK windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam){
    LRESULT result = 0;
    switch(msg){
        case WM_CLOSE:
        {
            running = false;
            break;
        }
        default:
        {
            result = DefWindowProcA(window, msg, wParam, lParam);
        }
    }
    return result;
}

bool platform_create_window(int width, int height, char *title){
    HINSTANCE instance = GetModuleHandleA(0);

    WNDCLASSA wc = {};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);               //This means we decide the look of the cursor(arrow)
    wc.lpszClassName = title;
    wc.lpfnWndProc = windows_window_callback;                        //Callback for Input into the Window

    if(!RegisterClassA(&wc)){
        return false;
    }

    int dwStyle = WS_OVERLAPPEDWINDOW;
    window = CreateWindowExA(0, title, title, dwStyle, 100, 100, width, height, NULL, NULL, instance, NULL);
    if(window == NULL){
        return false;
    }
    ShowWindow(window, SW_SHOW);

    return true;
}

void platform_update_window(){
    MSG msg;
    while(PeekMessageA(&msg, window, 0, 0, PM_REMOVE)){
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}
