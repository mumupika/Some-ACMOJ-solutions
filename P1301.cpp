#if 0
#include<iostream>
//Reference:https://www.cnblogs.com/Tianwell/p/11490987.html
//https://blog.csdn.net/vinceee__/article/details/89893578
//跑出元素的逆序对，并从前往后将逆序对的较小数寻找出来并且再加上逆序情况。
//看的不太明白，但是目前应该能用模版蒙混过关
using namespace std;
int *temp;
void ADD(int a,int b,int n)
{
    while(a<=n)
    {
        temp[a]+=b;
        a+=a&-a;
    }
}
int solve(int a)
{
    int sum=0;
    while(a)
    {
        sum+=temp[a];
        a-=a&-a;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int *input,*res;
    input=new int [n+1];
    res=new int [n+1];
    temp=new int [n+1];
    for(int i=1;i<=n;i++)
        cin >> input[i];
    
    //求取每个数的逆序对
    for(int i=n;i>0;i--)
    {
        ADD(input[i]+1,1,n);
        res[input[i]]=solve(input[i]);
    }

    for(int i=0;i<=n;i++)
        temp[i]=0;
    //将”成为逆序对的数加上因逆序而需要交换的次数

    for(int i=1;i<=n;i++)
    {
        ADD(1,1,n);
        ADD(input[i],-1,n);
        res[input[i]]+=solve(input[i]);
    }

    for(int i=1;i<=n;i++)
        cout << res[i] << ' ';
    return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
void count_cross(int *a,int L,int mid,int R,int *res)
{
    int i=L,j=mid+1,k=0;
    int *temp=new int [R-L+1];
    while(i<=mid && j<=R)
    {
        if(a[i]>=a[j])
        {
            temp[k++]=a[j];
            res[a[j]]+=mid-i+1;
            j++;
        }
        else
        {
            temp[k++]=a[i];
            res[a[i]]+=j-mid-1;
            i++;
        }
    }
    while(i<=mid)
    {
        temp[k++]=a[i];
        res[a[i]]+=j-mid-1;
        i++;
    }
    while(j<=R)
        temp[k++]=a[j++];
    for(int i=L;i<=R;i++)
        a[i]=temp[i-L];
}
void count_in(int *a,int L,int R,int* res)
{
    int mid=(L+R)/2;
    if(L<R)
    {
        count_in(a,L,mid,res);
        count_in(a,mid+1,R,res);
        count_cross(a,L,mid,R,res);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int num,*a,*res;
    cin >> num;
    a=new int[num];
    res=new int[num];
    for(int i=0;i<num;i++)
        cin >> a[i];
    count_in(a,0,num-1,res);
    for(int i=1;i<=num;i++)
        cout << res[i] << ' ';
    delete []a;
    delete []res;
    return 0;
}
#endif