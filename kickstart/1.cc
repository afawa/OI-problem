#include <bits/stdc++.h>
using namespace std;
int n,x;
int a[100005];
struct onePerson{
    int rounds,num;
    bool operator <(const onePerson & a) const{
        if(rounds == a.rounds)
            return num<a.num;
        return rounds<a.rounds;
    }
};
onePerson q[100005];
int main(){
    int t,ca = 0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&x);
        onePerson tmp;
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
            tmp.rounds = a[i]/x;
            if(a[i] % x != 0)
                tmp.rounds++;
            tmp.num = i+1;
            q[i] = tmp;
        }
        sort(q,q+n);
        printf("Case #%d:",++ca);
        for(int i=0;i<n;++i){
            printf(" %d",q[i].num);
        }
        printf("\n");
    }
    return 0;
}