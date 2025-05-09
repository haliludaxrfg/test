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
using namespace std;
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
    // 支持下标运算符
    // 允许使用下标访问字符
    char& operator[](size_t index) { return m_data[index]; }  
    const char& operator[](size_t index) const { return m_data[index]; }  
    //字符串截取
    MyString operator()(int start, int end) const {
        // 处理参数范围
        int start_idx = std::max(0, start);
        int end_idx = std::min(end, static_cast<int>(m_length) - 1);
        
        start_idx = std::min(start_idx, static_cast<int>(m_length) - 1);
        end_idx = std::max(end_idx, 0);

        if (start_idx > end_idx) {
            std::swap(start_idx, end_idx);
        }

        size_t sub_len = end_idx - start_idx + 1;

        MyString result;
        result.deepCopy(m_data + start_idx, sub_len);

        return result;
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

    MyString& operator+=(const MyString& rhs) { 
        size_t new_length = m_length + rhs.m_length;
        char* new_data = new char[new_length + 1];
        std::strcpy(new_data, m_data);
        std::strcat(new_data, rhs.m_data);
        delete[] m_data;
        m_data = new_data;
        m_length = new_length;
        return *this;
     }

    bool operator==(const MyString& rhs) const { 
        if (m_length != rhs.m_length) return false;
        return std::strcmp(m_data, rhs.m_data) == 0;
     }

    size_t length() const { return m_length; }
    const char* c_str() const { return m_data; }

    friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
        return os << str.m_data;
    }
};

// 使用示例
int main() {
    MyString m("software");
    MyString n(m),o;
    o = m;
    cout << o << endl;     
    cout << n[4] << endl;             // 输出第4位字符
    cout << n.length() << endl;        // 输出字符串的长度
    o = m + n;                              // 合并字符串
    cout << o << endl;     
    o = m(2, 8);                   // 截取从2位到第8位的子字符串
    cout << o << endl;                    // 输出合并后的字符串
    cout << o.length() << endl;        // 输出合并后的字符串长度
    cout << o.c_str() << endl;        // 输出合并后的字符串内容
    return 0;
}