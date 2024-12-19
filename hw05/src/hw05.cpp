
#include <hw05.h>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std; 

using VecOfStr = vector<string>;

VecOfStr hw05(const VecOfStr& strings) {
    VecOfStr palindromes;
    auto isPalindrome = [](const string& str) {
        string cleaned;
        for (char c : str) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }
        // i mean empty string and 1 symbol is not pallindrome
        if (cleaned.empty() || cleaned.length() < 2) return false; 
        auto left = cleaned.begin();
        auto right = cleaned.end() - 1;

        while (left < right) {
            if (*left != *right) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    };

   
    for (const auto& str : strings) {
        if (isPalindrome(str)) {
            palindromes.push_back(str);
        }
    }

    return palindromes;
}