#pragma once

TYPE_BEGIN(struct HksCompilerSettings, 0x20);

TYPE_END();

TYPE_BEGIN(struct Hksglobal, 0x5B0);
TYPE_FIELD(HksBytecodeSharingMode m_bytecodeSharingMode, 0x80);
TYPE_FIELD(HksCompilerSettings m_compilerSettings, 0x348);
TYPE_END();

TYPE_BEGIN(struct lua_state, 0xE8);
TYPE_FIELD(Hksglobal* m_global, 0x08);
TYPE_END();

#define luaVM (*(lua_state**)(UI_luaVM_a))