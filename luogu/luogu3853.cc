#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int l,n,m;
int p[100005];
bool check(int mid){
    int tmp=0;
    for(int i=1;i<n;++i){
        int val = p[i] - p[i-1];
        tmp += val / mid;
        if(val % mid ==0){
            tmp--;
        }
        if(tmp > m)
            return false;
    }
    return true;
}
int main(){
    scanf("%d%d%d",&l,&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d",p+i);
    int left=1,right=l;
    while(1){
        if(left>=right)
            break;
        int mid = (left+right)/2;
        if(check(mid)){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    printf("%d\n",right);
    return 0;
}