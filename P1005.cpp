#if 0
# include <iostream>
# include <stdio.h>
using namespace std;
struct node
{
    int element;
    node *next;
};
struct LinkList 
{
    int size;
    node *head;
  // TODO: Define some variables of struct LinkList here.
  void Initialize(int *a, int n) 
  {
    if(n<1) return;
    node *temp,*pre;
    pre=head=new node;
    head->element=a[0];
    size=1;
    for(int i=1;i<n;i++)
    {
        temp=new node;
        temp->element=a[i];
        size++;
        pre->next=temp;
        pre=pre->next;
    }
    pre->next=NULL;
    // TODO: use a[0 ... n-1] to initialize the link list.
  }
  void Insert(int i, int x) 
  {
    if(i<0 || i>size) return;
    node *read,*temp;
    read=head;
    temp=NULL;
    if(i==0)
    {
        temp=new node;
        temp->element=x;
        temp->next=head;
        head=temp;
        size++;
    }
    else
    {
        for(int j=1;j<i;j++)
            read=read->next;
        temp=new node;
        temp->element=x;
        temp->next=read->next;
        read->next=temp;
        size++;
    }
    // TODO: insert element x after i-th element.
  }
  void Delete(int i) 
  {
    if(i<1 || i>size) return;
    node *read,*pre;
    read=pre=head;
    if(i==1)
    {
        head=read->next;
        delete read;
        size--;
    }
    else
    {
        for(int j=1;j<i-1;j++)
        {
            read=read->next;
            pre=pre->next;
        }
        read=read->next;
        pre->next=read->next;
        delete read;
        size--;
        read=pre=NULL;
    }
    // TODO: delete element i
  }
  void EvenOddSwap() 
  {
    node *r1,*r2;
    int temp;
    r1=head;r2=head->next;
    if(size%2==0)
    {
        for(int i=1;i<=size/2;i++)
        {
            temp=r1->element;
            r1->element=r2->element;
            r2->element=temp;
            if(i<size/2)
            {
              r1=r1->next->next;
              r2=r2->next->next;
            }
        }
        r1=r2=NULL;
    }
    else
    {
        for(int i=1;i<=size/2;i++)
        {
            temp=r1->element;
            r1->element=r2->element;
            r2->element=temp;
            if(i<size/2)
            {
              r1=r1->next->next;
              r2=r2->next->next;
            }
        }
        r1=r2=NULL;
    }
    // TODO: Swap the even-indexed element with the corresponding odd-indexed element.
  }
  void Query(int i) 
  {
    if(i<1 || i>size) return;
    node *read=head;
    for(int j=1;j<i;j++)
        read=read->next;
    cout << read->element << endl;
  }
  void QueryAll() 
  {
    node *read=head;
    while(read)
    {
        cout << read->element << ' ';
        read=read->next;
    }
    cout << '\n';
  }
  void ClearMemory() 
  {
    node *pre,*read;
    pre=head;read=head->next;
    while(pre->next)
    {
        delete pre;
        pre=read;
        read=read->next;
    }
    read=pre=NULL;
    // TODO: Clear the memory.
  }
};

LinkList L;

int main() {
    ios :: sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, *a;
  cin >> n;
  a = new int [n];
  for (int i = 0; i < n; ++ i) cin >> a[i];
  L.Initialize(a, n);
  delete [] a;

  int m, op, i, x;
  cin >> m;
  while(m --) {
    cin >> op;
    switch(op) {
      case 1: 
        cin >> i >> x;
        L.Insert(i, x);
          break;
      case 2:
        cin >> i;
        L.Delete(i);
        break;
      case 3:
        L.EvenOddSwap();
          break;
      case 4:
        cin >> i;
        L.Query(i);
        break;
      case 5:
        L.QueryAll();
        break;
    }
  }

  L.ClearMemory();
  return 0;
}
#endif