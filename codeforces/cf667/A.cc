#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    int a,b;
    while(t--){
        scanf("%d%d",&a,&b);
        int res = a-b;
        if(res<0){
            res = -res;
        }
        printf("%d\n",res/10 + (res%10 == 0 ? 0:1));
    }
}