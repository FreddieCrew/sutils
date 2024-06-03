#include <a_samp>
#include <sutils>

main() {
    ABS();
    NaN();
    StrCpy();
    StrToUpper();
    StrToLower();
    StrCount();
    IsEmpty();
    IsDigits();
    IsIP();
}

stock ABS() {
    new val = -1000, absval;
    absval = abs(val);
    printf("%i", absval);
}

stock NaN() {
    new nanval = nan();
    printf("%s | %i", isnan(nanval) ? "Yes" : "No", nanval);
}

stock StrCpy() {
    new origin[10], destiny[11] = "Hello";
    strcpy(destiny, origin);
    printf("%s", destiny);
}

stock StrCount() {
    new origin[50] = "COW COW COW COW COW COW test test test", count = 0;
    count = strcount(origin, "COW", true);
    printf("Matches: %i", count);
}

stock StrToUpper() {
    new str[11] = "hello", dest[12];

    strtoupper(str, dest, sizeof(dest));
    printf("%s", dest);
}

stock StrToLower() {
    new str[11] = "HELLO", dest[12];

    strtolower(str, dest, sizeof(dest));
    printf("%s", dest);
}

stock IsEmpty() {
    new str[5];

    printf("%s", isempty(str) ? "Yes" : "No");
}

stock IsDigits() {
    new str[] = "123";

    printf("%s", isdigits(str) ? "Yes" : "No");
}

stock IsIP() {
    new str[] = "127.0.0.1";

    printf("%s", isip(str) ? "Yes" : "No");
}
