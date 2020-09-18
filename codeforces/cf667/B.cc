#include <iostream>
#include <cstdio>

using namespace std;
int a,b,x,y,n;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d",&a,&b,&x,&y,&n);
        if(n>=(a-x+b-y)){
            printf("%lld\n",(long long)x*(long long)y);
        }else{
            int c = a+b-n;
            int mina = max(a-n,x);
            int minb = max(b-n,y);
            printf("%lld\n",min((long long)(c-mina)*(long long)(mina),(long long)(minb)*(long long)(c-minb)));
        }
    }
    return 0;
}