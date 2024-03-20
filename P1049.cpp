#if 0
/*
    老子不想写树，太大了，又多，又难写，还要输出NULL，真讨厌啊。。。
    北京时间：2023.3.16 AM 01:51
*/
#include <iostream>
#include <cstring>
using namespace std;
char pre[100],in[100],res[2000];
int maxn;
void dfs(int preStart,int preEnd,int inStart,int inEnd,int p)
{
    int root,leftlen,rightlen;
    for (root=inStart;root<inEnd;++root){
        if (in[root]==pre[preStart])
            break;
    }
    res[p]=in[root];
    if (p>maxn) maxn=p;
    leftlen=root-inStart;
    if (leftlen>0) dfs(preStart+1,preStart+leftlen,inStart,root,p*2);
    rightlen=inEnd-root-1;
    if (rightlen>0) dfs(preStart+leftlen+1,preEnd,root+1,inEnd,p*2+1);
    //本质上和课本上思路是一样的。
}
int main() {
    cin>>pre;
    cin>>in;
    dfs(0,strlen(pre),0,strlen(in),1);
    //妈的老子不想写二叉树了写个深搜吧都他妈比二叉树简单
    //树那么难写谁爱写谁写去吧tmd
    for (int i=1;i<=maxn;++i)
        if (res[i]) 
            cout<<res[i]<<" ";
        else 
            cout<<"NULL ";
    return 0;
}
#endif
