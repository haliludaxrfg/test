#include <iostream>
using namespace std;

struct ListNode {
    int numerator, denominator;
    ListNode *next;
};

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

void coutlist(ListNode *headnode)
{
    if (headnode == NULL)
        cout << "NULL";
    else
    {
        ListNode *cur = headnode;
        while (cur != NULL)
        {
            cout << cur->numerator << "/" << cur->denominator << " ";
            cur = cur->next;
        }
    }
}

void dfs(ListNode*& headnode, long x1, long y1, long x2, long y2, int n) {
    if (y1 + y2 > n) return;
    long x = x1 + x2, y = y1 + y2;
    if (gcd(x, y) == 1) { // Only insert if x/y is in its simplest form
        ListNode *newNode = new ListNode{x, y, NULL};
        ListNode **insertPos = &headnode;
        while (*insertPos != NULL && (*insertPos)->numerator * y < x * (*insertPos)->denominator) {
            insertPos = &((*insertPos)->next);
        }
        newNode->next = *insertPos;
        *insertPos = newNode;
    }
    dfs(headnode, x1, y1, x, y, n);
    dfs(headnode, x, y, x2, y2, n);
}

ListNode *FareyList(int n)
{
    if (n < 1)
        return NULL;
    else
    {
        ListNode *headnode = new ListNode{0, 1, NULL};
        ListNode *tail = new ListNode{1, 1, NULL};
        headnode->next = tail;
        dfs(headnode, 0, 1, 1, 1, n);
        return headnode;
    }
}

void FreeList(ListNode *&headnode) {
    ListNode *cur = headnode;
    while (cur != NULL) {
        ListNode *temp = cur;
        cur = cur->next;
        delete temp;
    }
    headnode = NULL;
}

int main() {
    int n;
    cin >> n;
    ListNode* headnode = FareyList(n);
    coutlist(headnode);
    FreeList(headnode);
    return 0;
}
