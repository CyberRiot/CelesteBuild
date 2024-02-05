#pragma once

#include "schnitzel_lib.h"
#include "glcorearb.h"

// ##################################################################################
//                             OpenGL Function Pointers
// ##################################################################################
static PFNGLCREATEPROGRAMPROC glCreateProgram_ptr;

void gl_load_functions(){

    PROC proc = wglGetProcAddress("glCreateProgram");
    if(!proc){
        SM_ASSERT(false, "Failed to load gl");
    }
    glCreateProgram_ptr = (PFNGLCREATEPROGRAMPROC)proc;
}

GLAPI GLuint APIENTRY glCreateProgram(void){
    return glCreateProgram_ptr();
}