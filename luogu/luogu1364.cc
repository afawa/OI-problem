#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int n;
struct node{
    int val,left,right;
};
node T[105];
int sum[105];
bool checkRoot[105];
int root;
void getSum(int now){
    if(now == 0)
        return;
    sum[now]+=T[now].val;
    getSum(T[now].left);
    getSum(T[now].right);
    sum[now] += sum[T[now].left] + sum[T[now].right];
}
int dp[105];
int getRootVal(int now){
    if(now==0){
        return 0;
    }
    int ans=0;
    ans += getRootVal(T[now].left) + getRootVal(T[now].right) + sum[T[now].right] + sum[T[now].left];
    return ans;
}
void dfs(int now){
    if(T[now].left){
        dp[T[now].left] = dp[now] - sum[T[now].left] + sum[root] - sum[T[now].left];
        dfs(T[now].left);
    }
    if(T[now].right){
        dp[T[now].right] = dp[now] - sum[T[now].right] + sum[root] - sum[T[now].right];
        dfs(T[now].right);
    }
}
int main(){
    scanf("%d",&n);
    memset(checkRoot,0,sizeof(checkRoot));
    for(int i=1;i<=n;++i){
        scanf("%d%d%d",&T[i].val,&T[i].left,&T[i].right);
        checkRoot[T[i].left]=1;
        checkRoot[T[i].right]=1;
    }
    for(int i=1;i<=n;++i){
        if(checkRoot[i]==0){
            root = i;
            break;
        }
    }
    memset(sum,0,sizeof(sum));
    getSum(root);
    dp[root] = getRootVal(root);
    dfs(root);
    int ans = dp[root];
    for(int i=1;i<=n;++i){
        ans = min(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}