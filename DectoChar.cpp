#include <iostream>
#include <string>

const std::string DECIMAL_TO_CHAR = "0123456789";
const std::string LETTER_TO_DECIMAL = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char mapDecimalToChar(int decimal) {
    if (decimal < 0 || decimal > 35) {
        return '?'; // 返回一个非法字符，如果输入不在0到35之间
    }
    return LETTER_TO_DECIMAL[decimal]; // 映射到对应的大写字母
}

int main() {
    int decimalNumber;
    std::cout << "请输入一个两位数的十进制数 (0-35): ";
    std::cin >> decimalNumber;

    char mappedChar = mapDecimalToChar(decimalNumber);
    if (mappedChar != '?') {
        std::cout << "映射的大写字母是: " << mappedChar << std::endl;
    } else {
        std::cout << "输入的数字不在有效的范围内。" << std::endl;
    }

    return 0;
}