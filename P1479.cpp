#if 0
/**
 * 寻找最小重复字串：
 * KMP算法的next数组求解。next寻找的是最长公共前缀。例如：对于cabcabca,
 * c->0
 * ca->0
 * cab->0
 * (c)ab(c)->1
 * (ca)b(ca)->2
 * (cab)(cab)->3
 * [cab(c]abc)->4
 * [cab(ca]bca)->5
 * 利用双指针：当没有遇到相同字母时，让k回到上一个发现相同字母的地方，当k在-1或匹配时，记录数值并且向后推一位，就找到了最长公共前缀。
 * 那么最小重复字串就是字符串的长度减去最小公共前缀的长度了。
*/
#include<iostream>
using namespace std;
#define ll long long
const ll N=100000000;
int main()
{
    ll n;
    scanf("%lld",&n);
    char *s=new char[n+1];
    scanf("%s",s);
    ll *next=new ll[n+1];
    int k=-1,j=0;
    next[j]=k;
    while(s[j])
    {
        if(k==-1||s[k]==s[j])
        {
            k++;
            j++;
            next[j]=k;
        }
        else
            k=next[k];
    }
    printf("%lld",n-next[n]);
    delete []s;
    delete []next;
}
#endif