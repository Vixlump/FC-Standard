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

#define loop while(true)
//pre var deps

//var z deps
#include "var_z/hash.h"
#include "var_z/codex.h"
#include "var_z/patchwork.h"

//var y deps

//var x deps
#include "var_x/p_t.h"
#include "var_x/debug.h"
#include "var_x/error.h"
#include "var_x/asign.h"
#include "var_x/cswap.h"
#include "var_x/abreg.h"
#include "var_x/v.h"
#include "var_x/i.h"
#include "var_x/scan.h"

int main(int argc, char *argv[]) {
    load_codex(original_file_name);
    scan_stream();
    return 42;
}
