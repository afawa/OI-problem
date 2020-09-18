#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int n,m,k;
int p[5005];
long long dp[5005][5005];
long long sum[5005];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i){
        scanf("%d",p+i);
    }
    sum[m]=0;
    for(int i=1;i<=m;++i){
        sum[m]+=p[i];
    }
    for(int i=m+1;i<=n;++i){
        sum[i] = sum[i-1] + p[i] - p[i-m];
    }
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=n;++i){
        dp[0][i]=0;
    }
    for(int i=1;i<=k;++i){
        for(int pos = m*i;pos<=n;++pos){
            if(dp[i][pos-1]!=-1){
                dp[i][pos] = max(dp[i][pos],dp[i][pos-1]);
            }
            if(dp[i-1][pos-m]!=-1){
                dp[i][pos] = max(dp[i][pos],dp[i-1][pos-m]+sum[pos]);
            }
        }
    }
    long long ans=-1;
    for(int i=1;i<=n;++i){
        ans = max(ans,dp[k][i]);
    }
    printf("%lld\n",ans);
    return 0;
}