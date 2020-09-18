#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

queue<int> need0,need1;
int n,cnt;
string str;
int ans[200006];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        cnt=0;
        while(!need0.empty()){
            need0.pop();
        }
        while(!need1.empty()){
            need1.pop();
        }
        memset(ans,0,sizeof(ans));
        scanf("%d",&n);
        cin>>str;
        for(int i=0;i<n;++i){
            if(str[i]=='0'){
                if(need0.empty()){
                    ++cnt;
                    ans[i] = cnt;
                    need1.push(cnt);
                }else{
                    int tmp = need0.front();need0.pop();
                    ans[i] = tmp;
                    need1.push(tmp);
                }
            }else if(str[i]=='1'){
                if(need1.empty()){
                    ++cnt;
                    ans[i] = cnt;
                    need0.push(cnt);
                }else{
                    int tmp = need1.front();need1.pop();
                    ans[i] = tmp;
                    need0.push(tmp);
                }
            }
        }
        printf("%d\n",cnt);
        for(int i=0;i<n;++i){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}