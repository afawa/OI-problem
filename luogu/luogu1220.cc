#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n,c;
int pos[55];
int W[55];
int leftW[55][55];
int dp[55][55][2];
int main(){
    scanf("%d%d",&n,&c);
    int sum=0;
    for(int i=1;i<=n;++i){
        scanf("%d",pos+i);
        scanf("%d",W+i);
        sum+=W[i];
    }
    memset(dp,-1,sizeof(dp));
    leftW[c][c] = sum-W[c];
    dp[c][c][1] = dp[c][c][0] = 0;
    for(int len=2;len<=n;++len){
        for(int i = max(1,c-len+1);i<=min(c,n-len+1);++i){
            
        }
    }
    return 0;
}