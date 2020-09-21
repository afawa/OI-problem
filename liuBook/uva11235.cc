#include <bits/stdc++.h>
using namespace std;
int n,q;
int a[100005];
int maxFre[100005][30],leftMax[100005][30],rightMax[100005][30];
int query(int left,int right){
    int k=0;
    while((1<<(k+1) <= right-left+1))
        k++;
    int tmp = maxFre[left][k];
    int tmp1 = maxFre[right-(1<<k)+1][k];
    int ans = max(tmp,tmp1);
    int tmp2=0;
    if(a[left+(1<<k)-1] == a[right - (1<<k) +1]){
        tmp2 = leftMax[right-(1<<k)+1][k] + rightMax[left][k] - ((1<<(k+1))-(right - left +1));
    }
    return max(ans,tmp2);
}
int main(){
    while(~scanf("%d",&n) && n){
        scanf("%d",&q);
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
        }
        memset(maxFre,0,sizeof(maxFre));
        memset(leftMax,0,sizeof(leftMax));
        memset(rightMax,0,sizeof(rightMax));
        for(int i=0;i<n;++i){
            maxFre[i][0] = 1;
            leftMax[i][0] = 1;
            rightMax[i][0] = 1;
        }
        for(int j=1;(1<<j)<=n;++j){
            for(int i=0;i+(1<<j)-1<n;++i){
                if(leftMax[i][j-1] == maxFre[i][j-1] && a[i] == a[i+ (1<<(j-1))]){
                    leftMax[i][j] = leftMax[i][j-1] + leftMax[i+ (1<<(j-1))][j-1];
                }else{
                    leftMax[i][j] = leftMax[i][j-1];
                }
                if(rightMax[i + (1<<(j-1))][j-1] == maxFre[i + (1<<(j-1))][j-1] && a[i + (1<<j) -1] == a[i+(1<<(j-1))-1]){
                    rightMax[i][j] = rightMax[i + (1<<(j-1))][j-1] + rightMax[i][j-1];
                }else{
                    rightMax[i][j] = rightMax[i + (1<<(j-1))][j-1];
                }
                int tmp=0;
                if(a[i+(1<<(j-1))-1] == a[i+(1<<(j-1))]){
                    tmp = rightMax[i][j-1] + leftMax[i+(1<<(j-1))][j-1];
                }
                maxFre[i][j] = max(maxFre[i][j],max(tmp,max(maxFre[i][j-1],maxFre[i+(1<<(j-1))][j-1])));
            }
        }
        int left,right;
        for(int i=0;i<q;++i){
            scanf("%d%d",&left,&right);
            printf("%d\n",query(left-1,right-1));
        }
    }
    return 0;
}