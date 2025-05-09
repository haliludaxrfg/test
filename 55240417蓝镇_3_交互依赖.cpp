#include <iostream>

class Female;

class Male {
    Female* pWife;
public:
    Male() { m_buffer[m_sum++] = this; }
    Female*& getWife() { return pWife; }
    static Male* m_buffer[100];
    static int m_sum;
};

int Male::m_sum = 0;
Male* Male::m_buffer[100];

class Female {
public:
    Male* getHusband();
};

Male* Female::getHusband() {
    for (int i = 0; i < Male::m_sum; i++) {
        if (Male::m_buffer[i]->getWife() == this) {
            return Male::m_buffer[i];
        }
    }
    return nullptr;
}

int main() {
    Male a, b;
    Female c, d;
    
    // 设置关联关系
    a.getWife() = &c;
    b.getWife() = &d;
    
    // 测试查找关联
    std::cout << "d's husband is b? " << (d.getHusband() == &b) << std::endl;
    std::cout << "c's husband is a? " << (c.getHusband() == &a) << std::endl;
    
    // 测试未关联情况
    Female e;
    std::cout << "e's husband is null? " << (e.getHusband() == nullptr) << std::endl;
    
    return 0;
}