#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
int n,f;
int r[10005];
bool check(double mid){
    int cnt=0;
    for(int i=0;i<n;++i){
        double tmp = M_PI * r[i] * r[i];
        cnt += floor(tmp / mid);
        if(cnt >= f+1)
            return true;
    }
    return false;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&f);
        int maxr = 0;
        for(int i=0;i<n;++i){
            scanf("%d",r+i);
            maxr = max(maxr,r[i]);
        }
        double left = 0,right = M_PI * maxr * maxr;
        while(1){
            if(fabs(left-right) < 1e-4)
                break;
            double mid = (left+right)/2;
            if(check(mid)){
                left = mid;
            }else{
                right = mid;
            }
        }
        printf("%.4lf\n",left);
    }
    return 0;
}