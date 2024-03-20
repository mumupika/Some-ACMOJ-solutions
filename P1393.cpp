#if 0
#include<iostream>
/**
 * 1.创建对应列表长度并且读入数值。
 * 2.将链表反转。
 * 3.带余数加法，新的链表是最长长度+1.
 * 4.再将链表反转并且输出。
*/
using namespace std;
struct Node
{
    int number;
    Node *next;
};
class LinkedList
{
    int size;
    Node *head;
    public:
    LinkedList(int i);
    LinkedList(int i,int j);
    LinkedList(const LinkedList &l);
    void display() const;
    void reverse();
    ~LinkedList();
    friend LinkedList Addition(LinkedList&, LinkedList&);
};
LinkedList::LinkedList(int k)
{
    head=new Node;
    int temp;
    cin >> temp;
    head->number=temp;
    size=1;
    Node *read,*pre=head;
    for(int i=2;i<=k;i++)
    {
        read=new Node;
        pre->next=read;
        cin >> temp;
        read->number=temp;
        pre=pre->next;
        size++;
    }
    pre->next=nullptr;
}
LinkedList::LinkedList(int k,int j)
{
    head=new Node;
    head->number=0;
    size=1;
    Node *read,*pre=head;
    for(int i=2;i<=k;i++)
    {
        read=new Node;
        pre->next=read;
        read->number=0;
        pre=pre->next;
        size++;
    }
    pre->next=nullptr;
}
LinkedList::LinkedList(const LinkedList &l)
{
    size=l.size;
    Node *read_this,*read_l=l.head,*read_pre=head;
    read_pre=new Node;
    read_pre->number=read_l->number;
    read_l=read_l->next;
    for(int i=2;i<=size;i++)
    {
        read_this=new Node;
        read_this->number=read_l->number;
        read_pre->next=read_this;
        read_pre=read_pre->next;
        read_l=read_l->next;
    }
    read_pre->next=nullptr;
}
void LinkedList::display() const
{
    Node *read=head;
    bool flag=false;
    if(size==0) return;
    while(read)
    {
        if(read->number==0 && flag==false)
        {
            read=read->next;
            continue;
        }
        flag=true;
        cout << read->number << ' ';
        read=read->next;
    }
    cout << endl;
    read=nullptr;
}
void LinkedList::reverse()
{
    Node *pre=nullptr,*now=head,*after=head->next;
    while(now)
    {
        now->next=pre;
        pre=now;
        now=after;
        if(after)
            after=after->next;
    }
    head=pre;
}
LinkedList Addition(LinkedList &l1,LinkedList &l2)
{
    int max=(l1.size>l2.size)?l1.size+1:l2.size+1;
    l1.reverse();
    l2.reverse();
    LinkedList sum(max,1);//重载函数来初始化为0.
    Node *read_l1=l1.head,*read_l2=l2.head,*input=sum.head;
    int carry=0,val1,val2;
    while(read_l1 || read_l2)
    {
        if(!read_l1) val1=0;
        else 
        {
            val1=read_l1->number;
            read_l1=read_l1->next;
        }
        if(!read_l2) val2=0;
        else
        {
            val2=read_l2->number;
            read_l2=read_l2->next;
        }
        input->number=(carry+val1+val2)%10;
        input=input->next;
        carry=(carry+val1+val2)/10;
    }
    if(carry != 0) input->number=carry;
    sum.reverse();
    return sum;
}
LinkedList::~LinkedList()
{
    Node *read,*pre;
    read=head->next;
    pre=head;
    while(read)
    {
        delete pre;
        pre=read;
        read=read->next;
    }
    delete pre;
    pre=read=nullptr;
}
int main()
{
    int a,b;
    cin >> a >> b;
    LinkedList l1(a),l2(b);
    LinkedList l3=Addition(l1,l2);
    l3.display();
    return 0;
}
#endif