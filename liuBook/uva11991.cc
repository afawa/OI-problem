#include <iostream>
#include <cstring>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;
int n,m;
unordered_map<int,vector<int>> mp;
int main(){

    while(~scanf("%d%d",&n,&m)){
        int a,b;
        mp.clear();
        for(int i=1;i<=n;++i){
            scanf("%d",&a);
            mp[a].push_back(i);
        }
        for(int i=0;i<m;++i){
            scanf("%d%d",&a,&b);
            if(mp[b].size()<a){
                printf("0\n");
            }else{
                printf("%d\n",mp[b][a-1]);
            }
        }
    }
    return 0;
}