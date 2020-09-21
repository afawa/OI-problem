#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[1000008];
struct item{
    int pos,val;
};
deque<item> que;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d",a+i);
    }
    item tmp;
    for(int i=0;i<k;++i){
        while(!que.empty() && que.back().val>=a[i]){
            que.pop_back();
        }
        tmp.pos = i;
        tmp.val = a[i];
        que.push_back(tmp);
    }
    vector<int> ans1;
    for(int i=k;i<n;++i){
        ans1.push_back(que.front().val);
        if(que.front().pos == i-k){
            que.pop_front();
        }
        while(!que.empty() && que.back().val>=a[i]){
            que.pop_back();
        }
        tmp.pos = i;
        tmp.val = a[i];
        que.push_back(tmp);
    }
    ans1.push_back(que.front().val);
    que.clear();
    for(int i=0;i<k;++i){
        while(!que.empty() && que.back().val<=a[i]){
            que.pop_back();
        }
        tmp.pos = i;
        tmp.val = a[i];
        que.push_back(tmp);
    }
    vector<int> ans2;
    for(int i=k;i<n;++i){
        ans2.push_back(que.front().val);
        if(que.front().pos == i-k){
            que.pop_front();
        }
        while(!que.empty() && que.back().val<=a[i]){
            que.pop_back();
        }
        tmp.pos = i;
        tmp.val = a[i];
        que.push_back(tmp);
    }
    ans2.push_back(que.front().val);
    for_each(begin(ans1),end(ans1),[](int x){printf("%d ",x);});
    printf("\n");
    for_each(begin(ans2),end(ans2),[](int x){printf("%d ",x);});
    printf("\n");
    return 0;
}