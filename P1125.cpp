#if 0
#include <iostream>
using namespace std;
class Priority_queue
{
    private:
    int *data;
    int size;
    int capacity;
    public:
    Priority_queue()
    {
        capacity=100;
        data = new int[capacity+1];
        size = 0;
    }

    ~Priority_queue()
    {
        while(!empty())
            pop();
    }

    void resize()
    {
        int *tmp = (int*)malloc((2 * capacity + 1) * sizeof(int));
        for(int i = 0;i <= capacity; ++i)
        {
            if(data[i])
                tmp[i] = data[i];
        }
        delete []data;
        data = new int[1*capacity+1];
        data = tmp;
    }

    bool empty()
    {
        return !size;
    }
    bool full()
    {
        return size == capacity;
    }
    void push(int x)
    {
        if(empty())
        {
            data[++size] = x; 
            return;
        }
        if(full())
            resize();
        int pos;
        for(pos = ++size; data[pos / 2] > x; pos /= 2)
            data[pos] = data[pos / 2];
        data[pos] = x;
    }

    void pop(){
        int pos,child;
        int last;
        if(empty())
            return;
        last = data[size--];
        for(pos = 1;pos * 2 <= size;pos = child)
        {
            child = 2 * pos;
            if(child != size && data[child + 1] < data[child])
                child++;
            if(last > data[child])
                data[pos] = data[child];
            else 
                break;
        }
        data[pos] = last;
    }

    int top(){
        if(empty())
            return data[0];
        return data[1];
    }

    void clear()
    {
        while(!empty())
            pop();
    }
};

Priority_queue q[300005];

int main() 
{
    int n,m,op;
    cin >> n >> m;
    for(int i = 0;i < n; ++i){
        int girl;
        scanf("%d",&girl);
        q[i].push(girl);
    }
    while(m--){
        scanf("%d",&op);
        if(op == 0)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            while(!q[b].empty())
            {
                q[a].push(q[b].top());
                q[b].pop();
            }
        }
        else if(op == 1)
        {
            int a;
            scanf("%d",&a);
            if(q[a].empty())
            {
                cout << -1 << endl;
                continue;
            }
            else
            {
                cout << q[a].top() << endl;
                q[a].pop();
                continue;
            }
        }
        else if(op == 2)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            q[a].push(b);
        }
    }
    return 0;
}
#endif