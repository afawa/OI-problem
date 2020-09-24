#include <bits/stdc++.h>
using namespace std;
int n,maxx;
long long c[20005],cnt[20005];
struct cow{
    int v,x;
    bool operator< (const cow & a) const{
        return v<a.v;
    }
};
cow cows[20005];
void modify(int pos,int val,long long * c){
    while(pos <= maxx){
        c[pos] += val;
        pos += pos&(-pos);
    }
}
long long sum(int pos,long long *c){
    long long ans=0;
    while(pos > 0){
        ans += c[pos];
        pos -= pos&(-pos);
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    maxx = 0;
    memset(c,0,sizeof(c));
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;++i){
        scanf("%d%d",&cows[i].v,&cows[i].x);
        maxx = max(maxx,cows[i].x);
    }
    sort(cows+1,cows+n+1);
    long long ans=0;
    for(int i=1;i<=n;++i){
        long long low = sum(cows[i].x-1,c);
        long long lowCnt = sum(cows[i].x-1,cnt);
        long long up = sum(maxx,c) - sum(cows[i].x,c);
        long long upCnt = sum(maxx,cnt) - sum(cows[i].x,cnt);
        ans += cows[i].v * ((cows[i].x * lowCnt - low) + (up - cows[i].x * upCnt));
        modify(cows[i].x,1,cnt);
        modify(cows[i].x,cows[i].x,c);
    }
    printf("%lld\n",ans);
    return 0;
}