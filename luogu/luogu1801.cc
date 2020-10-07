#include <bits/stdc++.h>
using namespace std;
int m,n,a[200005],u[200005];
priority_queue<int,vector<int>,less<int> > maxq;
priority_queue<int,vector<int>,greater<int> > minq;
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;++i)
        scanf("%d",a+i);
    for(int j=1;j<=n;++j)
        scanf("%d",u+j);
    int size = 0,tmp = 1;
    for(int pos = 1;pos<=m;++pos){
        maxq.push(a[pos]);
        if(maxq.size()>size){
            int maxNow = maxq.top();maxq.pop();
            minq.push(maxNow);
        }
        while(u[tmp] == pos){
            tmp++;
            size ++;
            int ans = minq.top();minq.pop();
            printf("%d\n",ans);
            maxq.push(ans);
        }
    }
    return 0;
}