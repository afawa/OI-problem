#include <bits/stdc++.h>
using namespace std;
char str[300005];
int n,cnt;
struct node{
    int child[26];
    int end;
};
node T[400005];
void insert(char * s){
    node * p = T;
    for(int i=0;s[i];++i){
        int child = p->child[s[i]-'a'];
        if(!child){
            p->child[s[i]-'a'] = ++cnt;
        }
        p = T + p->child[s[i]-'a'];
    }
    p->end++;
}
int mem[300005];
int dfs(int pos,int now){
    if(!str[pos]){
        if(T[now].end != 0){
            return 1;
        }else
            return 0;
    }
    int ans=0;
    if(T[now].end != 0){
        if(mem[pos]==-1){
            mem[pos] = dfs(pos,0);
        }
        ans = (ans + mem[pos]) % 20071027;
    }
    int next = T[now].child[str[pos]-'a'];
    if(next != 0){
        ans = (ans + dfs(pos+1,next)) % 20071027;
    }
    return ans;
}
int main(){
    int ca = 0;
    while(~scanf("%s",str)){
        scanf("%d",&n);
        char tmp[105];
        cnt=0;
        memset(T,0,sizeof(T));
        memset(mem,-1,sizeof(mem));
        for(int i=0;i<n;++i){
            scanf("%s",tmp);
            insert(tmp);
        }
        printf("Case %d: %d\n",++ca,dfs(0,0));
    }
    return 0;
}