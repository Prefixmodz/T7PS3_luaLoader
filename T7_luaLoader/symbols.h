#pragma once


static symbol<void(lua_state* s, const HksCompilerSettings* options, const char* buff, size_t sz, const char* name)>hksi_hksL_loadbuffer{ hksi_hksL_loadbuffer_a };
static symbol<int(lua_state* s, int nargs, int nresults, int errfunc)>hksi_lua_pcall{ hksi_lua_pcall_a };
static symbol<void(lua_state* s, uint32_t nArgs, uint32_t nResults, uint32_t pc)>hks_vm_call_internal{ hks_vm_call_internal_a };