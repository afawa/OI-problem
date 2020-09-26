#include <bits/stdc++.h>
using namespace std;
int n,s;
int p[100005],q[100005];
long long prefixSum[100005];
int main(){
    while(~scanf("%d%d",&n,&s)){
        for(int i=1;i<=n;++i){
            scanf("%d",p+i);
        }
        prefixSum[0]=0;
        for(int i=1;i<=n;++i){
            prefixSum[i] = prefixSum[i-1] + p[i];
        }
        int head = 1, tail = 0;
        memset(q,0,sizeof(q));
        int ans = n;
        int flag=0;
        for(int i=1;i<=n;++i){
            if(p[i] >= s){
                flag=1;
                ans = 1;
            }
            while(tail >= head && prefixSum[i] - prefixSum[q[head]] >= s){
                flag=1;
                ans = min(ans,i-q[head]);
                head++;
            }
            while(tail >= head && prefixSum[i]<=prefixSum[tail]){
                tail--;
            }
            q[++tail] = i;
        }
        if(flag)
            printf("%d\n",ans);
        else{
            printf("0\n");
        }
    }
    return 0;
}