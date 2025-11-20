// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define updmax(a,b) a = max(a,b)
#define updmin(a,b) a = min(a,b)
#define nl '\n'

// -------- Column (sparse 1D array) --------
struct ColumnNode {
    int val;
    int index;
    ColumnNode *next;
    ColumnNode *prev;

    ColumnNode(int val, int index) {
        this->val = val;
        this->index = index;
        next = prev = nullptr;
    }
};

class Column {
private:
    ColumnNode* head;
    ColumnNode* tail;
    int len;
    int columnSize;

    void link(ColumnNode* a, ColumnNode* b) {
        if(a) a->next = b;
        if(b) b->prev = a;
    }

public:
    Column(int n) : head(nullptr), tail(nullptr), len(0), columnSize(n) {}

    ~Column() {
        ColumnNode* cur = head;
        while(cur) {
            ColumnNode* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    bool empty() { return head == nullptr; }

    int get(int idx) {
        if(idx < 0 || idx >= columnSize) return 0;
        ColumnNode* cur = head;
        while(cur && cur->index < idx) cur = cur->next;
        if(cur && cur->index == idx) return cur->val;
        return 0;
    }

    void set(int idx, int val) {
        if(idx < 0 || idx >= columnSize) return;
        if(val == 0) { erase(idx); return; }

        if(empty()) { head = tail = new ColumnNode(val, idx); len++; return; }
        if(idx < head->index) { 
            ColumnNode* node = new ColumnNode(val, idx); 
            link(node, head); head = node; len++; return; 
        }

        ColumnNode* cur = head;
        while(cur->next && cur->next->index < idx) cur = cur->next;

        if(cur->index == idx) { cur->val = val; return; }
        if(cur->next && cur->next->index == idx) { cur->next->val = val; return; }

        ColumnNode* node = new ColumnNode(val, idx);
        node->next = cur->next;
        node->prev = cur;
        if(cur->next) cur->next->prev = node;
        cur->next = node;
        if(cur == tail) tail = node;
        len++;
    }

    void erase(int idx) {
        if(empty()) return;
        ColumnNode* cur = head;
        while(cur && cur->index < idx) cur = cur->next;
        if(!cur || cur->index != idx) return;

        if(cur == head) {
            head = head->next;
            if(head) head->prev = nullptr; else tail = nullptr;
            delete cur; len--; return;
        }

        if(cur->prev) cur->prev->next = cur->next;
        if(cur->next) cur->next->prev = cur->prev;
        if(cur == tail) tail = cur->prev;
        delete cur; len--;
    }

    void printColumn() {
        ColumnNode* cur = head;
        int last = -1;
        while(cur) {
            for(int i=last+1;i<cur->index;i++) cout << 0 << " ";
            cout << cur->val << " ";
            last = cur->index;
            cur = cur->next;
        }
        for(int i=last+1;i<columnSize;i++) cout << 0 << " ";
        cout << nl;
    }
};

// -------- RowNode containing Column --------
struct RowNode {
    Column list; // sparse row
    int rowIndex;
    RowNode* next;
    RowNode* prev;

    RowNode(int rowIndex, int colCount) : list(colCount), rowIndex(rowIndex), next(nullptr), prev(nullptr) {}
};

// -------- SparseMatrix (linked rows) --------
class SparseMatrix {
private:
    RowNode* head;
    RowNode* tail;
    int rowCount;
    int colCount;

    void link(RowNode* a, RowNode* b) {
        if(a) a->next = b;
        if(b) b->prev = a;
    }

public:
    SparseMatrix(int rows, int cols) : head(nullptr), tail(nullptr), rowCount(rows), colCount(cols) {
        // pre-create all rows
        for(int i=0;i<rowCount;i++) appendRow(i);
    }

    ~SparseMatrix() {
        RowNode* cur = head;
        while(cur) {
            RowNode* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    void appendRow(int rowIndex) {
        RowNode* node = new RowNode(rowIndex, colCount);
        if(!head) head = tail = node;
        else { tail->next = node; node->prev = tail; tail = node; }
    }

    RowNode* getRow(int rowIndex) {
        RowNode* cur = head;
        while(cur && cur->rowIndex != rowIndex) cur = cur->next;
        return cur;
    }

    void set(int row, int col, int val) {
        if(row<0 || row>=rowCount || col<0 || col>=colCount) return;
        RowNode* r = getRow(row);
        if(r) r->list.set(col, val);
    }

    int get(int row, int col) {
        if(row<0 || row>=rowCount || col<0 || col>=colCount) return 0;
        RowNode* r = getRow(row);
        if(r) return r->list.get(col);
        return 0;
    }

    void printMatrix() {
        RowNode* cur = head;
        while(cur) {
            cur->list.printColumn();
            cur = cur->next;
        }
        cout << nl;
    }
};

// -------- Main Example --------
int main() {
    SparseMatrix mat(4,5); 

    mat.set(0,1,7);
    mat.set(0,3,10);
    mat.set(1,2,5);
    mat.set(3,4,8);


    mat.printMatrix();




    return 0;
}
