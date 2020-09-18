#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n;
struct card{
    int up,low;
};
card p[1005];
int dp[1005][10005];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&p[i].up,&p[i].low);
    }
    memset(dp,-1,sizeof(dp));
    dp[0][5000 + (p[0].up - p[0].low)] = 0;
    dp[0][5000 + (p[0].low - p[0].up)] = 1;
    for(int i=1;i<n;++i){
        int val = p[i].up - p[i].low;
        for(int j=0;j<=10000;++j){
            if(dp[i-1][j]!=-1){
                if(dp[i][j+val]==-1){
                    dp[i][j+val] = dp[i-1][j];
                }else{
                    dp[i][j+val] = min(dp[i][j+val],dp[i-1][j]);
                }
                if(dp[i][j-val]==-1){
                    dp[i][j-val] = dp[i-1][j] + 1;
                }else{
                    dp[i][j-val] = min(dp[i][j-val],dp[i-1][j]+1);
                }
            }
        }
    }
    int ans;
    for(int i=0;i<=5000;++i){
        if(dp[n-1][5000+i]!=-1 || dp[n-1][5000-i]!=-1){
            if(dp[n-1][5000+i] == -1){
                ans = dp[n-1][5000-i];
            }else if(dp[n-1][5000-i]==-1){
                ans = dp[n-1][5000+i];
            }else{
                ans = min(dp[n-1][5000-i],dp[n-1][5000+i]);
            }
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}