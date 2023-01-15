#include <cassert>
#include <iostream>


int length(const char* str) {
    if (str == nullptr) return 0;
    int len = 0;
    while (str[len] != '\0') ++len;
    return len;
}

bool palindrome(char* str) {
    if (str == nullptr) return false;

    char* str1 = new char[length(str) + 1];
    for (int i = 0; i < length(str); i++) str1[i] = str[i];
    str1[length(str)] = '\0';

    for (int i = 0; i < length(str1); i++) str1[i] = (char)tolower(str1[i]);

    for (int i = 0; i < length(str1); i++) {
        if (ispunct(str1[i]) || isspace(str1[i])) {
            for (int j = i; j < length(str1); j++) str1[j] = str1[j + 1];
            i--;
        }
    }

    char* str2 = new char[length(str1) + 1];
    for (int i = 0; i < length(str1); i++) str2[i] = str1[length(str1) - i - 1];
    str2[length(str1)] = '\0';

    for (int i = 0; i < length(str1); i++) if (str1[i] != str2[i]) return false;
    return true;
}

int main() {
    assert(palindrome("Do geese see God?") == true);
    assert(palindrome("A man, a plan, a canal, Panama!") == true);
    assert(palindrome("Red roses run no risk, sir, on Nurse's order. ") == true);
    assert(palindrome("Red roses run no risk, on Nurse's order.") == false);
    assert(palindrome(nullptr) == 0);
    return 0;
}