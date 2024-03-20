#if 0
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int num;
    scanf("%d",&num);
    int a[num];
    for(int i=0;i<num;i++)
        scanf("%d",&a[i]);
    sort(a,a+num);//排序
    int j,k;
    int res=0;
    //采用a+b=-c的方法进行夹逼。所以用扫描+夹逼法。
    for(int i=0;i<num-2;i++)
    {
        j=i+1,k=num-1;
        if(i>0 && a[i]==a[i-1]) continue;//重复情况，不重复计量。
        while(j<k)
        {
            if(a[j]+a[k]<0-a[i])
                j++;//数值小，左指针右移。
            else if(a[j]+a[k]>0-a[i])
                k--;//数值大，右指针左移。
            else
            {
                res++;
                j++;
				k--;//正确，两指针共同移动+1.
				while(a[j]==a[j-1] && a[k]==a[k+1] && j<k) 
                {
                    j++;
                    k--;
                }//重复
            }
        }
    }
    printf("%d\n",res);
    return 0;
}
#endif