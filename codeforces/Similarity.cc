#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int n;
char str[150];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",str);
        string ans;
        for(int i=1;i<=n;++i){
          int start = i-1;
          ans.push_back(str[start+i-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}