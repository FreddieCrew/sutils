#include "natives.hpp"

using namespace std;

cell AMX_NATIVE_CALL Natives::n_Abs(AMX* amx, cell* params) {
    int value = params[1];
    return static_cast<cell>(std::abs(value));
}

cell AMX_NATIVE_CALL Natives::n_IsNaN(AMX* amx, cell* params) {
    float value = amx_ctof(params[1]);
    return static_cast<cell>(std::isnan(value) ? 1 : 0);
}

cell AMX_NATIVE_CALL Natives::n_CreateNaN(AMX* amx, cell* params) {
    float nanValue = std::numeric_limits<float>::quiet_NaN();
    return amx_ftoc(nanValue);
}

cell AMX_NATIVE_CALL Natives::n_StrTrim(AMX* amx, cell* params) {
    cell* strAddr = (cell*)params[1];
    int length = params[2];

    char* str = (char*)strAddr;

    while (isspace(*str)) {
        str++;
        length--;
    }

    if (length > 0) {
        char* end = str + length - 1;
        while (end > str && isspace(*end)) {
            end--;
        }
        *(end + 1) = '\0';
    }

    return 1;
}

cell AMX_NATIVE_CALL Natives::n_StrCount(AMX* amx, cell* params) {
    cell* strAddr;
    amx_GetAddr(amx, params[1], &strAddr);

    const char* str;
    amx_StrParam(amx, params[1], str);

    const char* word;
    amx_StrParam(amx, params[2], word);

    int caseSensitive = params[3];

    if (str == nullptr || word == nullptr) return 0;

    cell count(0);
    const char* ptr = str;
    while (*ptr != '\0') {
        const char* wordPtr = word;
        const char* curPtr = ptr;
        bool match = true;

        while (*wordPtr != '\0') {
            if ((caseSensitive && *curPtr != *wordPtr) || (!caseSensitive && std::tolower(*curPtr) != std::tolower(*wordPtr))) {
                match = false;
                break;
            }
            curPtr++;
            wordPtr++;
        }

        if (match && *wordPtr == '\0')
            count++;

        ptr++;
    }

    return count;
}

cell AMX_NATIVE_CALL Natives::n_IsStringIP(AMX* amx, cell* params) {
    const char* str;
    amx_StrParam(amx, params[1], str);

    if (str == nullptr)
        return 0;

    std::regex regexIP("^\\b(?:\\d{1,3}\\.){3}\\d{1,3}\\b$");
    return static_cast<cell>(std::regex_match(str, regexIP) ? 1 : 0);
}

cell AMX_NATIVE_CALL Natives::n_IsStringEmpty(AMX* amx, cell* params) {
    cell* strAddr;
    amx_GetAddr(amx, params[1], &strAddr);

    const char* str;
    amx_StrParam(amx, params[1], str);

    return static_cast<cell>((str == nullptr || str[0] == '\0') ? 1 : 0);
}

cell AMX_NATIVE_CALL Natives::n_StringIsDigits(AMX* amx, cell* params) {
    cell* strAddr;
    amx_GetAddr(amx, params[1], &strAddr);

    const char* str;
    amx_StrParam(amx, params[1], str);

    if (str == nullptr)
        return 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (!std::isdigit(str[i])) {
            return 0;
        }
    }

    return 1;
}

// Default Pawn function that, for some reason, was removed from SA-MP, so why not bring it back?
// Original source: https://github.com/compuphase/pawn/blob/main/amx/amxstring.c#L276
cell AMX_NATIVE_CALL Natives::n_StrCpy(AMX* amx, cell* params) {
    std::string csrc = amx_GetCppString(amx, params[2]);

    cell* addr = nullptr;
    amx_GetAddr(amx, params[1], &addr);
    amx_SetString(addr, csrc.c_str(), 0, 0, csrc.length() + 1);
    return static_cast<cell>(csrc.size());
}
