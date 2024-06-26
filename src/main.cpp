#include <amx/amx.h>
#include <plugincommon.h>

#include "common.hpp"
#include "natives.hpp"

logprintf_t logprintf;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData) {
    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
    logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];
    return true;
}

extern "C" const AMX_NATIVE_INFO native_list[] = {
    { "abs", Natives::n_Abs },
    { "isnan", Natives::n_IsNaN },
    { "strcpy", Natives::n_StrCpy },
    { "nan", Natives::n_CreateNaN },
    { "isempty", Natives::n_IsStringEmpty },
    { "strcount", Natives::n_StrCount },
    { "isdigits", Natives::n_StringIsDigits },
    { "isip", Natives::n_IsStringIP },
    { NULL, NULL }
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx) {
    return amx_Register(amx, native_list, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL Unload() {
    return 1;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx) {
    return 1;
}
