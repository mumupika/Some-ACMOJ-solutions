#if 0
#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int x,y;
};
int n,m,m1,m2,mp[32][32],step[32][32];
bool vis[32][32];
int main()
{
	scanf("%d%d%d%d",&n,&m,&m1,&m2);
	int fx[]={m1,m1,m2,m2,-m1,-m1,-m2,-m2};
    int fy[]={m2,-m2,m1,-m1,m2,-m2,m1,-m1};
	for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) 
            scanf("%d",&mp[i][j]);
	for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) 
            if(mp[i][j]==3)
            {
		        queue<node>q;
		        q.push((node){i,j});
		        step[i][j]=0;
		        while(!q.empty())
                {
			        int x=q.front().x;
                    int y=q.front().y;
			        vis[x][y]=1;
			        for(int ii=0;ii<8;ii++)
                    {
				        int xx=x+fx[ii],yy=y+fy[ii];
				        if(xx<1||yy<1||xx>n||yy>m) 
                            continue;
				        if(mp[xx][yy]==4)
                        {
					        printf("%d",step[x][y]+1);
					        return 0;
				        }
				        if(mp[xx][yy]!=1||vis[xx][yy]) continue;
				        vis[xx][yy]=1;
				        q.push((node){xx,yy});
				        step[xx][yy]=step[x][y]+1;
			        }
			        q.pop();
		        }
	        }
}
#endif