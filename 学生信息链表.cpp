#include <bits/stdc++.h>
using namespace std;

struct Listnode {
    int studynum;
    string name;
    string phone;
    Listnode *next;
};

Listnode* createNode(int studynum, string name, string phone) {
    Listnode* newNode = new Listnode();
    newNode->studynum = studynum;
    newNode->name = name;
    newNode->phone = phone;
    newNode->next = NULL;
    return newNode;
}

void add(Listnode*& head, int nstudynum, string nname, string nphone) {
    Listnode* newNode = createNode(nstudynum, nname, nphone);
    // 如果链表为空，或者新节点的学号小于头节点的学号，则新节点成为新的头节点
    if (head == NULL || head->studynum >= nstudynum) {
        newNode->next = head;
        head = newNode;
        return;
    }
    
    // 否则，找到正确的插入位置
    Listnode* cur = head;
    while (cur->next != NULL && cur->next->studynum < nstudynum) {
        cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
}

int main() {
    int n;
    cin >> n;
    Listnode* head = NULL;

    for (int i = 0; i < n; i++) {
        int studynum;
        string name;
        string phone;
        cin >> studynum >> name >> phone; // 读取节点信息
        add(head, studynum, name, phone);
    }
    cout<<endl;
    // 打印链表以验证插入操作
    Listnode* cur = head;
    while (cur != NULL) {
        cout << cur->studynum << " " << cur->name << " " << cur->phone << endl;
        cur = cur->next;
    }

    // 释放链表内存
    while (head != NULL) {
        Listnode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
