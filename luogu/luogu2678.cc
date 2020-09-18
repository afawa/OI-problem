#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int l,n,m;
int s[50005];
bool check(int mid){
    int prev=0,tmp=0;
    for(int i=0;i<n;++i){
        if(s[i] - prev >= mid){
            prev=s[i];
        }else{
            tmp++;
        }
    }
    if(l-prev<mid)
        ++tmp;
    if(tmp>m)
        return false;
    return true;
}
int main(){
    scanf("%d%d%d",&l,&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",s+i);
    }
    int left=0,right=l;
    while(1){
        if(left>=right){
            break;
        }
        int mid = (left+right)/2;
        if(check(mid)){
            left = mid+1;
        }else{
            right = mid;
        }
    }
    if(right == l){
        if(check(l)){
            printf("%d\n",l);
            return 0;
        }
    }
    printf("%d\n",right-1);
    return 0;
}