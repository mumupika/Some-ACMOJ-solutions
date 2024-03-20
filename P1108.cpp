#if 0
#include <iostream>
//dfs算法实现
using namespace std;
string f1(string a,string b)
{
    int len=b.size();
    string res;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<a.size();j++)
        {           
            if(b[i]==a[j])
            {
                res+=a[j];
                break;
            }
        }
    }
    return res;
}

void f2(string mid,string c,string &res)
{
    if(mid.size()==0||c.size()==0)  return;
    res+=c[0];//层次遍历经过筛选后得到的第一个字符即为其根，列入前序遍历结果中。。
    char t=c[0];
    int i=0;
    for(;i<mid.size();i++)
    {
        if(mid[i]==t)break;
    }
    string l,r,lm,rm;
    for(int j=0;j<i;j++)
    {
        lm+=mid[j];//分割左子树。
    }
    for(int j=i+1;j<mid.size();j++)
    {
        rm+=mid[j];//分割右子树。
    }
    l= f1(lm,c);//从层次遍历中筛选出左子树层次遍历序列。
    r= f1(rm,c);//从层次遍历中筛选出右子树层次遍历序列。
    f2(lm,l,res);
    f2(rm,r,res);//递归，进入新的一轮。
}

int main() 
{
    string mid;
    string ceng;
    string res;
    cin>>mid>>ceng;
    f2(mid,ceng,res);
    cout<<res;
    return 0;
}
#endif