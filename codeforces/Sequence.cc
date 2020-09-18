#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int a[100006];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",a+i);
    }
    sort(a,a+n);
    int low = floor(pow(a[n-1],(double)1/(n-1)));
    int upper = ceil(pow(a[n-1],(double)1/(n-1)));
    double low_cost=0;
    //printf("%d %d\n",low,upper);
    for(int i=0;i<n;++i){
        low_cost += abs((double)a[i]-pow(low,i));
    }
    double up_cost = 0;
    for(int i=0;i<n;++i){
        //printf("%d %lld %lld\n",a[i],(long long)pow(upper,i),abs((long long)a[i]-(long long)pow(upper,i)));
        up_cost+=abs((double)a[i]-pow(upper,i));
    }
    long long ans = (long long)min(up_cost,low_cost);
    printf("%lld\n",ans);
    return 0;
}