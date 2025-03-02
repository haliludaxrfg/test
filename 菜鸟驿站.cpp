#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Package {
    int id; // 包裹ID
    string recipient; // 收件人姓名
    string address; // 收件人地址
    string status; // 包裹状态（如：已到达、已取走）
};

vector<Package> packages; // 存储包裹信息的向量

void addPackage() {
    Package pkg;
    cout << "请输入包裹ID: ";
    cin >> pkg.id;
    cout << "请输入收件人姓名: ";
    cin >> pkg.recipient;
    cout << "请输入收件人地址: ";
    cin >> pkg.address;
    pkg.status = "已到达";
    packages.push_back(pkg);
    cout << "包裹录入成功！" << endl;
}

void showPackages() {
    cout << "包裹信息如下：" << endl;
    for (const auto& pkg : packages) {
        cout << "ID: " << pkg.id << ", 收件人: " << pkg.recipient << ", 地址: " << pkg.address << ", 状态: " << pkg.status << endl;
    }
}

void searchPackage() {
    int id;
    cout << "请输入要查找的包裹ID: ";
    cin >> id;
    for (const auto& pkg : packages) {
        if (pkg.id == id) {
            cout << "ID: " << pkg.id << ", 收件人: " << pkg.recipient << ", 地址: " << pkg.address << ", 状态: " << pkg.status << endl;
            return;
        }
    }
    cout << "未找到该包裹！" << endl;
}

void deletePackage() {
    int id;
    cout << "请输入要删除的包裹ID: ";
    cin >> id;
    for (auto it = packages.begin(); it != packages.end(); ++it) {
        if (it->id == id) {
            packages.erase(it);
            cout << "包裹删除成功！" << endl;
            return;
        }
    }
    cout << "未找到该包裹！" << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- 菜鸟驿站管理系统 ---\n";
        cout << "1. 录入包裹信息\n";
        cout << "2. 显示所有包裹信息\n";
        cout << "3. 查找包裹信息\n";
        cout << "4. 删除包裹信息\n";
        cout << "0. 退出\n";
        cout << "请选择操作：";
        cin >> choice;
        switch (choice) {
            case 1:
                addPackage();
                break;
            case 2:
                showPackages();
                break;
            case 3:
                searchPackage();
                break;
            case 4:
                deletePackage();
                break;
            case 0:
                return 0;
            default:
                cout << "无效的选择，请重新输入！" << endl;
        }
    }
}