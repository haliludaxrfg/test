#include <iostream>
#include <set>
using namespace std;
// 从小到大排序列表
struct ListNode
{
    int val;
    ListNode *next;
};
// 打印
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

class MergeSort
{
public:
    // 归并算法：分治阶段
    ListNode *sortList(ListNode *headnode)
    {
        if (!headnode || !headnode->next)
        {
            return headnode;
        }
        ListNode *slow = headnode;
        ListNode *fast = headnode->next;
        while (fast && fast->next) // 快指针到边界
        {
            slow = slow->next;
            fast = fast->next->next;
            /* code */
        }
        ListNode *second = slow->next; // 后半组链表
        slow->next = NULL;
        ListNode *first = headnode;
        first = sortList(first);
        second = sortList(second);
        return mergeList(first, second);
    }
    // 归并算法：合并阶段
    ListNode *mergeList(ListNode *left, ListNode *right)
    {
        ListNode *dummy = new ListNode{0, nullptr};
        ListNode *tail = dummy;
        while (left && right)
        {
            if (left->val < right->val)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
            /* code */
        }
        if (left)
        {
            tail->next = left;
        }
        else
        {
            tail->next = right;
        }
        return dummy->next;
    }
};
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

    MergeSort mergeSort;

    // 对链表进行排序
    ListNode *sortedHead = mergeSort.sortList(headnode);

    // 打印排序后的链表
    coutlist(sortedHead);
}