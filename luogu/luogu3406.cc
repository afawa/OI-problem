#include <bits/stdc++.h>
using namespace std;
int n,m;
int pre[100005];
int path[100005];
int A[100005],B[100005],C[100005];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d",path+i);
    }
    for(int i=1;i<=n-1;++i){
        scanf("%d%d%d",A+i,B+i,C+i);
    }
    memset(pre,0,sizeof(pre));
    for(int i=0;i<m-1;++i){
        int maxi = max(path[i],path[i+1]);
        int mini = min(path[i],path[i+1]);
        pre[mini] += 1;
        pre[maxi] -= 1;
    }
    for(int i=2;i<=n-1;++i){
        pre[i] += pre[i-1];
    }
    long long ans=0;
    for(int i=1;i<=n-1;++i){
        ans += min((long long)pre[i]*(long long)A[i],(long long)C[i]+(long long)pre[i]*(long long)B[i]);
    }
    printf("%lld\n",ans);
    return 0;
}