#include <hw03.h>
#include <iostream>
#include <cstring>

void hw03(char* str, const char* pattern) {
    if (str == nullptr||pattern ==nullptr) {
        return; 
    }
     if (*str == '\0' || *pattern == '\0') {  
        return; 
    }
    int strLen = std::strlen(str);
    int patternLen = std::strlen(pattern);
    for (int i = 0; i <= strLen - patternLen; ++i) {
      if (std::strncmp(&str[i], pattern, patternLen) == 0) {
        std::memmove(&str[i],&str[i + patternLen],strLen -i-patternLen+ 1);
        break; 
      }
    }
}
