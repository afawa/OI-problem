#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
int n;
int a[300005];
vector<int> vec[300005];
vector<int> vec1[300005];
struct node{
    int val,pos;
};
stack<node> s;
stack<node> s1;
int dp[300005];
void update(int now,int prev){
    if(dp[now]==-1){
        dp[now] = dp[prev] + 1;
    }else{
        dp[now] = min(dp[prev] + 1, dp[now]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
    }
    node tmp;
    tmp.pos = 0;
    tmp.val = 1e9 + 10;
    s.push(tmp);
    for(int i=1;i<=n;++i){
        if(a[i]<=s.top().val){
            vec[i].push_back(s.top().pos);
        }else{
            while(a[i]>s.top().val){
                vec[i].push_back(s.top().pos);
                int top_val = s.top().val;
                s.pop();
                while(s.top().val == top_val){
                    s.pop();
                }
            }
            vec[i].push_back(s.top().pos);
        }
        tmp.pos = i;
        tmp.val = a[i];
        s.push(tmp);
    }
    tmp.pos = 0;
    tmp.val = -1;
    s1.push(tmp);
    for(int i=1;i<=n;++i){
        if(a[i]>=s1.top().val){
            vec1[i].push_back(s1.top().pos);
        }else{
            while(a[i]<s1.top().val){
                vec1[i].push_back(s1.top().pos);
                int top_val = s1.top().val;
                s1.pop();
                while(s1.top().val == top_val){
                    s1.pop();
                }
            }
            vec1[i].push_back(s1.top().pos);
        }
        tmp.pos = i;
        tmp.val = a[i];
        s1.push(tmp);
    }
    memset(dp,-1,sizeof(dp));
    dp[1] = 0;
    for(int i=2;i<=n;++i){
        for(int j=0;j<vec[i].size();++j){
            if(vec[i][j]!=0){
                update(i,vec[i][j]);
            }
        }
        for(int j=0;j<vec1[i].size();++j){
            if(vec1[i][j]!=0){
                update(i,vec1[i][j]);
            }
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
