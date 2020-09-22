#include <bits/stdc++.h>
using namespace std;
struct edge{
    int x,y1,y2,type;
    bool operator<(const edge & a) const{
        return x<a.x;
    }
};
edge edges[2005];
int __y[2005];
struct node{
    int left,right;
    int covers;
};
node T[10000];
int lens=0;
void build(int left,int right,int now){
    T[now].left = left;
    T[now].right = right;
    T[now].covers = 0;
    if(left == right){
        return;
    }
    int mid = (left+right)/2;
    build(left,mid,now*2);
    build(mid+1,right,now*2+1);
}
void insert(int left,int right,int type,int now){
    if(T[now].left == left && T[now].right == right && T[now].covers != -1){
        if(type == 0){
            T[now].covers ++;
            if(T[now].covers ==1){
                lens += __y[T[now].right+1] - __y[T[now].left];
            }
        }else{
            T[now].covers --;
            if(T[now].covers == 0){
                lens -= __y[T[now].right+1] - __y[T[now].left];
            }
        }
        return;
    }
    if(T[now].covers != -1){
        T[now*2].covers = T[now].covers;
        T[now*2+1].covers = T[now].covers;
    }
    int mid = (T[now].left + T[now].right) /2;
    if(mid<left){
        insert(left,right,type,now*2+1);
    }else if(right<=mid){
        insert(left,right,type,now*2);
    }else{
        insert(left,mid,type,now*2);
        insert(mid+1,right,type,now*2+1);
    }
    if(T[now*2].covers == T[now*2+1].covers){
        T[now].covers = T[now*2].covers;
    }else{
        T[now].covers = -1;
    }
}
int n,x1,x2,y,y2;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d%d%d",&x1,&y,&x2,&y2);
        edges[i*2].x = x1;
        edges[i*2].type = 0;
        edges[i*2+1].x = x2;
        edges[i*2+1].type = 1;
        edges[i*2].y1 = edges[i*2+1].y1 = y2;
        edges[i*2].y2 = edges[i*2+1].y2 = y;
        __y[i*2] = y2;
        __y[i*2+1] = y;
    }
    sort(__y,__y+2*n);
    int k = unique(__y,__y+2*n) - __y;
    sort(edges,edges+2*n);
    for(int i=0;i<2*n;++i){
        edges[i].y1 = lower_bound(__y,__y+k,edges[i].y1) - __y;
        edges[i].y2 = lower_bound(__y,__y+k,edges[i].y2) - __y;
    }
    build(0,k-1,1);
    lens = 0;
    insert(edges[0].y1,edges[0].y2-1,edges[0].type,1);
    int prevX = edges[0].x;
    long long ans=0;
    for(int i=1;i<2*n;++i){
        ans += (long long)lens * (edges[i].x - prevX);
        prevX = edges[i].x;
        insert(edges[i].y1,edges[i].y2-1,edges[i].type,1);
    }
    printf("%lld\n",ans);
    return 0;
}