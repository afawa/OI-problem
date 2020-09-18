#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int k,n;
vector<int> vec;
void swap(int i,int j){
    int pp = vec[j];
    for(int tmp = j;tmp>i;--tmp){
        vec[tmp] = vec[tmp-1];
    }
    vec[i] = pp;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&k,&n);
        int a;
        vec.clear();
        for(int i=0;i<n;++i){
            scanf("%d",&a);
            vec.push_back(a);
        }
        int cnt=0;
        while(1){
            if(k==0 || cnt == n)
                break;
            int pos,Max=-1;
            for(int i=cnt;i<n && i<=k+cnt ;++i){
                if(Max<vec[i]){
                    Max = vec[i];
                    pos = i;
                }
            }
            k-=(pos-cnt);
            swap(cnt,pos);
            cnt++;
        }
        if(k%2){
            swap(n-2,n-1);
        }
        for(int i=0;i<n;++i){
            printf("%d ",vec[i]);
        }
        printf("\n");
    }
    return 0;
}