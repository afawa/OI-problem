#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int p[100];
map<vector<int>,pair<double,double> > mp;
bool judge(vector<int> & next){
    for(int i=0;i<m;++i){
        if(next[i] > p[i])
            return false;
    }
    return true;
}
void bfs(){
    queue<vector<int> > q;
    vector<int> w;
    for(int i=0;i<m;++i){
        w.push_back(0);
    }
    mp[w].first = 1;
    q.push(w);
    while(!q.empty()){
        vector<int> now = q.front();q.pop();
        int aval=0;
        for(int i=0;i<m;++i){
            vector<int> next = now;
            next[i]+=1;
            sort(next.begin(),next.begin()+m);
            if(judge(next)){
                aval+=1;
            }
        }
        if(aval == 0)
            continue;
        mp[now].second = m / (double) aval;
        for(int i=0;i<m;++i){
            vector<int> next = now;
            next[i]+=1;
            sort(next.begin(),next.begin()+m);
            if(judge(next)){
                if(!mp.count(next)){
                    mp[next] = {mp[now].first / aval,0};
                    q.push(next);
                }else{
                    mp[next].first += mp[now].first/aval;
                }
            }
        }
    }
}
int main(){
    int t,ca=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        mp.clear();
        memset(p,0,sizeof(p));
        for(int i=0;i<k;++i)
            scanf("%d",p+i);
        sort(p,p+m);
        bfs();
        double ans=0;
        for(auto it = mp.begin();it != mp.end(); ++it){
            ans += it->second.first * it->second.second;
        }
        printf("Case #%d: %.6lf\n",++ca,ans);
    }
    return 0;
}