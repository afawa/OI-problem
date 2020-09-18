#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int a[105];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
        }
        for(int i=n-1;i>=0;--i){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}