#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n,x,y;
vector<long long> ans;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ans.clear();
        scanf("%d%d%d",&n,&x,&y);
        int tmp = n-1;
        while(1){
            if((y-x)%tmp == 0)
                break;
            tmp-=1;
        }
        int stride = (y-x) / tmp;
        int sum = ((y-x) / stride)+1;
        for(int i = x;i<=y;i+=stride){
            ans.push_back(i);
        }
        x-=stride;
        while(1){
            if(x<=0)
                break;
            if(sum==n)
                break;
            sum++;
            ans.push_back(x);
            x-=stride;
        }
        for(int i=1;i<=n-sum;++i){
            ans.push_back((long long)y+(long long)i*stride);
        }
        for(int i=0;i<ans.size();++i){
            printf("%lld ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}