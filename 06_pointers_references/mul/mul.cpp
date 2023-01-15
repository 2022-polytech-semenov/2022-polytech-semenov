#include <cassert>
#include <iostream>
#include <cstring>

int length(const char* a) {
    return (int)std::strlen(a);
}

const char* itos(int n) {
    if (!n) return "0";

    int m = n;
    int numofdigits = 0;
    while (m) {
        numofdigits++;
        m /= 10;
    }

    char* arr;
    arr = (char*)malloc(numofdigits + 1);
    arr[numofdigits] = '\0';
    while (n) {
        arr[--numofdigits] = (char)(n % 10 + '0');
        n /= 10;
    }
    return (const char*)arr;
}

const char* mul(const char* a, const char* b) {
    int lena = length(a);
    int lenb = length(b);

    int aint = 0, bint = 0;
    for (int i = lena - 1, mult = 1; i >= 0; i--, mult *= 10) aint += (a[i] - '0') * mult;
    for (int i = lenb - 1, mult = 1; i >= 0; i--, mult *= 10) bint += (b[i] - '0') * mult;
    return itos((aint * bint));
}

int main() {
    assert(strcmp(mul("12", "13"), "156") == 0);
    assert(strcmp(mul("2", "3"), "6") == 0);
    assert(strcmp(mul("100", "100"), "10000") == 0);
    assert(strcmp(mul("99", "99"), "9801") == 0);
    return 0;
}