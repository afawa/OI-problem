#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

long long n;
int s;
int getSum(long long n){
    int ans=0;
    while(n!=0){
        ans+=n%10;
        n/=10;
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%d",&n,&s);
        int level=0,tmp = getSum(n);
        long long ans=0;
        while(tmp>s){
            int digit = (n / (long long)pow(10,level)) % 10;
            n+=(10-digit) * (long long)pow(10,level);
            ans += (10-digit) * (long long)pow(10,level);
            tmp = getSum(n);
            level++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}