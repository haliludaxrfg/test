#include <iostream>
#include <set>
#include <numeric>
using namespace std;
// 本题目标是去重
struct ListNode
{
    int val;
    ListNode *next;
};
// 打印
int Lenth(ListNode* headnode){
    ListNode *dummyHead = new ListNode;
    dummyHead->next = headnode; // The true head is headnode.

    ListNode *cur = dummyHead;
    int cnt = -1;
    while (cur!=NULL)
    {
        cnt++;
        cur = cur->next;
    }
    return cnt;
    
}

int valofnode(ListNode *headnode,int pos){
    ListNode *dummyHead = new ListNode;
    dummyHead->next = headnode; // The true head is headnode.

    ListNode *cur = dummyHead;
    int cnt = -1;
    int value = 0;
    while (cur->next != NULL)
    {
        cnt++;
        cur = cur->next;
        if(pos == cnt){
            value = cur ->val;
            break;
        }
    }
    return value;
}

void checkval(int _){
    if (_!=0)
    {
        cout <<_;
    }else{
        cout <<"NULL";
    }    
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
// 尾插


void InsertTail(ListNode *&headnode, int v)
{
    if (headnode == NULL)
    {
        ListNode *node = new ListNode;
        headnode = node;
        headnode->val = v;
        headnode->next = NULL;
        return;
    }
    else
    {
        ListNode *cur = headnode;
        while (cur->next != NULL)
        {
            cur = cur->next;
        } // tail
        ListNode *newNode = new ListNode;
        newNode->val = v;
        newNode->next = NULL;
        cur->next = newNode;
    }
}

// 无重复尾插
set<int> exists; // 全局变量？
void InsertTail_norepeated(ListNode *&headnode, int v) {
    if (exists.find(v) == exists.end()) {
        InsertTail(headnode, v);
        exists.insert(v);
    }
}
// 头插
void InsertHead(ListNode *&headnode, int v)
{
    ListNode *newNode = new ListNode;
    newNode->val = v;
    newNode->next = headnode;
    headnode = newNode;
}

// 删掉特定值
ListNode *removeNode(ListNode *headnode, int v)
{
    // dummyhead
    ListNode *dummyHead = new ListNode;
    dummyHead->next = headnode; // The true head is headnode.

    ListNode *cur = headnode;
    while (cur->next != NULL)
    {
        if (cur->next->val == v) // previous one
        {
            ListNode *temp = cur->next; // to be deleted
            cur->next = cur->next->next;
            delete temp;
        }
        else
        {
            cur = cur->next;
        }
    }
    return dummyHead->next;
}
// 向某个值的结点前插入一个值
ListNode *addNode(ListNode *headnode, int v, int num)
{
    // dummyhead
    ListNode *dummyHead = new ListNode;
    dummyHead->next = headnode; // The true head is headnode.

    ListNode *cur = dummyHead;
    while (cur != NULL)
    {
        if (cur->val == v)
        {
            ListNode *node = new ListNode;
            node->val = num;
            node->next = cur->next; // node is linked with next node.
            cur->next = node;       // node is linked with cur.
        }
        else
        {
            cur = cur->next;
        }
    }

    return dummyHead->next;
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
    int K;cin >>K;
    //cout <<"Lenth:"<<Lenth(headnode)<<endl;
    checkval(valofnode(headnode,Lenth(headnode)-K));
    //coutlist(headnode);
}
