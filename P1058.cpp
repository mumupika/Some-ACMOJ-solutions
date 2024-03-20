#if 0
#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{
    // attention! this linkedlist is 0-based!
    // attention! this linkedlist has head node!
    // attention! head node doesn't contain any data for the convenience of data addition!

    struct NODE {
        // TODO
        int data;
        NODE *next;
    };

    NODE *head = nullptr;
    int len = 0;

    void init() 
    {
        // TODO
        head = new NODE;
        head->data = -1;
        head->next = head;
    }

    // this function is used for the movement of pointer!
    // attention！the pointer returned will be the address of NODE(i-1) instead of NODE-i!
    // num of NODE is also 0-based!
    // if i==0, then the pointer returned will be head!
    NODE* move(int i) 
    {
        // TODO
        NODE *p = head;
        for (int j = 0; j < i; j++)
        {
            p = p->next;
        }
        return p;
        // TODO END
    }
    void insert(int i, int x) 
    {
        // TODO
        NODE *a = move(i);
        NODE *b = new NODE;
        b->data = x;
        b->next = a->next;
        a->next = b;
        len++;
        // TODO END
    }
    void remove(int i) 
    {
        // TODO
        NODE *a = move(i);
        NODE *b;
        b = a->next;
        a->next = b->next;
        delete b;
        len--;
        // TODO END
    }
    void remove_insert(int i) 
    {
        //TODO
        NODE *p = move(i);
        int x = p->next->data;
        remove(i);
        insert(len, x);
        // TODO END
    }
    void get_length() 
    {
        // TODO
        cout << len << endl;
        // TODO END
    }
    void query(int i) 
    {
        // TODO
        if (i < 0 || i > len - 1)
            cout << -1 << endl;
        else
        {
            NODE *p = move(i);
            cout << p->next->data << endl;
        }
        // TODO END
    }
    void get_max() 
    {
        // TODO
        NODE *p = head;
        if (len > 0)
        {
            int maxnum = p->data;
            while (p->next != head)
            {
                p = p->next;
                maxnum = max(maxnum, p->data);
            }
            cout << maxnum << endl;
        }
        else
            cout << -1 << endl;
        // TODO END
    }
    void clear() 
    {
        // TODO
        NODE *q = head;
        NODE *p;
        while (q->next != head)
        {
            p = q->next;
            delete q;
            q = p;
        }
        delete q;
        // TODO END
    } 
    // void QueryAll()
    // {
    //     cout << "ALL:" <<endl;
    //     NODE *p = head;
    //     for (int i = 0; i < len; i++)
    //     {
    //         p = p->next;
    //         cout << p->data << "\t";
    //     }
    //     cout << endl;
    // }
}
int n;
int main()
{
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch(op) {
            case 0:
                LIST::get_length();
                // LIST::QueryAll();
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p,x);
                // LIST::QueryAll();
                break;
            case 2:
                cin >> p;
                LIST::query(p);
                // LIST::QueryAll();
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                // LIST::QueryAll();
                break;
            case 4:
                cin >> p;
                LIST::remove_insert(p);
                // LIST::QueryAll();
                break;
            case 5:
                LIST::get_max();
                // LIST::QueryAll();
                break;
        }
    }
    LIST::clear();
    return 0;
}
#endif
