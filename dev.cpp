/*
Copyright (c) Cohen ter Heide 2014-2022 All rights reserved.
This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.
Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
Cohen ter Heide
support@lumpology.com
*/

//cstd control
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cinttypes>
#include <cstring>

//stream control
#include <iostream>
#include <fstream>
#include <sstream>

//filesystem control
//#include <filesystem>

//variable expantion
#include <string>
#include <memory>
#include <new>
#include <map>
#include <type_traits>
//#include <cctype>

//math control
#include <cmath>
#include <complex>
#include <random>
#include <limits>
#include <functional>

//time control
#include <ctime>
#include <chrono>

//threading control
#include <thread>
#include <atomic>
#include <mutex>
#include <vector>

using namespace std;
using namespace chrono;
using namespace this_thread;

//pre var deps
#define loop while(true)

   //Platforms specific inclusion controller:
   //Windows = 1
   //MacOSX = 2
   //GNU/Linux = 3
   //Android = 4
   //Ubuntu Touch = 5
   //BSD = 6
   //Raspberry PI = 7
   //IOS = 8
   //PineTime = 9
   //Oculus = 10
   //Custom = 11
#define FCPLATFORM 3

//Comment out if you do not want to compile with aspectu
#define ASPECTUFXTOOLS

//var z deps
//#include "var_z/int128.h"
#include "var_z/version.h"
#include "var_z/hash.h"
#include "var_z/patchwork/codex.h"
#include "var_z/patchwork/patchwork.h"
#include "var_z/exprtk.hpp"

//var y deps
#include "var_y/p_t.h"
#include "var_y/livepatch.h"
#include "var_y/function_driver.h"
#include "var_y/overloader.h"

//math parcer
//#include "fparser.hh"

//non Standard C++ Dependancies
#ifdef ASPECTUFXTOOLS
//#include<SDL2/SDL.h>
#include "var_z/imgui/imgui.h"
#include "var_z/imgui/imgui_impl_glut.h"
#include "var_z/imgui/imgui_impl_opengl3.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <curl/curl.h>
#endif

//var x deps
#include "var_x/error.h"
#include "var_x/debug.h"
#include "var_x/asign.h"
#include "var_x/valuesystem.h"
#include "var_x/cswap.h"
#include "var_x/abreg.h"
#include "var_x/v.h"
#include "var_x/m.h"
#include "var_x/c.h"
#include "var_x/f.h"
#include "var_x/t.h"
#include "var_x/i.h"
#include "var_x/x.h"
#include "var_x/r.h"
#include "var_x/o.h"
#ifdef ASPECTUFXTOOLS
#include "var_x/a.h"
#endif
#include "var_x/scan.h"

int main(int argc, char *argv[]) {
   for (uint64_t i = 0; i < argc; i++) {
      codex_add_string_array(COREFC("_args"), argv[i]);
   }
      codex_store_string(COREFC("_version"), fc_version);
   load_codex(original_file_name);
   scan_stream();
   return 42;
}
