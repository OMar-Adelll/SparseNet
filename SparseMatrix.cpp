// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define int long long
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

struct ColumnNode
{
    int val;
    int index;
    ColumnNode *next;
    ColumnNode *prv;

    ColumnNode(int item, int index)
    {
        this->val = item;
        this->index = index;
        next = prv = nullptr;
    }
};

class Column
{
private:
    ColumnNode *head;
    ColumnNode *tail;
    int len;
    int columnSize;

    void link(ColumnNode *f, ColumnNode *s)
    {
        if (f)
            f->next = s;
        if (s)
            s->prv = f;
    }

public:
    Column(int n) : head(nullptr), tail(nullptr), len(0), columnSize(n) {}
    ~Column()
    {
        ColumnNode *cur = head;
        while (cur)
        {
            ColumnNode *nxt = head->next;
            delete cur;
            cur = nxt;
        }
    }

    // -- Main Functions -- //
    bool isempty() { return head == nullptr; }

    int get(int idx)
    {
        if (idx < 0 || idx >= columnSize)
            return 0;
        ColumnNode *cur = head;
        while (cur && cur->index < idx)
            cur = cur->next;
        if (cur && cur->index == idx)
            return cur->val;

        return 0;
    }

    void set(int idx, int val)
    {
        if (idx < 0 || idx >= columnSize)
            return;

        if (val == 0)
        {
            // erase(idx);
            return;
        }

        // is the matrix with no columns or idx of column is smaller than the first one
        if (isempty())
        {
            head = tail = new ColumnNode(val, idx);
            len++;
            return;
        }

        if (idx < head->index)
        {
            ColumnNode *col = new ColumnNode(val, idx);
            link(col, head);
            head = col;
            len++;
        }

        // update node
        ColumnNode *cur = head;
        while (cur->next && cur->next->index < idx)
            cur = cur->next;

        if (cur->index == idx)
            cur->val = val;

        if (cur->next && cur->next->index == idx)
        {
            cur->next->val = val;
            return;
        }

        // new column
        ColumnNode *node = new ColumnNode(val, idx);
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
        ColumnNode *cur = head;
        while (cur && cur->index < idx)
            cur = cur->next;

        if (!cur || cur->index != idx)
            return;

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

        len--;
        delete cur;
    }

    void printColumn()
    {
        ColumnNode *cur = head;
        int LastIdx = -1;
        while (cur)
        {
            for (int i = LastIdx + 1; i < cur->index; i++)
                cout << 0 << " ";
            cout << cur->val << " ";
            LastIdx = cur->index;
            cur = cur->next;
        }

        for (int i = LastIdx + 1; i < columnSize; i++)
            cout << 0 << " ";
        cout << nl;
    }
};

signed main()
{

    return 0;
}