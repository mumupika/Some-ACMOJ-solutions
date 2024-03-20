#if 0
#include<iostream>
using namespace std;
class Queue
{
    int queueSize;//the size of the queue;
    int arrayLength;//the length of the array;
    int base;//base number of the queue.
    int head;
    int rear;//the head and the rear of the queue;
    int *queue;
    public:
        Queue(int initialSpace)
        {
            head=rear=0;
            queue=new int[initialSpace];
            arrayLength=initialSpace;
            queueSize=base=0;
        }
        ~Queue()
        {
            delete[] queue;
        }
        void doublespace()
        {
            int* newQueue=new int[2*arrayLength];

            int start=(head+1)%arrayLength;
            if(start<2)
                copy(queue+start,queue+start+arrayLength-1,newQueue);
            else
            {
                copy(queue+start,queue+arrayLength,newQueue);
                copy(queue,queue+rear+1,newQueue+arrayLength-start);
            }
            //循环队列分开进行复制：先复制（1）从head的下一位到queue尾部，（2）再从queue头部到rear，复制到newqueue的长度-start处开始。
            head=2*arrayLength-1;
            rear=arrayLength-2;
            arrayLength*=2;
            delete[] queue;
            queue=newQueue;
        }
        void enQueue()
        {
            if((rear+1)%arrayLength==head)
            {
                doublespace();
            }
            rear=(rear+1)%arrayLength;
            queue[rear]=++base;
            cout << queue[rear] << ' ' << ++queueSize << endl;
        }
        void deQueue()
        {
            if(rear==head)
            {
                cout << queue[head] << ' ' << 0 << endl;
                return;
            }
            head=(head+1)%arrayLength;
            cout << queue[head] << ' ' << --queueSize << endl;
        }
};
int main()
{
    int size,number;
    cin >> size >> number;
    Queue q(size);
    for(int i=0;i<number;i++)
    {
        int op;
        cin >> op;
        switch(op)
        {
            case 0:
                int temp;
                cin >> temp;
                q.enQueue();
                break;
            case 1:
                q.deQueue();
                break;
        }
    }
    return 0;
}
#endif