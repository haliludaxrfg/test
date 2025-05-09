#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

class BigInt {
private:
    string number; // 存储十进制数字（不含前导零）
    bool is_negative;

    // 去除前导零
    void remove_leading_zeros() {
        size_t non_zero = number.find_first_not_of('0');
        if (non_zero != string::npos) {
            number = number.substr(non_zero);
        } else {
            number = "0";
        }
        if (number.empty()) number = "0";
    }

    // 比较绝对值大小
    static bool abs_less(const string& a, const string& b) {
        if (a.length() != b.length()) return a.length() < b.length();
        return a < b;
    }

    // 字符串加法
    static string add_strings(const string& a, const string& b) {
        string result;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }

        reverse(result.begin(), result.end());
        return result;
    }

    // 字符串减法（a >= b）
    static string subtract_strings(string a, string b) {
        string result;
        int borrow = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0) {
            int num_a = a[i--] - '0' - borrow;
            int num_b = (j >= 0) ? b[j--] - '0' : 0;
            borrow = 0;

            if (num_a < num_b) {
                num_a += 10;
                borrow = 1;
            }

            result.push_back((num_a - num_b) + '0');
        }

        reverse(result.begin(), result.end());
        return result.substr(result.find_first_not_of('0'));
    }

    // 字符串乘法
    static string multiply_strings(const string& a, const string& b) {
        string result(a.length() + b.length(), '0');

        for (int i = a.length()-1; i >= 0; --i) {
            int carry = 0;
            for (int j = b.length()-1; j >= 0; --j) {
                int temp = (a[i]-'0')*(b[j]-'0') + (result[i+j+1]-'0') + carry;
                result[i+j+1] = temp % 10 + '0';
                carry = temp / 10;
            }
            result[i] += carry;
        }

        size_t start = result.find_first_not_of('0');
        return (start != string::npos) ? result.substr(start) : "0";
    }

public:
    // 构造函数
    BigInt() : number("0"), is_negative(false) {}

    BigInt(const string& s) {
        if (s.empty()) throw invalid_argument("Empty string");

        size_t start = 0;
        is_negative = false;

        if (s[0] == '-') {
            is_negative = true;
            start = 1;
        } else if (s[0] == '+') {
            start = 1;
        }

        number = s.substr(start);
        if (number.find_first_not_of("0123456789") != string::npos) {
            throw invalid_argument("Invalid number: " + s);
        }

        remove_leading_zeros();
        if (number == "0") is_negative = false;
    }

    BigInt(int64_t num) {
        if (num < 0) {
            is_negative = true;
            num = -num;
        } else {
            is_negative = false;
        }
        number = to_string(num);
    }

    // 算术运算符重载
    BigInt operator+(const BigInt& other) const {
        if (is_negative == other.is_negative) {
            string result = add_strings(number, other.number);
            return BigInt(is_negative ? "-" + result : result);
        }
        
        if (abs_less(number, other.number)) {
            string result = subtract_strings(other.number, number);
            return BigInt(other.is_negative ? "-" + result : result);
        } else {
            string result = subtract_strings(number, other.number);
            return BigInt(is_negative ? "-" + result : result);
        }
    }

    BigInt operator-(const BigInt& other) const {
        if (is_negative != other.is_negative) {
            string result = add_strings(number, other.number);
            return BigInt(is_negative ? "-" + result : result);
        }

        if (abs_less(number, other.number)) {
            string result = subtract_strings(other.number, number);
            return BigInt(!is_negative ? "-" + result : result);
        } else {
            string result = subtract_strings(number, other.number);
            return BigInt(is_negative ? "-" + result : result);
        }
    }

    BigInt operator*(const BigInt& other) const {
        string result = multiply_strings(number, other.number);
        bool result_neg = is_negative ^ other.is_negative;
        return BigInt(result_neg ? "-" + result : result);
    }

    // 阶乘
    BigInt operator!() const {
        if (number == "0") return BigInt(1);
        BigInt result(1);
        BigInt current(1);
        BigInt target(*this);

        while (current <= target) {
            result = result * current;
            current = current + BigInt(1);
        }

        return result;
    }

    // 比较运算符
    bool operator<=(const BigInt& other) const {
        if (is_negative != other.is_negative) return is_negative;
        if (is_negative) return abs_less(other.number, number);
        return abs_less(number, other.number) || (number == other.number);
    }

    // 十进制字符串表示
    string to_string() const {
        return (is_negative && number != "0") ? "-" + number : number;
    }

    // 各位数字之和
    int decimal_digit_sum() const {
        int sum = 0;
        for (char c : number) {
            sum += c - '0';
        }
        return sum;
    }
};

// 交互界面
void display_menu() {
    cout << "\n===== 大数计算器 =====" << endl;
    cout << "1. 计算阶乘 (n!)" << endl;
    cout << "2. 计算两数相加 (a + b)" << endl;
    cout << "3. 计算两数相减 (a - b)" << endl;
    cout << "4. 计算两数相乘 (a * b)" << endl;
    cout << "5. 计算数字各位之和" << endl;
    cout << "6. 退出" << endl;
    cout << "=====================" << endl;
    cout << "请选择操作 (1-6): ";
}

string get_input(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;
        try {
            BigInt test(input);
            return input;
        } catch (const exception& e) {
            cout << "输入错误: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    int choice;
    do {
        display_menu();
        cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    string input = get_input("请输入非负整数 n: ");
                    BigInt n(input);
                    if (input[0] == '-') {
                        cout << "阶乘只能计算非负整数!\n";
                        break;
                    }
                    BigInt result = !n;
                    cout << input << "! = " << result.to_string() << endl;
                    break;
                }
                case 2: {
                    BigInt a(get_input("请输入第一个数 a: "));
                    BigInt b(get_input("请输入第二个数 b: "));
                    cout << a.to_string() << " + " << b.to_string() 
                         << " = " << (a + b).to_string() << endl;
                    break;
                }
                case 3: {
                    BigInt a(get_input("请输入第一个数 a: "));
                    BigInt b(get_input("请输入第二个数 b: "));
                    cout << a.to_string() << " - " << b.to_string() 
                         << " = " << (a - b).to_string() << endl;
                    break;
                }
                case 4: {
                    BigInt a(get_input("请输入第一个数 a: "));
                    BigInt b(get_input("请输入第二个数 b: "));
                    cout << a.to_string() << " * " << b.to_string() 
                         << " = " << (a * b).to_string() << endl;
                    break;
                }
                case 5: {
                    BigInt num(get_input("请输入一个整数: "));
                    cout << num.to_string() << " 的各位数字之和为: "
                         << num.decimal_digit_sum() << endl;
                    break;
                }
                case 6:
                    cout << "退出程序。" << endl;
                    return 0;
                default:
                    cout << "无效选择，请重新输入。" << endl;
            }
        } catch (const exception& e) {
            cout << "错误: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);

    return 0;
}