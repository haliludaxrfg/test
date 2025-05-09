/*1）设计一个类封装（参考C语言）6种位运算(函数接口封装)，给出调用测试。
 基于位运算模拟10进制的+、-、*3个运算，给出调用测试。
（2）实现一个整数中所有数字累加和的计算。（可以和（1）独立project）
给出1000！的计算，可以采用任意方法（注意1000！将溢出）。
报告要求：
（1）详细描述题目要求；
（2）画出主要流程图，并给出必要的文字说明；
（3）分析程序难点，并讨论解决问题思路；
（4）分析所实现程序的优点和缺点；
（5）你的收获。
         提交内容：程序代码（请删除可执行文件）+报告
         文件命名规范：学号+姓名+题号+代码；学号+姓名+题号+报告*/
#include <bits/stdc++.h>
using namespace std;
using Bitset = vector<bool>;
//?
class BigInt {
private:
    bool is_negative;
    Bitset bits; // 动态大小的位集合

    // 移除前导零
    static Bitset trim(const Bitset& b) {
        Bitset result = b;
        while (!result.empty() && !result.back()) {
            result.pop_back();
        }
        return result;
    }

    // 绝对值加法
    static Bitset add(const Bitset& a, const Bitset& b) {
        Bitset result;
        bool carry = false;
        size_t max_size = max(a.size(), b.size());
        result.resize(max_size);
        for (size_t i = 0; i < max_size; ++i) {
            bool abit = i < a.size() ? a[i] : false;
            bool bbit = i < b.size() ? b[i] : false;
            bool sum = abit ^ bbit ^ carry;
            carry = (abit & bbit) | (abit & carry) | (bbit & carry);
            result[i] = sum;
        }
        if (carry) {
            result.push_back(true);
        }
        return trim(result);
    }

    // 绝对值减法（a >= b）
    static Bitset subtract(const Bitset& a, const Bitset& b) {
        Bitset result(a.size());
        bool borrow = false;
        for (size_t i = 0; i < a.size(); ++i) {
            bool abit = a[i];
            bool bbit = i < b.size() ? b[i] : false;
            int sum = (abit ? 1 : 0) - (bbit ? 1 : 0) - (borrow ? 1 : 0);
            borrow = false;
            if (sum < 0) {
                sum += 2;
                borrow = true;
            }
            result[i] = sum != 0;
        }
        return trim(result);
    }

    // 比较绝对值 a < b
    static bool abs_less(const Bitset& a, const Bitset& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        for (int i = a.size() - 1; i >= 0; --i) {
            if (a[i] != b[i]) return !a[i];
        }
        return false;
    }

    // 左移 j 位（低位补零）
    static Bitset shift_left(const Bitset& a, size_t j) {
        Bitset shifted(j, false);
        shifted.insert(shifted.end(), a.begin(), a.end());
        return shifted;
    }

    // 绝对值乘法
    static Bitset multiply(const Bitset& a, const Bitset& b) {
        Bitset result;
        for (size_t j = 0; j < b.size(); ++j) {
            if (b[j]) {
                Bitset shifted = shift_left(a, j);
                result = add(result, shifted);
            }
        }
        return trim(result);
    }

public:
    // 构造函数
    BigInt() : is_negative(false), bits(1, false) {}

    BigInt(int64_t num) {
        is_negative = num < 0;
        uint64_t abs_num = abs(num);
        bits.clear();
        while (abs_num > 0) {
            bits.push_back(abs_num & 1);
            abs_num >>= 1;
        }
        if (bits.empty()) bits.push_back(false);
    }

    BigInt(bool neg, const Bitset& b) : is_negative(neg), bits(trim(b)) {
        if (bits.empty()) {
            bits.push_back(false);
            is_negative = false; // 确保0的符号为正
        }
    }

    // 加法运算符重载
    BigInt operator+(const BigInt& other) const {
        if (is_negative == other.is_negative) {
            return BigInt(is_negative, add(bits, other.bits));
        } else {
            if (abs_less(bits, other.bits)) {
                return BigInt(other.is_negative, subtract(other.bits, bits));
            } else {
                return BigInt(is_negative, subtract(bits, other.bits));
            }
        }
    }

    // 一元负号
    BigInt operator-() const {
        if (bits.size() == 1 && !bits[0]) return *this; // -0 = 0
        return BigInt(!is_negative, bits);
    }

    // 减法运算符
    BigInt operator-(const BigInt& other) const {
        return *this + (-other);
    }

    // 乘法运算符
    BigInt operator*(const BigInt& other) const {
        bool result_neg = is_negative ^ other.is_negative;
        return BigInt(result_neg, multiply(bits, other.bits));
    }

    // 阶乘
    BigInt factorial() const {
        if (bits.size() == 1 && !bits[0]) return BigInt(1); // 0! = 1
        BigInt result(1);
        BigInt current(1);
        while (!abs_less(bits, current.bits)) {
            result = result * current;
            current = current + BigInt(1);
        }
        return result;
    }

    // 十进制数字累加和
    int decimal_digit_sum() const {
        uint64_t decimal_value = 0;
        uint64_t base = 1;
        for (size_t i = 0; i < bits.size(); ++i) {
            if (bits[i]) {
                decimal_value += base;
            }
            base *= 2;
        }

        int sum = 0;
        while (decimal_value > 0) {
            sum += decimal_value % 10;
            decimal_value /= 10;
        }
        return sum;
    }

    // 转换为二进制字符串（高位在前）
    string to_binary() const {
        string str;
        if (is_negative) str += '-';
        bool leading_zero = true;
        for (int i = bits.size() - 1; i >= 0; --i) {
            if (leading_zero && !bits[i]) continue;
            leading_zero = false;
            str += bits[i] ? '1' : '0';
        }
        return str.empty() ? "0" : str;
    }

    // 转换为十进制字符串
    string to_decimal() const {
        string decimal_value = "0";
        string base = "1";
        for (size_t i = 0; i < bits.size(); ++i) {
            if (bits[i]) {
                decimal_value = add_decimal_strings(decimal_value, base);
            }
            base = multiply_decimal_string_by_two(base);
        }
        return (is_negative ? "-" : "") + decimal_value;
    }

private:
    // Helper function to add two decimal strings
    static string add_decimal_strings(const string& a, const string& b) {
        string result;
        int carry = 0, sum = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum / 10;
            result += (sum % 10) + '0';
        }
        reverse(result.begin(), result.end());
        return result;
    }

    // Helper function to multiply a decimal string by 2
    static string multiply_decimal_string_by_two(const string& num) {
        string result;
        int carry = 0, product = 0;
        for (int i = num.size() - 1; i >= 0; --i) {
            product = (num[i] - '0') * 2 + carry;
            carry = product / 10;
            result += (product % 10) + '0';
        }
        if (carry) result += carry + '0';
        reverse(result.begin(), result.end());
        return result;
    }
};
void display_menu() {
    cout << "\n===== 大数计算器 =====" << endl;
    cout << "tip:输入为int但是输出无限制" << endl;
    cout << "1. 计算阶乘 (n!)" << endl;
    cout << "2. 计算两数相加 (a + b)" << endl;
    cout << "3. 计算两数相减 (a - b)" << endl;
    cout << "4. 计算两数相乘 (a * b)" << endl;
    cout << "5. 计算数字各位之和" << endl;
    cout << "6. 退出" << endl;
    cout << "=====================" << endl;
    cout << "请选择操作 (1-6): ";
}
// 示例
int main() {
    int choice;
    do {
        display_menu();
        cin >> choice;
        if (cin.fail()) { // 检查输入是否失败
            cout << "输入无效，程序退出。" << endl;
            return 1;
        }
        switch (choice) {
            case 1: {
                int n;
                cout << "请输入一个整数 n: ";
                cin >> n;
                if (cin.fail()) {
                    cout << "输入无效，程序退出。" << endl;
                    return 1;
                }
                BigInt result = BigInt(n).factorial();
                cout << n << "! = " << result.to_decimal() << endl;
                break;
            }
            case 2: {
                int a, b;
                cout << "请输入两个整数 a 和 b: ";
                cin >> a >> b;
                if (cin.fail()) {
                    cout << "输入无效，程序退出。" << endl;
                    return 1;
                }
                BigInt result = BigInt(a) + BigInt(b);
                cout << a << " + " << b << " = " << result.to_decimal() << endl;
                break;
            }
            case 3: {
                int a, b;
                cout << "请输入两个整数 a 和 b: ";
                cin >> a >> b;
                if (cin.fail()) {
                    cout << "输入无效，程序退出。" << endl;
                    return 1;
                }
                BigInt result = BigInt(a) - BigInt(b);
                cout << a << " - " << b << " = " << result.to_decimal() << endl;
                break;
            }
            case 4: {
                int a, b;
                cout << "请输入两个整数 a 和 b: ";
                cin >> a >> b;
                if (cin.fail()) {
                    cout << "输入无效，程序退出。" << endl;
                    return 1;
                }
                BigInt result = BigInt(a) * BigInt(b);
                cout << a << " * " << b << " = " << result.to_decimal() << endl;
                break;
            }
            case 5: {
                int n;
                cout << "请输入一个整数 n: ";
                cin >> n;
                if (cin.fail()) {
                    cout << "输入无效，程序退出。" << endl;
                    return 1;
                }
                BigInt big_int(n);
                cout << n << " 的各位数字之和为: " << big_int.decimal_digit_sum() << endl;
                break;
            }
            case 6:
                cout << "退出程序。" << endl;
                return 0;
            default:
                cout << "无效的选择，将退出程序。" << endl;
                return 1;
        }
    } while (1);
}
