#if 0
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

priority_queue<int, vector<int>, greater<int>> biheap;

ll Bo(int n)
{
    ll ans = 0;
    int* price;
    price = new int[n] {};
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++)
    {

        if (!biheap.empty())
        {
            int minp = biheap.top();
            if (price[i] > minp)
            {
                biheap.pop();
                biheap.push(price[i]);
                ans += price[i] - minp;
            }
        }
        biheap.push(price[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << Bo(n) << endl;
    return 0;
}
#endif
#if 0
#include <iostream>

using namespace std;
template<class Type>
class priorityQueue
{
private:
    int currentSize;//队列长度
    Type *array;
    int maxSize;//容量

    void doubleSpace()//扩容
    {
        Type *tmp = array;
        array = new Type[maxSize *= 2];
        for(int i = 1; i <= currentSize; ++i)
            array[i] = tmp[i];
        delete [] tmp;
    }

    void percolateDown(int hole)//在左右子堆有序的前提下，对根结点向下过滤使堆有序化
    {
        int child;//左右子中较小者
        Type tmp = array[hole];

        while(hole * 2 <= currentSize)
        {
            child = hole * 2;
            if(child + 1 <= currentSize && array[child + 1] < array[child]) ++child;
            if(array[child] < tmp)
            {
                array[hole] = array[child];
                hole = child;
            }
            else break;
        }

        array[hole] = tmp;
    }

    void buildHeap()//从编号最大的非叶结点开始直至根结点，逐个调用precolateDown函数使每个子堆有序化，
                    //从而达到使整个堆有序化的目的
    {
        for(int i = currentSize / 2; i > 0; --i)
            percolateDown(i);
    }
public:
    priorityQueue(int capacity = 100):currentSize(0), maxSize(capacity + 10)
    {
        array = new Type[maxSize];
    }

    priorityQueue(const Type data[], int size):currentSize(size),  maxSize(size + 10)
    {
        array = new Type[maxSize];
        for(int i = 0; i < size; ++i)
            array[i + 1] = data[i];
        buildHeap();
    }

    ~priorityQueue()
    {
        delete [] array;
    }

    bool isEmpty() const
    {
        return (!currentSize);
    }

    Type getHead() const
    {
        return array[1];
    }

    void enQueue(const Type &x)
    {
        if(currentSize == maxSize - 1) doubleSpace();

        int hole = ++currentSize;
        while(hole > 1 && x < array[hole / 2])
        {
            array[hole] = array[hole / 2];
            hole /= 2;
        }
        array[hole] = x;
    }

    Type deQueue()
    {
        Type tmp = array[1];
        array[1] = array[currentSize--];
        percolateDown(1);
        return tmp;
    }
};

int main()
{
    int n;//#days
    int price;
    long long profit = 0;
    int tmp;//Store the top of heap
    cin >> n;

    priorityQueue<int> pq(n);
    for(int i = 1; i <= n; ++i)
    {
        cin >> price;
        pq.enQueue(price);
        tmp = pq.getHead();
        if(tmp < price)
        {
            profit += price - tmp;
            pq.deQueue();
            pq.enQueue(price);
        }
    }

    cout << profit;

    return 0;
}
#endif
#if 0
#include<bits/stdc++.h>
using namespace std; 

void print_vector(vector<int>&a){
    cout<<a.size()<<endl<<"(";
    for(int i=0;i<int(a.size());i++){
        cout<<a[i]<<" , ";
    }
    cout<<")"<<endl;
}

int main(){
    int n;
    cin>>n;
    long long profit=0;
    // int* arr=new int[n];
    vector<int> min_heap;
    make_heap(min_heap.begin(),min_heap.end(),greater<int>());
    int q,temp;

    for(int i=0;i<n;i++){
        cin>>temp;

        min_heap.push_back(temp);
        push_heap(min_heap.begin(),min_heap.end(),greater<int>());
        q=min_heap[0];
        if(temp>q){
            profit+=(long long)(temp)-q;
            pop_heap(min_heap.begin(),min_heap.end(),greater<int>());
            min_heap.pop_back();

            min_heap.push_back(temp);
            push_heap(min_heap.begin(),min_heap.end(),greater<int>());
        }
        // print_vector(min_heap);
    }
    cout<<profit;





    return 0;
}
#endif