#if defined _inc_SUTILS_INCLUDE
	#undef _inc_SUTILS_INCLUDE
#endif
#if defined _SUTILS_INCLUDE_included
	#endinput
#endif
#define _SUTILS_INCLUDE_included

native abs(value);
native isnan(value);
native strcpy(dest[], const origin[], len = sizeof(dest));
native CreateNaN();
native strcount(const src[], const word[], bool:casesen);
native bool: isempty(const string[]);
native bool: isdigits(const string[]);
native bool: isip(const string[]);

stock strtoupper(const src[], dest[], len = sizeof(src)) {
	for (new i = 0; i < len; i++) {
		if(src[i] == '\0') break;

		dest[i] = toupper(src[i]);
	}
	return 1;
}

stock strtolower(const src[], dest[], len = sizeof(src)) {
	for (new i = 0; i < len; i++) {
		if(src[i] == '\0') break;

		dest[i] = tolower(src[i]);
	}
	return 1;
}