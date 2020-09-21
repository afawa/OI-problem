#include <bits/stdc++.h>
using namespace std;
int n,p[20005],c[100005],maxi=0,low[20005],low1[20005];
void modify(int x,int val){
    while(x<=maxi){
        c[x] += val;
        x += x&(-x);
    }
}
int sum(int x){
    int ans=0;
    while(x>0){
        ans+=c[x];
        x -= x&(-x);
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        maxi = 0;
        for(int i=1;i<=n;++i){
            scanf("%d",p+i);
            maxi = max(maxi,p[i]);
        }
        memset(c,0,sizeof(c));
        memset(low,0,sizeof(low));
        memset(low1,0,sizeof(low1));
        for(int i=1;i<=n;++i){
            low[i] = sum(p[i]-1);
            modify(p[i],1);
        }
        memset(c,0,sizeof(c));
        for(int i=n;i>0;--i){
            low1[i] = sum(p[i]-1);
            modify(p[i],1);
        }
        long long ans=0;
        for(int i=1;i<=n;++i){
            ans += low[i] * (n-i-low1[i]) + (i-1-low[i]) * low1[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}