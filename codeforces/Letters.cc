#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cnt[26],n;
char str[1005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%s",str);
            for(int j=0;str[j];++j){
                cnt[str[j]-'a']++;
            }
        }
        int flag=1;
        for(int i=0;i<26;++i){
            if(cnt[i]%n!=0){
                flag=0;
                break;
            }
        }
        puts(flag==1 ? "YES":"NO");
    }
    return 0;
}