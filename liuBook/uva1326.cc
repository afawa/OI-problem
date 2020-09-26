#include <bits/stdc++.h>
using namespace std;
int n,A[30];
char str[1000];
map<int,int> mp;
int bitCount(int x){
    return x == 0 ? 0 : bitCount(x>>1) + (x & 1);
}
int main(){
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i){
            scanf("%s",str);
            A[i] = 0;
            for(int j=0;str[j];++j){
                A[i] ^= (1<<(str[j]-'A'));
            }
        }
        mp.clear();
        int n1 = n/2,n2 = n-n1;
        for(int i=0;i<(1<<n1);++i){
            int x = 0;
            for(int j=0;j<n1;++j){
                if(i&(1<<j))
                    x ^= A[j];
            }
            if(!mp.count(x) || bitCount(mp[x]) < bitCount(i))
                mp[x] = i;
        }
        int ans=0;
        for(int i=0;i<(1<<n2);++i){
            int x=0;
            for(int j=0;j<n2;++j){
                if(i & (1<<j))
                    x^=A[j+n1];
            }
            if(mp.count(x) && bitCount(ans)<bitCount(mp[x]) + bitCount(i)){
                ans = (i<<n1)^mp[x];
            }
        }
        printf("%d\n",bitCount(ans));
        for(int i=0;i<n;++i){
            if(ans & (1<<i))
                printf("%d ",i+1);
        }
        printf("\n");
    }
    return 0;
}