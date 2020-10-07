#include <bits/stdc++.h>
using namespace std;
int n;
struct item{
    long long t1,t2;
    bool operator <(const item & a) const{
        return t2<a.t2;
    }
};
priority_queue<int> q;
item items[150005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld%lld",&items[i].t1,&items[i].t2);
    }
    long long sum=0,ans = 0;
    sort(items,items+n);
    for(int i=0;i<n;++i){
        if(sum + items[i].t1 < items[i].t2){
            sum += items[i].t1;
            q.push(items[i].t1);
            ans++;
        }else{
            if(!q.empty()){
                int tmp = q.top();
                if(items[i].t1 < tmp){
                    sum = sum - tmp + items[i].t1;
                    q.pop();
                    q.push(items[i].t1);
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}