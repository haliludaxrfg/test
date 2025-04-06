#include <iostream>
#include <set>
#include <numeric>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

int Lenth(ListNode* headnode){

    ListNode *cur = headnode;
    int cnt = 0;
    while (cur!=NULL)
    {
        cnt++;
        cur = cur->next;
    }
    return cnt;
    
}

void coutlist(ListNode *headnode)
{
    if (headnode == NULL)
    {
        cout << "NULL";
    }
    else
    {

        ListNode *cur = headnode;
        while (cur != NULL)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
}

ListNode* rightlist(ListNode *headnode){

    ListNode *cur = headnode;

    for (int i = Lenth(headnode)-1; i > Lenth(headnode)/2; i--)
    {
        cur = cur->next;
    }
    return cur;
}

void InsertTail(ListNode *&headnode, int v) {
    ListNode *newNode = new ListNode;
    newNode->val = v;
    newNode->next = NULL;

    if (headnode == NULL) {
        // 如果链表为空，新节点即为头节点
        headnode = newNode;
    } else {
        // 否则，遍历到链表尾部并添加新节点
        ListNode *cur = headnode;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
}

void FreeList(ListNode *&headnode) {
    ListNode *cur = headnode;
    while (cur != NULL) {
        ListNode *temp = cur;
        cur = cur->next;
        delete temp;
    }
    headnode = NULL; // 防止悬空指针
}

int main()
{
    ListNode *headnode = nullptr;
    
    while (1)
    {
        int _;
        cin >> _;
        if (_ == 0)
        {
            break;
        }
        InsertTail(headnode, _);
    }
    //cout <<"Lenth of All:"<<Lenth(headnode)<<endl;
    //cout <<"Lenth of Right:"<<Lenth(rightlist(headnode))<<endl;
    //coutlist(headnode);
    coutlist(rightlist(headnode));
    FreeList(headnode);
}
