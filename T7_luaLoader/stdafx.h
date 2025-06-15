// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

// TODO: reference additional headers your program requires here

#include <cellstatus.h>
#include <sys/prx.h>
#include <sys/prx_error.h>
#include <sys/memory.h>
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>













// libpsutil
#include <../dependencies/libpsutil/include/libpsutil.h>
using namespace libpsutil;
typedef math::vec2_t vec2_t;
typedef math::vec3_t vec3_t;
typedef math::vec4_t vec4_t;
typedef memory::detour detour;
template<typename T>
using symbol2 = symbol<T>;

// project
#include "structParse.h"

#include "addresses.h"
#include "enums.h"
#include "structs.h"
#include "symbols.h"


#pragma hdrstop
