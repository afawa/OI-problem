#include <bits/stdc++.h>
using namespace std;
int n,A[4005],B[4005],C[4005],D[4005];
unordered_map<int,int> mp;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d%d%d%d",A+i,B+i,C+i,D+i);
        }
        mp.clear();
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int x = A[i] + B[j];
                if(!mp.count(x))
                    mp[x] = 1;
                else
                    mp[x]++;
            }
        }
        long long ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int x = -(C[i] + D[j]);
                if(mp.count(x))
                    ans+=mp[x];
            }
        }
        printf("%lld\n",ans);
        if(t)
            puts("");
    }
    return 0;
}