#include "schnitzel_lib.h"
#include "platform.h"

#ifdef _WIN32
#include "win32_platform.cpp"
#endif

int main(){

    platform_create_window(1200, 720, "Celeste");
    while(running){
        //Event Tick
        platform_update_window();
        SM_ASSERT(true, "Assertion hit!");
    }

    return 0;
}