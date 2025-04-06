/*C语言没有字符串类型，C++提供了String类型，模拟String的封装，定义CString类。保证支持如下调用功能：
CString   m("software");
CString n(m),o;
o = m;
cout<<n[4]<<endl;             //输出第4位字符；
cout<<n.len()<<endl;        //输出字符串的长度
o = m+n;                              //合并字符串
o = m(2,8);                          //截取从2位到第8位的子字符串
报告要求：
（1）详细描述题目要求；
（2）画出主要流程图，并给出必要的文字说明；
（3）分析程序难点，并讨论解决问题思路；
（4）分析所实现程序的优点和缺点；
（5）你的收获。*/
#include <cstring>
#include <iostream>

class MyString {
private:
    char* m_data;
    size_t m_length;

    void deepCopy(const char* str, size_t len) {
        m_data = new char[len + 1];
        std::memcpy(m_data, str, len);
        m_data[len] = '\0';
        m_length = len;
    }

public:
    // 允许隐式转换的构造函数
    MyString(const char* str = nullptr) {
        if (str) {
            m_length = std::strlen(str);
            deepCopy(str, m_length);
        } else {
            m_data = new char[1];
            m_data[0] = '\0';
            m_length = 0;
        }
    }

    // 拷贝构造函数
    MyString(const MyString& other) {
        deepCopy(other.m_data, other.m_length);
    }

    // 移动构造函数
    MyString(MyString&& other) noexcept 
        : m_data(other.m_data), m_length(other.m_length) {
        other.m_data = nullptr;
        other.m_length = 0;
    }

    ~MyString() {
        delete[] m_data;
    }

    // 拷贝赋值
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            char* new_data = new char[other.m_length + 1];
            std::memcpy(new_data, other.m_data, other.m_length + 1);
            delete[] m_data;
            m_data = new_data;
            m_length = other.m_length;
        }
        return *this;
    }

    // 支持 const char* 的赋值
    MyString& operator=(const char* str) {
        if (str == nullptr) {
            delete[] m_data;
            m_data = new char[1];
            m_data[0] = '\0';
            m_length = 0;
        } else {
            size_t new_length = std::strlen(str);
            char* new_data = new char[new_length + 1];
            std::memcpy(new_data, str, new_length + 1);
            delete[] m_data;
            m_data = new_data;
            m_length = new_length;
        }
        return *this;
    }

    // 移动赋值
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] m_data;
            m_data = other.m_data;
            m_length = other.m_length;
            other.m_data = nullptr;
            other.m_length = 0;
        }
        return *this;
    }

    // 修复内存泄漏的 operator+
    MyString operator+(const MyString& rhs) const {
        MyString result;
        delete[] result.m_data;  // 释放默认构造分配的内存
        result.m_length = m_length + rhs.m_length;
        result.m_data = new char[result.m_length + 1];
        std::strcpy(result.m_data, m_data);
        std::strcat(result.m_data, rhs.m_data);
        return result;
    }

    // 可选：全局 operator+ 支持字符串字面量
    friend MyString operator+(const MyString& lhs, const char* rhs) {
        return lhs + MyString(rhs);
    }

    friend MyString operator+(const char* lhs, const MyString& rhs) {
        return MyString(lhs) + rhs;
    }

    MyString& operator+=(const MyString& rhs) { /* 原有实现 */ }

    bool operator==(const MyString& rhs) const { /* 原有实现 */ }

    size_t length() const { return m_length; }
    const char* c_str() const { return m_data; }

    friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
        return os << str.m_data;
    }
};

// 使用示例
int main() {
    MyString s1;
    MyString s2 = "Hello";      // 隐式调用构造函数
    MyString s3 = s2;
    MyString s4 = std::move(s3);

    s1 = "World";               // 调用 operator=(const char*)
    MyString s5 = s2 + " " + s1;

    std::cout << s5 << std::endl;       // 输出：Hello World
    std::cout << "Length: " << s5.length() << std::endl; // 输出：11

    return 0;
}