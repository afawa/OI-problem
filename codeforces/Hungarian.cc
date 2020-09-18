#include <cstdio>
#include <cstring>

using namespace std;
int n;
int map[205][205];
int p[205];
int vis[205];

bool match(int i){
  for(int j=0;j<n;++j){
    if(map[i][j] && !vis[j]){
      vis[j]=1;
      if(p[j] == -1 || match(p[j])){
        p[j] = i;
        return true;
      }
    }
  }
  return false;
}

int Hungarian(){
  int cnt=0;
  for(int i=0;i<n;++i){
    memset(vis,0,sizeof(vis));
    if(match(i)){
      ++cnt;
    }
  }
  return cnt;
}
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    memset(p,-1,sizeof(p));
    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
        scanf("%d",&map[i][j]);
      }
    }
    puts(Hungarian() == n ? "Yes" : "No");
  }
  return 0;
}