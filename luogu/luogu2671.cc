#include <bits/stdc++.h>
using namespace std;
int n,m;
int number[100006],color[100006];
int ans=0;
struct item{
    int pos,num;
};
void process(vector<item> &vec){
    int size = vec.size();
    int sum = 0;
    for(int i=0;i<size;++i){
        sum = (sum + vec[i].num) % 10007;
    }
    for(int i=0;i<size;++i){
        ans = (ans + vec[i].pos * ((sum + (size-2) * vec[i].num) % 10007)) % 10007;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",number+i);
    }
    for(int i=1;i<=n;++i){
        scanf("%d",color+i);
    }
    vector<item> odd[m+1];
    vector<item> even[m+1];
    item tmp;
    for(int pos = 1;pos <= n;++pos){
        tmp.num = number[pos];
        tmp.pos = pos;
        if(pos % 2 == 0){
            even[color[pos]].push_back(tmp);
        }else{
            odd[color[pos]].push_back(tmp);
        }
    }
    for(int i=1;i<=m;++i){
        process(odd[i]);
        process(even[i]);
    }
    printf("%d\n",ans);
    return 0;
}