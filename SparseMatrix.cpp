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

// column list
struct ColumnNode
{
    int val, index;
    ColumnNode *next, *prv;

    ColumnNode(int item, int idx)
    {
        val = item;
        index = idx;
        next = prv = nullptr;
    }
};

class Column
{
private:
    ColumnNode *head, *tail;
    int len, columnSize;

    void link(ColumnNode *a, ColumnNode *b)
    {
        if (a)
            a->next = b;
        if (b)
            b->prv = a;
    }

public:
    Column(int n)
    {
        head = tail = nullptr;
        len = 0;
        columnSize = n;
    }

    ~Column()
    {
        ColumnNode *cur = head;
        while (cur)
        {
            ColumnNode *nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

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
            erase(idx);
            return;
        }

        if (isempty())
        {
            head = tail = new ColumnNode(val, idx);
            len++;
            return;
        }

        if (idx < head->index)
        {
            ColumnNode *node = new ColumnNode(val, idx);
            link(node, head);
            head = node;
            len++;
            return;
        }

        ColumnNode *cur = head;
        while (cur->next && cur->next->index < idx)
            cur = cur->next;

        if (cur->index == idx)
        {
            cur->val = val;
            return;
        }

        if (cur->next && cur->next->index == idx)
        {
            cur->next->val = val;
            return;
        }

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
        }
        else
        {
            cur->prv->next = cur->next;
            if (cur->next)
                cur->next->prv = cur->prv;
            if (cur == tail)
                tail = cur->prv;
        }

        delete cur;
        len--;
    }

    void printColumn()
    {
        ColumnNode *cur = head;
        int last = -1;

        while (cur)
        {
            for (int i = last + 1; i < cur->index; i++)
                cout << 0 << " ";

            cout << cur->val << " ";
            last = cur->index;
            cur = cur->next;
        }

        for (int i = last + 1; i < columnSize; i++)
            cout << 0 << " ";

        cout << nl;
    }
};

// row list
struct rowNode
{
    Column list;
    int rowIndex;
    rowNode *next, *prv;

    rowNode(int idx, int colSize) : list(colSize)
    {
        rowIndex = idx;
        next = prv = nullptr;
    }
};

class sparseMatrix
{
private:
    rowNode *head, *tail;
    int rowCnt, colCnt;

    bool valid(int r, int c)
    {
        return r >= 0 && r < rowCnt && c >= 0 && c < colCnt;
    }

public:
    sparseMatrix(int rows, int cols)
    {
        head = tail = nullptr;
        rowCnt = rows;
        colCnt = cols;

        for (int i = 0; i < rowCnt; i++)
            appendRow(i);
    }

    ~sparseMatrix()
    {
        rowNode *cur = head;
        while (cur)
        {
            rowNode *nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    void appendRow(int rowIdx)
    {
        rowNode *node = new rowNode(rowIdx, colCnt);

        if (!head)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            node->prv = tail;
            tail = node;
        }
    }

    rowNode *getRow(int idx)
    {
        rowNode *cur = head;
        while (cur && cur->rowIndex != idx)
            cur = cur->next;

        return cur;
    }

    void set(int r, int c, int val)
    {
        if (!valid(r, c))
            return;

        rowNode *row = getRow(r);
        row->list.set(c, val);
    }

    int get(int r, int c)
    {
        if (!valid(r, c))
            return 0;

        rowNode *row = getRow(r);
        return row->list.get(c);
    }

    void printMatrix()
    {
        rowNode *cur = head;
        while (cur)
        {
            cur->list.printColumn();
            cur = cur->next;
        }
    }
};

int main()
{

    return 0;
}
