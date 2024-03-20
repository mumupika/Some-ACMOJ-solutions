#if 0
#include<iostream>
#include<deque>
#include<vector>
using namespace std;
const long long NMAX=1000005;
// C++ program to implement single source
// shortest path for a Binary Graph
using namespace std;
/* no.of vertices */
#define ll long long
// a structure to represent edges
struct node
{
    // two variable one denote the node
    // and other the weight
    ll to, weight;
};
 
 
// Prints shortest distance from given source to
// every other vertex
inline void zeroOneBFS(int src,vector<node> edges[],int m,int end)
{
    // Initialize distances from given source
    ll dist[m];
    for (ll i=0; i<m; i++)
        dist[i] = __LONG_LONG_MAX__;
 
    // double ende queue to do BFS.
    deque <ll> Q;
    dist[src] = 0;
    Q.push_back(src);
 
    while (!Q.empty())
    {
        ll v = Q.front();
        Q.pop_front();
 
        for (int i=0; i<edges[v].size(); i++)
        {
            // checking for the optimal distance
            if (dist[edges[v][i].to] > dist[v] + edges[v][i].weight)
            {
                dist[edges[v][i].to] = dist[v] + edges[v][i].weight;
 
                // Put 0 weight edges to front and 1 weight
                // edges to back so that vertices are processed
                // in increasing order of weights.
                if (edges[v][i].weight == 0)
                    Q.push_front(edges[v][i].to);
                else
                    Q.push_back(edges[v][i].to);
            }
        }
    }
 
    // printing the shortest distances
    printf("%lld",dist[end]);
}
 
inline void addEdge(int u, int v, int wt,vector<node>edges[])
{
    node temp1,temp2;
    temp1.to=v;temp1.weight=wt;
    edges[u].push_back(temp1);
    temp2.to=u;temp2.weight=wt;
    edges[v].push_back(temp2);
}
 
// Driver function
int main()
{
    ll n,m,s,t;
    scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
    // vector to store edges
    vector <node> edges[n+1]; 
    for(int i=1;i<=m;i++)
    {
        ll v1,v2,w;
        scanf("%lld%lld%lld",&v1,&v2,&w);
        addEdge(v1,v2,w,edges);
    }
    int src = s;//source node
    zeroOneBFS(src,edges,n+1,t);
    return 0;
}
#endif