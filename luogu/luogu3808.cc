#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
int n,cnt;
struct node{
    int pChild[26];
    int fail;
    int end;
};
char str[1000006];
node T[1000006];
void insert(){
    node * p = T+1;
    for(int i=0;str[i];++i){
        if(p->pChild[str[i]-'a']==0){
            ++cnt;
            p->pChild[str[i]-'a']=cnt;
        }
        p = T + p->pChild[str[i]-'a'];
    }
    p->end++;
}
void build(){
    for(int i=0;i<26;++i){
        T[0].pChild[i]=1;
    }
    T[0].fail = 0;
    T[1].fail = 0;
    queue<node *> que;
    que.push(T+1);
    while(!que.empty()){
        node * root = que.front();que.pop();
        for(int i=0;i<26;++i){
            node * p = T + root->pChild[i];
            if(root->pChild[i]!=0){
                node * prev = T + root->fail;
                while(prev->pChild[i]==0){
                    prev = T + prev->fail;
                }
                p->fail = prev->pChild[i];
                que.push(p);
            }
        }
    }
}
int query(){
    node * p = T+1;
    int ans=0;
    for(int i=0;str[i];++i){
        while(p->pChild[str[i]-'a']==0){
            p = T + p->fail;
        }
        p = T + p->pChild[str[i]-'a'];
        for(int t = p-T;t&&T[t].end!=-1;t = T[t].fail){
            ans+=T[t].end;
            T[t].end=-1;
        }
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    cnt=1;
    for(int i=0;i<n;++i){
        scanf("%s",str);
        insert();
    }
    build();
    scanf("%s",str);
    printf("%d\n",query());
    return 0;
}