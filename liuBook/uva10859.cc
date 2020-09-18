#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int n,m;
int map[1005][1005];
int visited[1005];
struct node{
    int l,e;
    bool operator<(const node & a) const{
        if(l==a.l)
            return e>a.e;
        return l<a.l;
    }
};
node T[1005][2];
void dfs(int now,int fa){
    visited[now]=1;
    for(int i=0;i<n;++i){
        if(i == fa)
            continue;
        if(map[now][i]==1){
            dfs(i,now);
        }
    }
    int l=0,e=0;
    for(int i=0;i<n;++i){
        if(i == fa)
            continue;
        if(map[now][i]==1){
            l+=T[i][1].l;
            e+=T[i][1].e;
        }
    }
    T[now][0].l = l;T[now][0].e=e;
    l=0,e=0;
    for(int i=0;i<n;++i){
        if(i == fa)
            continue;
        if(map[now][i]==1){
            if(T[i][0] < T[i][1]){
                l += T[i][0].l;
                e += T[i][0].e;
            }else{
                l += T[i][1].l;
                e += T[i][1].e;
                e += 1;
            }
        }
    }
    l+=1;
    T[now][1].l=l;T[now][1].e=e;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(map,0,sizeof(map));
        memset(visited,0,sizeof(visited));
        scanf("%d%d",&n,&m);
        int a,b;
        for(int i=0;i<m;++i){
            scanf("%d%d",&a,&b);
            map[a][b] = map[b][a] = 1;
        }
        int lans=0,eans=0;
        for(int i=0;i<n;++i){
            if(!visited[i]){
                dfs(i,i);
                node tmp = min(T[i][0],T[i][1]);
                lans += tmp.l;
                eans += tmp.e;
            }
        }
        printf("%d %d %d\n",lans,eans,m-eans);
    }
    return 0;
}