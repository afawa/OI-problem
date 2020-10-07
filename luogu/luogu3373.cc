#include <bits/stdc++.h>
using namespace std;
int n,m,p,a[100006];
struct op{
    int type,val;
    op(){type=-1,val=-1;};
    op(int t,int v):type(v),val(v) {};
};
struct node{
    int left,right,sum;
    vector<op> ops;
};
node T[400006];
void build(int left,int right,int now){
    T[now].left = left;
    T[now].right = right;
    T[now].ops.clear();
    if(left == right){
        T[now].sum = a[left] % p;
        return;
    }
    int mid = (left + right) / 2;
    build(left,mid,now*2);
    build(mid+1,right,now*2+1);
    T[now].sum = (T[now*2].sum + T[now*2+1].sum) % p;
}
void addMul(int left,int right,int val,int type,int now){
    if(T[now].left == left && T[now].right == right){
        T[now].ops.push_back({type,val});
        return;
    }
    if(T[now].ops.size() != 0){
        T[now*2].ops = T[now].ops;
        T[now*2+1].ops = T[now].ops;
    }
    int mid = (left + right) / 2;
    if(right <= mid){
        addMul(left,right,val,type,now*2);
    }else if(left > mid){
        addMul(left,right,val,type,now*2+1);
    }else{
        addMul(left,mid,val,type,now*2);
        addMul(mid+1,right,val,type,now*2+1);
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    build(1,n,1);
    int cmd,x,y,k;
    while(m--){
        scanf("%d",&cmd);
        if(cmd == 1 || cmd == 2){
            scanf("%d%d%d",&x,&y,&k);

        }
    }
    return 0;
}