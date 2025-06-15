#include "stdafx.h"

#pragma diag_suppress 77
SYS_MODULE_INFO(T7_luaLoader, 0, 1, 1);
SYS_MODULE_START(module_start);
SYS_MODULE_STOP(module_stop);
SYS_LIB_DECLARE_WITH_STUB(LIBNAME, SYS_LIB_AUTO_EXPORT, STUBNAME);
SYS_LIB_EXPORT(T7_luaLoader_export_function, LIBNAME);

void Run_raw_lua(std::string data)
{
    lua_Reader readerData;

    readerData.buffer = data.c_str();
    readerData.length = data.size();

    if (!luaVM || !readerData.buffer || readerData.length == 0)
        return;

    luaVM->m_global->m_bytecodeSharingMode = HKS_BYTECODE_SHARING_ON;

   // hksi_hksL_loadbuffer(luaVM, &luaVM->m_global->m_compilerSettings, data.c_str(), data.size(), data.c_str());

    if (!hksi_hks_load(luaVM, &luaVM->m_global->m_compilerSettings, (void*)hks_bufferReader_a, &readerData, 0, 0, readerData.buffer))
        hks_vm_call_internal(luaVM, 0, 0, 0);

    luaVM->m_global->m_bytecodeSharingMode = HKS_BYTECODE_SHARING_SECURE;

   // hksi_lua_pcall(luaVM, 0, 0, 0);
}

extern "C"
{
    int T7_luaLoader_export_function(void)
    {
        return CELL_OK;
    }

    int module_start(void)
    {
        printf("[T7_luaLoader]: Loaded!\n");

        Run_raw_lua("Dvar.ui_lobbyDebugVis:set(1)");
        
        return SYS_PRX_START_OK;
    }

    int module_stop(void)
    {
        printf("[T7_luaLoader]: Unloaded!\n");

        Run_raw_lua("Dvar.ui_lobbyDebugVis:set(0)");

        return SYS_PRX_STOP_OK;
    }
}