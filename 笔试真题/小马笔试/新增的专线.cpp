#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n,a,b,k;
int map[1005][1005];
bool check(int mid){
    int Max=-1;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            Max = max(Max,min(map[i][j],min(map[i][b]+mid+map[a][j],map[i][a]+mid+map[b][j])));
        }
    }
    Max = max(Max,mid);
    if(Max+mid<k)
        return true;
    return false;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&map[i][j]);
        }
    }
    scanf("%d%d%d",&a,&b,&k);
    int left=0,right=k+1;
    while(1){
        if(left>=right)
            break;
        int mid = (left+right)/2;
        if(check(mid)){
            left = mid+1;
        }else{
            right = mid;
        }
    }
    if(right == 0){
        puts(check(0) ? "0" : "-1");
    }else{
        printf("%d\n",right-1);
    }
    return 0;
}