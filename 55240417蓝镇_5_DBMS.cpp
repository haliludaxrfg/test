/*> 模拟一个小型数据库系统（DBMS）的实现。最小化的实现数据库和数据表的管理，实现数据库、数据表和数据的增加、查询、修改和删除（可以考虑多态）。
数据存储使用IO流类，存储文件可以用文本格式也可以用XML或者其他专门格式；操作指令发布可以使用界面，可以使用自定义管理器支持的简单字符命令定义或者类似SQL语言。  
（1）阐述对数据库、数据表、数据的理解；阐述对SQL语言的理解。（这些概念可以查查资料）  
（2）详细分类描述题目要求；  
（3）觉得实现麻烦吗？麻烦在哪里，有何更好的解决方式？  
（4）分析程序难点，并讨论解决问题思路；  
（5）数据库在一个软件中的地位？  
（6）有何收获？  
   提交内容：程序代码（请删除可执行文件）+报告  
   文件命名规范：学号+姓名+题号+代码；学号+姓名+题号+报告*/
#include <bits/stdc++.h>
using namespace std;

// 定义一个结构体表示数据表中的一行
struct Record {
    string phone;  // 手机号
    string name;   // 姓名
    int age;       // 年龄
    double balance; // 存款

    // 打印记录
    void print() const {
        cout << "Phone: " << phone << ", Name: " << name
             << ", Age: " << age << ", Balance: " << balance << endl;
    }

    // 将记录转换为字符串（用于文件存储）
    string toString() const {
        stringstream ss;
        ss << phone << "," << name << "," << age << "," << balance;
        return ss.str();
    }

    // 从字符串解析记录（用于文件加载）
    static Record fromString(const string& str) {
        stringstream ss(str);
        Record record;
        getline(ss, record.phone, ',');
        getline(ss, record.name, ',');
        ss >> record.age;
        ss.ignore(1); // 跳过逗号
        ss >> record.balance;
        return record;
    }
};

// 数据库类
class Database {
private:
    vector<Record> table; // 模拟数据表
    const string filename = "DBMSexp.txt"; // 数据文件名

    // 从文件加载数据
    void loadFromFile() {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "No existing data file found. Starting with an empty database." << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                table.push_back(Record::fromString(line));
            }
        }
        file.close();
        cout << "Data loaded from file successfully!" << endl;
    }

    // 将数据保存到文件
    void saveToFile() const {
        ofstream file(filename, ios::trunc);
        if (!file.is_open()) {
            cerr << "Error: Unable to open file " << filename << " for writing!" << endl;
            perror("Details");
            return;
        }

        for (const auto& record : table) {
            file << record.toString() << endl;
        }
        file.close();
        // 输出文件绝对路径
        std::error_code ec;
        auto abs_path = std::filesystem::absolute(filename, ec);
        if (!ec) {
            cout << "Data saved to: " << abs_path << endl;
        } else {
            cout << "Data saved to file (unable to resolve path)" << endl;
        }
    }

public:
    Database() {
        loadFromFile();
    }

    ~Database() {
        saveToFile();
    }

    // 增加记录
    void addRecord(const Record& record) {
    // 检查手机号是否已存在
    auto it = find_if(table.begin(), table.end(), [&](const Record& r) {
        return r.phone == record.phone;
    });

    if (it == table.end()) {
        table.push_back(record);
        cout << "Record added successfully!" << endl;
    } else {
        cout << "Error: Phone number already exists!" << endl;
    }
}

    // 删除记录（根据手机号）
    void deleteRecord(const string& phone) {
        auto it = remove_if(table.begin(), table.end(), [&](const Record& record) {
            return record.phone == phone;
        });

        if (it != table.end()) {
            table.erase(it, table.end());
            cout << "Record deleted successfully!" << endl;
        } else {
            cout << "Record not found!" << endl;
        }
    }

    // 查询记录（根据手机号）
    void queryRecord(const string& phone) const {
        auto it = find_if(table.begin(), table.end(), [&](const Record& record) {
            return record.phone == phone;
        });

        if (it != table.end()) {
            it->print();
        } else {
            cout << "Record not found!" << endl;
        }
    }

    // 修改记录（根据手机号）
    void updateRecord(const string& phone, const Record& newRecord) {
        auto it = find_if(table.begin(), table.end(), [&](const Record& record) {
            return record.phone == phone;
        });

        if (it != table.end()) {
            *it = newRecord;
            cout << "Record updated successfully!" << endl;
        } else {
            cout << "Record not found!" << endl;
        }
    }

    // 打印所有记录
    void printAllRecords() const {
        if (table.empty()) {
            cout << "No records found!" << endl;
            return;
        }

        for (const auto& record : table) {
            record.print();
        }
    }
};

class DBMSTerminal {
private:
    Database db;

    // 清除输入错误状态并跳过无效输入
    void clearInputError() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // 获取用户输入的整数
    int getIntInput(const string& prompt) {
        int value;
        while (true) {
            cout << prompt;
            cin >> value;
            if (cin.fail()) {
                clearInputError();
                cout << "Invalid input! Please enter a number." << endl;
            } else {
                clearInputError();
                return value;
            }
        }
    }

    // 获取用户输入的双精度浮点数
    double getDoubleInput(const string& prompt) {
        double value;
        while (true) {
            cout << prompt;
            cin >> value;
            if (cin.fail()) {
                clearInputError();
                cout << "Invalid input! Please enter a number." << endl;
            } else {
                clearInputError();
                return value;
            }
        }
    }

public:
    void showMenu() {
        while (true) {
            cout << "\n===== Mini DBMS Menu =====" << endl;
            cout << "1. Add Record" << endl;
            cout << "2. Query Record" << endl;
            cout << "3. Update Record" << endl;
            cout << "4. Delete Record" << endl;
            cout << "5. List All Records" << endl;
            cout << "0. Exit" << endl;
            
            int choice = getIntInput("Enter your choice (0-5): ");

            switch (choice) {
                case 1: addRecordHandler(); break;
                case 2: queryRecordHandler(); break;
                case 3: updateRecordHandler(); break;
                case 4: deleteRecordHandler(); break;
                case 5: listAllHandler(); break;
                case 0: cout << "Exiting..." << endl; return;
                default: cout << "Invalid choice!" << endl;
            }
        }
    }

private:
    // 新增：各操作的处理函数
    void addRecordHandler() {
        Record record;
        cout << "\nEnter phone number: ";
        getline(cin, record.phone);
        
        cout << "Enter name: ";
        getline(cin, record.name);

        record.age = getIntInput("Enter age: ");
        record.balance = getDoubleInput("Enter balance: ");

        db.addRecord(record);
    }

    void queryRecordHandler() {
        string phone;
        cout << "\nEnter phone number to query: ";
        getline(cin, phone);
        db.queryRecord(phone);
    }

    void updateRecordHandler() {
        string oldPhone;
        cout << "\nEnter phone number to update: ";
        getline(cin, oldPhone);

        Record newRecord;
        cout << "Enter new phone number: ";
        getline(cin, newRecord.phone);
        cout << "Enter new name: ";
        getline(cin, newRecord.name);
        newRecord.age = getIntInput("Enter new age: ");
        newRecord.balance = getDoubleInput("Enter new balance: ");

        db.updateRecord(oldPhone, newRecord);
    }

    void deleteRecordHandler() {
        string phone;
        cout << "\nEnter phone number to delete: ";
        getline(cin, phone);
        db.deleteRecord(phone);
    }

    void listAllHandler() {
        cout << "\n=== All Records ===" << endl;
        db.printAllRecords();
    }
};

// 修改后的主函数
int main() {
    DBMSTerminal terminal;
    terminal.showMenu();
    return 0;
}