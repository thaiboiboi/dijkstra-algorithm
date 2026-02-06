#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define maxN 1000
#define inf 1e9

int c[maxN][maxN]; //ma trận kề
int d[maxN],parent[maxN];
bool mark[maxN];
int n,m,u,v,w,s,f;

int getmin(){
    int minD=inf, u=0;
    for(int i=1;i<=n;i++)
        if (!mark[i]&&minD>d[i]){
            minD=d[i];
            u=i;
        }
    return u;
}

void dijkstra(int s,int f){
    //khởi tạo
    for(int i=1; i<=n; i++){
        d[i]=inf; mark[i]=false;
    }
    //thuật toán dijkstra
    d[s]=0; //bắt đầu từ đỉnh nguồn s
    while(true){
        int u=getmin(); //chọn đỉnh u có d[u] nhỏ nhất
        if (u==0||u==f) break; //thoát nếu không chọn được u hoặc gặp đỉnh f
        mark[u]=true; //đánh dấu u đã xử lý
        for(int v=1; v<=n; v++)
            if(!mark[v] && d[v]>d[u]+c[u][v]){
                d[v]=d[u]+c[u][v];
                parent[v]=u;
            }
    }
}

void path(int s, int f){
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
	//Khởi tạo đồ thị ban đầu
	for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if (i==j) c[i][j]=0;
            else c[i][j]=inf;

	for(int i=1;i<=m;i++){ //duyet qua m canh
        scanf("%d %d %d",&u,&v,&w);
        c[u][v]=w;
	}

    dijkstra(s,f);
    path(s,f);
	return 0;
}
