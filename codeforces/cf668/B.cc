#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
long long nagetive,positive;
int n;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        nagetive = 0;
        positive = 0;
        scanf("%d",&n);
        long long a;
        for(int i=0;i<n;++i){
            scanf("%lld",&a);
            //printf("%lld %lld\n",positive,nagetive);
            if(a<0){
                if(positive<-a){
                    nagetive += -a-positive;
                    positive = 0;
                }else{
                    positive += a;
                }
            }else if (a>0){
                positive += a;
            }
        }
        //printf("%lld %lld\n",positive,nagetive);
        printf("%lld\n",positive);
    }
    return 0;
}