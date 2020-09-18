#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int n,h;
vector<int> vec;
struct node{
    int pos;
    double height;
};
stack<node> s;
int main(){
    scanf("%d%d",&n,&h);
    int a;
    vec.push_back(h);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        vec.push_back(a);
    }
    node tmp;
    vector<int> ans;
    for(int i=1;i<=n;++i){
        double now = (double)(h-vec[i]) / (double) (i);
        if(s.empty()){
            ans.push_back(0);
        }else{
            if(now >= s.top().height){
                ans.push_back(s.top().pos);
            }else{
                while(!s.empty() && now < s.top().height){
                    s.pop();
                }
                if(s.empty()){
                    ans.push_back(0);
                }else{
                    ans.push_back(s.top().pos);
                }
            }
        }
        tmp.height = now;
        tmp.pos = i;
        s.push(tmp);
    }
    for(int i=0;i<n;++i){
        printf("%d\n",ans[i]);
    }
    return 0;
}