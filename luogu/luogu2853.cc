#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int k,n,m;
int sum[1005];
vector<int> vec[1005];
int pos[1005];
int visited[1005];
void dfs(int now){
    visited[now] = 1;
    sum[now]++;
    for(int i=0;i<vec[now].size();++i){
        if(!visited[vec[now][i]]){
            dfs(vec[now][i]);
        }
    }
}
int main(){
    scanf("%d%d%d",&k,&n,&m);
    for(int i=0;i<k;++i){
        scanf("%d",pos+i);
    }
    int a,b;
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        vec[a].push_back(b);
    }
    for(int i=0;i<k;++i){
        memset(visited,0,sizeof(visited));
        dfs(pos[i]);
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        //printf("%d ",sum[i]);
        if(sum[i] == k){
            ans++;
        }
    }
    //printf("\n");
    printf("%d\n",ans);
    return 0;
}