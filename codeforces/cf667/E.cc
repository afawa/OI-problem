#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int n,k,cnt=0;
int x[200005],y[200005];
int sum[200005];
int sum_k[200005];
map<int,int> mp;
void mp_insert(int val){
    if(mp.count(val)){
        mp[val]++;
    }else{
        mp[val]=1;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(sum,0,sizeof(sum));
        cnt=0;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i){
            scanf("%d",x+i);
        }
        for(int i=0;i<n;++i){
            scanf("%d",y+i);
        }
        sort(x,x+n);
        int prev=x[0];
        sum[cnt]++;
        for(int i=1;i<n;++i){
            if(x[i]==prev){
                sum[cnt]++;
            }else{
                ++cnt;
                sum[cnt]++;
            }
            prev = x[i];
        }
        int size = unique(x,x+n)-x;
        int prev_pos = -100;
        int start = x[0];
        int end = x[0] + k;
        int pos = upper_bound(x,x+size,end) - x -1;
        for(int i=0;i<=pos;++i){
            sum_k[0]+=sum[i];
        }
        prev_pos = pos;

        for(int i=1;i<size;++i){
            start = x[i];
            end = x[i]+k;
            pos = upper_bound(x,x+size,end) - x -1;
            sum_k[i] = sum_k[i-1];
            sum_k[i]-=sum[i-1];
            if(prev_pos != pos){
                for(int j=prev_pos+1;j<=pos;++j){
                    sum_k[i]+=sum[j];
                }
            }
        }
        for(int i=0;i<size;++i){
            start = x[i];
            end = x[i]+k;
            pos = upper_bound(x,x+size,end) - x;
            for(int j=pos;)
        }

    }
    return 0;
}