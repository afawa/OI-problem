#include <iostream>
#include <cstdio>

using namespace std;
int n,a[105];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
        }
        int sum=0,Max=-1;
        for(int i=0;i<n;++i){
            sum+=a[i];
            Max = max(Max,a[i]);
        }
        sum-=Max;
        if(Max>sum){
            printf("T\n");
        }else if(Max == sum){
            printf("HL\n");
        }else{
            int tmp = sum-Max;
            puts(tmp%2 ? "T":"HL");
        }
    }
    return 0;
}