#include <bits/stdc++.h>
using namespace std;
int p[20005],n,a,b,dis[20005];
char cmd;
int getRoot(int a){
    if(a!=p[a]){
        int tmp = p[a];
        p[a] = getRoot(p[a]);
        dis[a] = dis[a] + dis[tmp];
    }
    return p[a];
}
void merge(int a,int b){
    p[a] = b;
    dis[a] = (int)abs(a-b) % 1000;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            p[i] = i;
            dis[i] = 0;
        }
        while(1){
            cin.get();
            scanf("%c",&cmd);
            if(cmd == 'O')
                break;
            if(cmd == 'E'){
                scanf("%d",&a);
                getRoot(a);
                printf("%d\n",dis[a]);
            }else if(cmd == 'I'){
                scanf("%d%d",&a,&b);
                merge(a,b);
            }
        }
    }
    return 0;
}