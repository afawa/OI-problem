#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
map<int,int> mps[20][200005];
void init(){
    for(int i=0;i<20;++i){
        for(int j=0;j<200005;++j)
            mps[i][j].clear();
    }
}

bool flag;
bool merge(int left,int right,int level){
    if(flag == false)
        return false;
    if(left == right){
        mps[level][left][a[left]] = 1;
        return true;
    }
    int mid = (left + right) / 2;
    mps[level][left] = mps[level+1][left];
    
    for(int i=mid+1;i<=right;++i){
        if(mps[level+1][left].count(a[i]))
            mps[level][left][a[i]]++;
        else{
            mps[level][left][a[i]] = 1;
        }
    }
    for(auto it= mps[level][left].begin();it!=mps[level][left].end();++it){
        if(it->second == 1){
            return true;
        }
    }
    flag = false;
    return false;
}

bool split(int left,int right,int level){
    if(flag == false)
        return false;
    int mid = (left + right) / 2;
    bool ans = split(left,mid,level+1) & split(mid+1,right,level+1);
    ans &= merge(left,right,level);
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        flag = true;
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
        }
        puts(split(0,n-1,0)?"non-boring" : "boring");
    }
    return 0;
}