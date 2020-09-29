#include <bits/stdc++.h>
using namespace std;
int n,k;
struct interval{
    int start,end;
    bool operator <(const interval &a) const{
        return start<a.start;
    }
};
interval T[100005];
int main(){
    int t,ca=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        int a,b;
        for(int i=0;i<n;++i){
            scanf("%d%d",&a,&b);
            T[i].start = a;
            T[i].end = b;
        }
        sort(T,T+n);
        int nowIn = 0,now = T[0].start;
        int ans=0;
        while(nowIn<n){
            //printf("%d %d %d\n",now,nowIn,ans);
            int add = (T[nowIn].end - now)/k;
            if((T[nowIn].end - now)%k)
                add++;
            ans += add;
            now += add * k;
            ++nowIn;
            for(;nowIn<n;++nowIn){
                if(T[nowIn].end>now){
                    now = max(now,T[nowIn].start);
                    break;
                }
            }
        }
        printf("Case #%d: %d\n",++ca,ans);
    }
    return 0;
}