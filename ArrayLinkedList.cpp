// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fixed(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size()
#define Mod 1000000007
#define EPS 1e-9
#define updmax(a, b) a = max(a, b)
#define updmin(a, b) a = min(a, b)
#define nl '\n'
#define pi acos(-1.0)
void debug() { cout << "[DEBUG]" << nl; }

struct Node
{
    int val;
    int index;
    Node *next;
    Node *prv;

    Node(int val, int index)
    {
        this->val = val;
        this->index = index;
        this->next = this->prv = nullptr;
    }
};

class Array_LinkedList
{
private:
    Node *head;
    Node *tail;
    int len;
    int arraySize;

    void LinkNodes(Node *first, Node *second)
    {
        if (first)
            first->next = second;
        if (second)
            second->prv = first;
    }

public:
    // -- Constructor & Destructor -- //
    Array_LinkedList(int n) // constructor to set the size of the array
    {
        head = tail = nullptr;
        arraySize = n;
        len = 0;
    }

    ~Array_LinkedList()
    {
        Node *cur = head;
        while (cur)
        {
            Node *nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    // -- Main Functions -- //
    bool isempty()
    {
        return head == nullptr;
    }

    int get(int idx)
    {
        if (idx < 0 || idx >= arraySize)
            return 0;

        Node *cur = head;
        while (cur && cur->index < idx)
            cur = cur->next;

        if (cur && cur->index == idx)
            return cur->val;

        return 0;
    }

    void set(int idx, int val)
    {
        if (idx < 0 || idx >= arraySize)
            return;

        if (val == 0)
        {
            erase(idx);
            return;
        }

        if (isempty())
        {
            head = tail = new Node(val, idx);
            len++;
            return;
        }

        if (idx < head->index)
        {
            Node *node = new Node(val, idx);
            LinkNodes(node, head);
            head = node;
            len++;
            return;
        }

        Node *cur = head;
        while (cur->next && cur->next->index < idx)
            cur = cur->next;

        if (cur->index == idx) // update the value
        {
            cur->val = val;
        }

        if (cur->next && cur->next->index == idx) // to check if the last node is the correct index update it
        {
            cur->next->val = val;
            return;
        }

        // insert new node
        Node *node = new Node(val, idx);
        node->next = cur->next;
        node->prv = cur;

        if (cur->next)
            cur->next->prv = node;

        cur->next = node;

        if (cur == tail)
            tail = node;

        len++;
    }

    void erase(int idx)
    {
        if (isempty())
            return;

        Node *cur = head;
        while (cur && cur->index < idx)
            cur = cur->next;

        if (!cur || cur->index != idx)
            return; // you didn't found the correct node

        if (cur == head)
        {
            head = head->next;
            if (head)
                head->prv = nullptr;
            else
                tail = nullptr;

            delete cur;
            len--;
            return;
        }

        if (cur->prv)
            cur->prv->next = cur->next;
        if (cur->next)
            cur->next->prv = cur->prv;
        if (cur == tail)
            tail = cur->prv;

        delete cur;
        len--;
    }

    void printArray()
    {
        Node *cur = head;
        int lastIndx = -1;
        while (cur)
        {
            for (int i = lastIndx + 1; i < cur->index; i++)
                cout << 0 << " ";

            cout << cur->val << " ";

            lastIndx = cur->index;
            cur = cur->next;
        }

        for (int i = lastIndx + 1; i < arraySize; i++)
            cout << 0 << " ";

        cout << nl;
    }

    void printNonZero()
    {
        Node *cur = head;
        while (cur)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }

        cout << nl;
    }

    // -- Additional Functions -- //
    int getArraySize()
    {
        return this->arraySize;
    }

    int getListSize()
    {
        return this->len;
    }

    int Max_element()
    {
        if (isempty())
            return 0;
        int maxi = head->val;
        Node *cur = head;
        while (cur)
        {
            updmax(maxi, cur->val);
            cur = cur->next;
        }

        return maxi;
    }

    int Min_element()
    {
        return 0;
    }

    int Min_element_NonZero()
    {
        if (isempty())
            return 0;
        int mini = head->val;
        Node *cur = head;
        while (cur)
        {
            updmin(mini, cur->val);
            cur = cur->next;
        }

        return mini;
    }

    int found(int val)
    {
        if (isempty())
            return -1;

        if (val == 0)
        {
            if (len == arraySize)
            {
                return -1;
            }
            else
            {
                if (head->index != 0)
                    return 0;

                Node *cur = head->next;
                int rt = 1;
                while (cur && cur->index == rt)
                {
                    cur = cur->next;
                    rt++;
                }

                return rt;
            }
        }
        else
        {
            Node *cur = head;
            while (cur)
            {
                if (cur->val == val)
                    return cur->index;
                cur = cur->next;
            }
        }

        return -1;
    }

    void clear()
    {
        Node *cur = head;
        while (cur)
        {
            Node *nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
};

int main()
{

    return 0;
}