#include <bits/stdc++.h>
using namespace std;
int n,s,t;
int a[100005];
double prefixSum[100005];
int q[100005];
bool check(double mid){
    prefixSum[0] = 0;
    for(int i=1;i<=n;++i){
        prefixSum[i] = prefixSum[i-1] + (double) a[i] - mid;
    }
    int head = 1, tail = 0;
    for(int i=s;i<=n;++i){
        while(head <= tail && prefixSum[q[tail]]>prefixSum[i-s]){
            tail--;
        }
        q[++tail] = i-s;
        while(head<=tail && q[head]<i-t){
            ++head;
        }
        if(head<=tail && prefixSum[i] - prefixSum[q[head]] >=0) 
            return true;
    }
    return false;
}
int main(){
    scanf("%d%d%d",&n,&s,&t);
    int maxa = -10005, mina = 10005;
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        maxa = max(maxa,a[i]);
        mina = min(mina,a[i]);
    }
    double left = mina , right = maxa;
    while(1){
        if(fabs(left - right) < 1e-5){
            break;
        }
        double mid = (left + right) / 2;
        if(check(mid)){
            left = mid;
        }else{
            right = mid;
        }
    }
    printf("%.3lf\n",right);
    return 0;
}