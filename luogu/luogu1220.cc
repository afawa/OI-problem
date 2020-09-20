#include <bits/stdc++.h>
using namespace std;
int n,c;
int pos[55];
int W[55];
int leftW[55][55];
int dp[55][55][2];
void update(int a,int b,int c,int val){
    if(dp[a][b][c]==-1){
        dp[a][b][c] = val;
    }else{
        dp[a][b][c] = min(dp[a][b][c],val);
    }
}
int main(){
    scanf("%d%d",&n,&c);
    int sum=0;
    for(int i=1;i<=n;++i){
        scanf("%d",pos+i);
        scanf("%d",W+i);
        sum+=W[i];
    }
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            int tmp = 0;
            for(int k=i;k<=j;++k){
                tmp+=W[k];
            }
            leftW[i][j] = sum-tmp;
        }
    }
    dp[c][c][1] = dp[c][c][0] = 0;
    for(int len=2;len<=n;++len){
        for(int i = max(1,c-len+1);i<=min(c,n-len+1);++i){
            if(dp[i+1][i+len-1][0]!=-1){
                update(i,i+len-1,0,dp[i+1][i+len-1][0] + leftW[i+1][i+len-1] * (pos[i+1]-pos[i]));
            }
            if(dp[i+1][i+len-1][1]!=-1){
                update(i,i+len-1,0,dp[i+1][i+len-1][1] + leftW[i+1][i+len-1] * (pos[i+len-1]-pos[i]));
            }
            if(dp[i][i+len-2][0]!=-1){
                update(i,i+len-1,1,dp[i][i+len-2][0] + leftW[i][i+len-2] * (pos[i+len-1]-pos[i]));
            }
            if(dp[i][i+len-2][1]!=-1){
                update(i,i+len-1,1,dp[i][i+len-2][1] + leftW[i][i+len-2] * (pos[i+len-1]-pos[i+len-2]));
            }
        }
    }
    int ans;
    if(dp[1][n][0]==-1){
        ans = dp[1][n][1];
    }else if(dp[1][n][1]==-1){
        ans = dp[1][n][0];
    }else{
        ans = min(dp[1][n][0],dp[1][n][1]);
    }
    printf("%d\n",ans);
    return 0;
}