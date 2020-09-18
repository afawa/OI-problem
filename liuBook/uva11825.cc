#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n,m;
int P[20];
int cover[1<<16+5];
int f[1<<16+5];
int main(){
    int cnt=0;
    while(~scanf("%d",&n) && n){
        for(int i=0;i<n;++i){
            scanf("%d",&m);
            P[i] = (1<<i);
            int a;
            while(m--){
                scanf("%d",&a);
                P[i] |= (1<<a);
            }
        }
        for(int S=0 ;S<(1<<n);++S){
            cover[S] = 0;
            for(int i=0;i<n;++i){
                if(S & (1<<i)){
                    cover[S] |= P[i];
                }
            }
        }
        f[0]=0;
        for(int S=1;S<(1<<n);++S){
            f[S]=0;
            for(int S0=S;S0;S0 = (S0-1)&S){
                if(cover[S0]==((1<<n)-1))
                    f[S] = max(f[S],f[S^S0]+1);
            }
        }
        printf("Case %d: %d\n",++cnt,f[(1<<n)-1]);
    }
    return 0;
}