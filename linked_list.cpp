#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    struct Node * next;
};

class LinkedList
{
    public:
        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
        }
    
    private:
        Node *head;
        Node *tail;
};