#include <hw02.h>

std::string hw02(std::string input_str)
{
    std::string result;
    bool wasChar[256] = {false};
    for (char x : input_str) {
        if (!wasChar[(char)x]) {
            wasChar[(char)x] = true; 
            result+= x;
        }
    }
    return result;
}
