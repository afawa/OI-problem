#include <bits/stdc++.h>
using namespace std;
int n,m;
char in;
int high[1007];
long long ans=0;
struct item{
    int val,pos;
};
stack<item> s;
void clear(){
    while(!s.empty())
        s.pop();
}
int main(){
    scanf("%d%d",&n,&m);
    memset(high,0,sizeof(high));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf(" %c",&in);
            if(in == '.'){
                ++high[j];
            }else{
                high[j]=0;
            }
        }
        clear();
        high[m] = 0;
        item tmp;
        tmp.pos = -1;
        tmp.val = 0;
        s.push(tmp);
        for(int j=0;j<=m;++j){
            tmp.val = high[j];
            if(high[j] >= s.top().val){
                tmp.pos = j;
            }else{
                int leftPos,val;
                while(high[j] < s.top().val){
                    leftPos = s.top().pos;
                    val = s.top().val;
                    s.pop();
                    ans += (1+ j -leftPos) * (j - leftPos) / 2 * (val - max(s.top().val,high[j]));
                }
                tmp.pos = leftPos;
            }
            s.push(tmp);
        }
    }
    printf("%lld\n",ans);   
    return 0;
}