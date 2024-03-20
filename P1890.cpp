#if 0
#include<iostream>
using namespace std;
//2.0:由于映射没有弄明白，所以增加了映射功能。映射回原来的下标。
//pikapika很讨厌二分，分治算法，因为经常会因为越界，和python等上取整下取整搞混，然后发生各种越界的问题
//大家一定要仔细写题，不要向pikapika一样粗心大意。。。。。。
//pikapika很菜哈哈哈哈——————某朋友的注释
#define nums 100005
int a[nums];
int b[nums];
int Index[nums];
int temp[nums];
int tempindex[nums];
void mergesort(int a[],int b[],int start,int mid,int end)
{
    int i=start,j=mid+1;
    int k=start;
    while(i<=mid && j<=end)
    {
        if(a[i]<=a[j])
        {
            //dealing...
            temp[k]=a[i];
            tempindex[k]=Index[i];
            b[Index[i]]+=(j-mid-1);//映射回原来的地方。
            k++;
            i++;

        }
        else
        {
            //dealing...
            temp[k]=a[j];
            tempindex[k]=Index[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        temp[k]=a[i];
        tempindex[k]=Index[i];
        b[Index[i]]+=(j-mid-1);
        i++;
        k++;
    }
    while(j<=end)
    {
        temp[k]=a[j];
        tempindex[k++]=Index[j++];
    }
    for(int q=start;q<=end;q++)
    {
        Index[q]=tempindex[q];
        a[q]=temp[q];
    }
}

void merge(int a[],int b[],int start,int end)
{
    if(start==end)
        return;
    int middle=(start+end)>>1;
    merge(a,b,start,middle);
    merge(a,b,middle+1,end);
    mergesort(a,b,start,middle,end);
}


int main()
{
    int num;
    scanf("%d",&num);
    int a[num];
    int b[num];
    for(int i=0;i<num;i++)
    {
        scanf("%d",&a[i]);
        b[i]=0;
        Index[i]=i;
        temp[i]=0;
        tempindex[i]=0;
    }
    merge(a,b,0,num-1);
    for(int i=0;i<num;i++)
        printf("%d ",b[i]);
    return 0;
}
#endif