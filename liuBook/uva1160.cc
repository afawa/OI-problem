#include <bits/stdc++.h>
using namespace std;
int p[100006];
int getRoot(int a){
    if(a!=p[a]){
        p[a] = getRoot(p[a]);
    }
    return p[a];
}
void merge(int a,int b){
    int ra = getRoot(a);
    int rb = getRoot(b);
    p[ra] = rb;
}
void init(){
    for(int i = 0;i<=100000;++i){
        p[i] = i;
    }
}
int main(){
    int a,b,ans=0;
    init();
    while(~scanf("%d",&a)){
        if(a == -1){
            printf("%d\n",ans);
            ans = 0;
            init();
        }else{
            scanf("%d",&b);
            if(getRoot(a) == getRoot(b)){
                ans++;
            }else{
                merge(a,b);
            }
        }
    }
    return 0;
}