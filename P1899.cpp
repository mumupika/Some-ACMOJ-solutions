#if 0
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;
vector<bool> vis;
vector<vector<bool>> g;//邻接矩阵
vector<int> part;
vector<int> l;
vector<int> r;
vector<bool> ans;

bool hungarian(int i){
    for(int j=1;j<n+1;j++){
        if(g[i][j]&&!vis[j]){
            vis[j]=true;
            if(l[j]==0||hungarian(l[j])){
                l[j]=i;
                r[i]=j;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin>>n>>m;
    part.assign(n+1,0);
    l.assign(n+1,0);
    r.assign(n+1,0);
    ans.assign(n+1,false);
    g.assign(n+1,vector<bool>(n+1));
    int u, v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        g[u][v]=true;
        g[v][u]=true;
    }
    for(int i=1;i<n+1;i++){
        if(part[i]==0){
            queue<int> q;
            part[i]=1;//二分图左边的点
            q.push(i);
            while(!q.empty()){
                int cur=q.front();
                q.pop();
                for(int j=1;j<n+1;j++){
                    if(g[cur][j]){
                        if(part[j]==0){
                            part[j]=part[cur]*(-1);
                            q.push(j);
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<n+1;i++){
        //cout<<part[i]<<endl;
        if(part[i]!=1){
            continue;
        }
        vis.assign(n+1,false);
        if(!hungarian(i)){
            ans[i]=true;
        }
    }
    for(int i=1;i<n+1;i++){
        if(part[i]==1){
            ans[i]=true;
        }
    }
    for(int i=1;i<n+1;i++){
        //cout<< i<<"i "<<l[i]<<" "<<r[i]<<endl;
        if(part[i]==-1&&l[i]==0){
            vis.assign(n+1,false);
            vis[i]=true;
            queue<int> ql;
            queue<int> qr;
            qr.push(i);
            ans[i]=true;
            while(!qr.empty()){
                int vexr=qr.front();
                qr.pop();
                for(int j=1;j<n+1;j++){
                    if(g[vexr][j]&&!vis[j]){
                        ql.push(j);
                        ans[j]=false;
                    }
                }
                while(!ql.empty()){
                    int vexl=ql.front();
                    ql.pop();
                    if(r[vexl]!=0 && !vis[r[vexl]]){
                        qr.push(r[vexl]);
                        vis[r[vexl]]=true;
                        ans[r[vexl]]=true;
                    }
                }
            }
        }
    }
    int count=0;
    for(int i=1;i<n+1;i++){
        if(ans[i]){
            count++;
        }
    }
    cout<<count<<endl;
    for(int i=1;i<n+1;i++){
        if(ans[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}
#endif
