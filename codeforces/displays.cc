#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int s[3005],c[3005];
int dp[3005][4];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",s+i);
    }
    
    for(int i=0;i<n;++i){
        scanf("%d",c+i);
    }
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;++i){
        dp[i][1] = c[i];
    }
    for(int len=2;len<=3;++len){
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(s[i]<s[j] && dp[i][len-1]!=-1){
                    if(dp[j][len]==-1){
                        dp[j][len] = dp[i][len-1] + c[j];
                    }else{
                        dp[j][len] = min(dp[j][len],dp[i][len-1]+c[j]);
                    }
                }
            }
        }
    }
    int ans=-1;
    for(int i=0;i<n;++i){
        if(dp[i][3]==-1)
            continue;
        if(ans==-1){
            ans = dp[i][3];
        }else{
            ans = min(ans,dp[i][3]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
