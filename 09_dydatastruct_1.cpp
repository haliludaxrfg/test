#include <iostream>
using namespace std;
/*
int main(){
    vector <int> nums;
    int _;
    while (1)
    {
        cin >> _;
        if(_==0)
            break;
        else
            nums.push_back(_);
    }

    if(nums.empty())
        printf("NULL");
    else{
        for(auto &a:nums){
            cout << a <<" ";
        }
    }

}*/
// 用vector秒了，真的是招笑了
struct ListNode
{
    int val;
    ListNode *next;
};
// 打印
void printList(ListNode *L)
{
    if (L == NULL)
    {
        cout << "NULL";
    }
    else
    {

        ListNode *cur = L;
        while (cur != NULL)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
}
// 尾插

void InsertTail(ListNode *&L, int v)
{
    if (L == NULL)
    {
        ListNode *node = new ListNode;
        L = node;
        L->val = v;
        L->next = NULL;
        return;
    }
    else
    {
        ListNode *cur = L;
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
// 头插
void InsertHead(ListNode *&L, int v)
{
    ListNode *newNode = new ListNode;
    newNode->val = v;
    newNode->next = L;
    L = newNode;
}
// 删掉特定值
ListNode *removeNode(ListNode *L, int v)
{
    // dummyhead
    ListNode *dummyHead = new ListNode;
    dummyHead->next = L; // The true head is L.

    ListNode *cur = L;
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
ListNode *addNode(ListNode *L, int v, int num)
{
    // dummyhead
    ListNode *dummyHead = new ListNode;
    dummyHead->next = L; // The true head is L.

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
   ListNode* L = new ListNode;//头指针为L
   L = nullptr;
   while(1){
    int _;cin>>_;
    if(_==0){
        break;
        }
    InsertTail(L,_);
   }
   printList(L);
}
