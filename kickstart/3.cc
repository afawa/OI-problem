#include <bits/stdc++.h>
using namespace std;
int s,c;
int x1,x2,y,y2;
int mp[10][20];
int num,ans;
struct point{
    int x,y;
};
int dfs(int person,int x,int y,int x1,int y1,int flag){
    vector<point> can;
    point tmp;
    vector<int> possible;
    if(y != 1 && !mp[x][y-1]){
        tmp.x = x;tmp.y = y-1;
        can.push_back(tmp);
    }
    if(y != 2*x-1 && !mp[x][y+1]){
        tmp.x = x;tmp.y = y+1;
        can.push_back(tmp);
    }
    if(y%2==0 && !mp[x-1][y-1]){
        tmp.x = x-1;tmp.y = y-1;
        can.push_back(tmp);
    }
    if(y%2==1 && x!=s && !mp[x+1][y+1]){
        tmp.x = x+1; tmp.y = y+1;
        can.push_back(tmp);
    }
    if(can.size()==0){
        if(flag == 1){
            //printf("%d %d\n",ans,person);
            return num;
        }else{
            possible.push_back( dfs(1-person,x1,y1,x,y,1));
        }
    }else{
        for(int i=0;i<can.size();++i){
            int nx = can[i].x;
            int ny = can[i].y;
            mp[nx][ny]=1;
            if(person==0){
                num++;
            }else{
                num--;
            }
            possible.push_back(dfs(1-person,x1,y1,nx,ny,0));
            if(person==0){
                num--;
            }else{
                num++;
            }
            mp[nx][ny]=0;
        }
    }
    sort(possible.begin(),possible.end());
    if(person == 0){
        return possible[possible.size()-1];
    }else{
        return possible[0];
    }
}
int main(){
    int t,ca=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&s);
        scanf("%d%d%d%d",&x1,&y,&x2,&y2);
        scanf("%d",&c);
        int a,b;
        memset(mp,0,sizeof(mp));
        mp[x1][y] = 1;
        mp[x2][y2] = 1;
        for(int i=0;i<c;++i){
            scanf("%d%d",&a,&b);
            mp[a][b]=1;
        }
        num = 0;
        printf("Case #%d: %d\n",++ca,dfs(0,x1,y,x2,y2,0));
    }
    return 0;
}