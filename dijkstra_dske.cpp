#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define maxN 10001
#define inf 1e9

typedef pair<int,int> ii;
typedef vector<ii> vii;
vii adj[maxN];
bool mark[maxN];
int d[maxN],parent[maxN];
int n,m,u,v,w,s,f;

void dijkstra(int s,int f){
    for(int i=1; i<=n; i++){
        d[i]=inf; mark[u]=false;
    }
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    d4
    pq.push(ii(0,s));
    while(!pq.empty()){
        int u=pq.top().second; //lấy đỉnh u có d[u] nhỏ nhất
        pq.pop();
        if (mark[u]) continue; //bỏ qua đỉnh u đã xử lý
		if (u==f) break; //thoát nếu gặp đỉnh f
		mark[u]=true; //đánh dấu u đã xử lý

        for(int i=0; i<(int)adj[u].size(); i++){
            int v=adj[u][i].first;
			int w=adj[u][i].second;
            if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                parent[v]=u;
                pq.push(ii(d[v],v));
            }
        }

    }
}

void path(int s,int f){
    if (d[f]==inf)
        printf("There is no path from %d to %d",s,f);
    else{
        printf("Distance from %d to %d:%d\n",s,f,d[f]);
        while(f!=s){
            printf("%d <- ",f);
            f=parent[f];
        } 
        printf("%d",s);
    }
}

int main(){
	freopen("minpath.inp","r",stdin);
	freopen("minpath.out","w",stdout);
	scanf("%d %d %d %d",&n,&m,&s,&f);
	for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back(ii(v,w));
	}

    dijkstra(s,f);
    path(s,f);
	return 0;
}
