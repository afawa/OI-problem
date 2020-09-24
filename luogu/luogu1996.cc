#include <bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],tmp[100005];
struct item{
    int val,pos;
    bool operator < (const item & a) const{
        return val<a.val;
    }
};
item items[100005];
int c[100005];
void modify(int x,int val){
    while(x<=n){
        c[x] = (c[x] + val) % (int)(1e8-3);
        x+=x&(-x);
    }
}
int sum(int x){
    int ans=0;
    while(x>0){
        ans = (ans+c[x]) % (int)(1e8-3);
        x-=x&(-x);
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        tmp[i] = a[i];
    }
    for(int i=1;i<=n;++i){
        scanf("%d",b+i);
        items[i].val = b[i]; items[i].pos = i;
    }
    sort(tmp+1,tmp+n+1);
    sort(items+1,items+n+1);
    for(int i=1;i<=n;++i){
        b[i] = items[lower_bound(tmp,tmp+n,a[i]) - tmp].pos;
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        ans = (ans + (i - 1 - sum(b[i]-1))) % (int)(1e8-3);
        modify(b[i],1);
    }
    printf("%d\n",ans);
    return 0;
}