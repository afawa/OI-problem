#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n,l,r,h;
long long ans;
struct node{
    int left,right,cnt,maxh;
};
node T[400005];
void build(int left,int right,int now){
    T[now].left = left;
    T[now].right = right;
    T[now].cnt = 0;
    T[now].maxh = 0;
    if(left == right){
        return;
    }
    int mid = (left+right)/2;
    build(left,mid,now*2);
    build(mid+1,right,now*2+1);
}
void insert(int left,int right,int height,int now){
    if(T[now].cnt>height)
        return;
    if(T[now].left == left && T[now].right == right){
        if(T[now].cnt<=height){
            if(T[now].maxh <= height){
                ans += right - left + 1;
                T[now].cnt = height;
                T[now].maxh = height;
                return;
            }
        }
    }
    T[now*2].cnt = max(T[now*2].cnt,T[now].cnt);
    T[now*2+1].cnt = max(T[now*2+1].cnt,T[now].cnt);
    int mid = (T[now].left + T[now].right)/2;
    if(left > mid){
        insert(left,right,height,now*2+1);
    }else if(right <= mid){
        insert(left,right,height,now*2);
    }else{
        insert(left,mid,height,now*2);
        insert(mid+1,right,height,now*2+1);
    }
    T[now].maxh = max(T[2*now].maxh,T[2*now+1].maxh);
    if(T[now*2].cnt != T[now*2+1].cnt || T[now*2].cnt == -1 || T[now*2+1].cnt==-1){
        T[now].cnt = -1;
    }else{
        T[now].cnt = T[now*2].cnt;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(T,0,sizeof(T));
        ans=0;
        build(1,100000,1);
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d%d%d",&l,&r,&h);
            insert(l,r-1,h,1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}