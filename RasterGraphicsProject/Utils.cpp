#include "Utils.h"

String Utils::intToString(int number) {
    if (number == 0) {
        return String("0");
    }

    bool isNegative = number < 0;
    if (isNegative) {
        number = -number;
    }

    String result;
    while (number > 0) {
        int digit = number % 10;
        char digitChar = '0' + digit;
        result = String(&digitChar) + result;
        number /= 10;
    }

    if (isNegative) {
        result = String("-") + result;
    }

    return result;
}