#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n,k;
string str;
int sum1,sum0;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        cin>>str;
        int flag=1;
        sum1=0;sum0=0;
        for(int i=0;i<k && flag;++i){
            int val = -1;
            int pos = i;
            while(pos<n){
                if(str[pos]=='0'){
                    if(val == 1){
                        flag = 0;
                        break;
                    }
                    val = 0;
                }else if(str[pos] == '1'){
                    if(val == 0){
                        flag = 0;
                        break;
                    }
                    val = 1;
                }
                pos+=k;
            }
            if(flag && val !=-1){
                pos = i;
                while(pos<n){
                    str[pos] = '0'+val;
                    pos+=k;
                }
            }
        }
        
        for(int i=k;i<n;++i){
            char a = str[i-k];
            char b = str[i];
            if((a=='0'&& b=='1')||(a=='1'&&b=='0')){
                flag = 0;
                break;
            }
            if(a=='?' && b!='?'){
                str[i-k] = str[i];
            }else if(a != '?' && b=='?'){
                str[i] = str[i-k];
            }
        }
        for(int i=0;i<k;++i){
            if(str[i]=='0'){
                sum0++;
            }else if(str[i] == '1'){
                sum1++;
            }else if(str[i] == '?'){

            }
        }
    }
    return 0;
}