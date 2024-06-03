#pragma once

#ifndef SUTILS_NATIVES_H
#define SUTILS_NATIVES_H

#include <string>
#include <cmath>
#include <cstring>
#include <cctype>
#include <regex>
#include <algorithm>

#include <amx/amx2.h>

#include "common.hpp"

namespace Natives {
    cell n_Abs(AMX* amx, cell* params);
    cell n_IsNaN(AMX* amx, cell* params);
    cell n_CreateNaN(AMX* amx, cell* params);
    cell n_StrTrim(AMX* amx, cell* params);
    cell n_StrCount(AMX* amx, cell* params);
    cell n_IsStringIP(AMX* amx, cell* params);
    cell n_IsStringEmpty(AMX* amx, cell* params);
    cell n_StringIsDigits(AMX* amx, cell* params);
    cell n_StrCpy(AMX* amx, cell* params);
}

#endif
