#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n;
int p[3005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
      scanf("%d",&n);
      for(int i=0;i<n;++i){
        scanf("%d",p+i);
      }
      vector<int> vec[3005];
      for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
          if(p[i]==p[j]){
            vec[i].push_back(j);
          }
        }
      }
      long long ans=0;
      for(int i=0;i<n;++i){
        for(int j=0;j<vec[i].size();++j){
          set<int> s;
          for(int k=i+1;k<vec[i][j];++k){
            if(s.count(k)){
              continue;
            }
            if(vec[k].size()==0){
              continue;
            }
            int pos = upper_bound(vec[k].begin(),vec[k].end(),vec[i][j]) - vec[k].begin();
            //printf("%d %d %d %d\n",i,vec[i][j],k,pos);
            if(vec[k][pos-1]!=vec[i][j]){
              ans += (vec[k].size() - pos) * (pos+1);
            }else{
              ans += (vec[k].size() - pos) * (pos);
            }
            //printf("%lld\n",ans);
            for(int l = 0;l<pos;++l){
              s.insert(vec[k][l]);
            }
          }
        }
      }
      printf("%lld\n",ans);
    }
    return 0;
}