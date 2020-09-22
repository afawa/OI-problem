#include <bits/stdc++.h>
using namespace std;
int n,m,d[500005];
struct node{
    int left,right,max_subx,max_suby,max_prefixx,max_suffixx;
    long long max_sub,max_prefix,max_suffix,sum;
};
node T[2000005];
bool cmp(tuple<long long,int,int> a,tuple<long long,int,int> b){
    if(get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b)){
        return get<2>(a) < get<2>(b);
    }
    if(get<0>(a) == get<0>(b)){
        return get<1>(a) < get<1>(b);
    }
    return get<0>(a) > get<0>(b);
}
node merge(node & tmp1,node & tmp2){
    node ans;
    ans.left = tmp1.left;
    ans.right = tmp2.right;
    ans.sum = tmp1.sum + tmp2.sum;
    vector<tuple<long long,int,int>> vec{make_tuple(tmp1.max_sub,tmp1.max_subx,tmp1.max_suby),
                        make_tuple(tmp2.max_sub,tmp2.max_subx,tmp2.max_suby),
                        make_tuple(tmp1.max_suffix+tmp2.max_prefix,tmp1.max_suffixx,tmp2.max_prefixx)};
    sort(vec.begin(),vec.end(),cmp);
    ans.max_sub = get<0>(vec[0]);
    ans.max_subx = get<1>(vec[0]);
    ans.max_suby = get<2>(vec[0]);
    if(tmp1.sum + tmp2.max_prefix > tmp1.max_prefix){
        ans.max_prefix = tmp1.sum + tmp2.max_prefix;
        ans.max_prefixx = tmp2.max_prefixx;
    }else{
        ans.max_prefix = tmp1.max_prefix;
        ans.max_prefixx = tmp1.max_prefixx;
    }
    if(tmp2.sum + tmp1.max_suffix >= tmp2.max_suffix){
        ans.max_suffix = tmp2.sum + tmp1.max_suffix;
        ans.max_suffixx = tmp1.max_suffixx;
    }else{
        ans.max_suffix = tmp2.max_suffix;
        ans.max_suffixx = tmp2.max_suffixx;
    }
    return ans;
}
void build(int left,int right,int now){
    if(left == right){
        T[now].left = left;
        T[now].right = right;
        T[now].max_sub = d[left],T[now].max_subx = left,T[now].max_suby = left;
        T[now].max_prefix = d[left],T[now].max_prefixx = left;
        T[now].max_suffix = d[left],T[now].max_suffixx = left;
        T[now].sum = d[left];
        return;
    }
    int mid = (left + right) /2;
    build(left,mid,now*2);
    build(mid+1,right,now*2+1);
    T[now] = merge(T[2*now],T[2*now+1]);
}

node query(int left,int right,int now){
    if(T[now].left == left && T[now].right == right){
        return T[now];
    }
    node ans;
    int mid = (T[now].left + T[now].right)/2;
    if(mid>=right){
        ans = query(left,right,2*now);
    }else if(mid < left){
        ans = query(left,right,2*now+1);
    }else{
        node tmp1 = query(left,mid,2*now);
        node tmp2 = query(mid+1,right,2*now+1);
        ans = merge(tmp1,tmp2);
    }
    return ans;
}

int main(){
    int cnt=0;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;++i){
            scanf("%d",d+i);
        }
        build(0,n-1,1);
        int left,right;
        printf("Case %d:\n",++cnt);
        for(int i=0;i<m;++i){
            scanf("%d%d",&left,&right);
            node ans = query(left-1,right-1,1);
            printf("%d %d\n",ans.max_subx+1,ans.max_suby+1);
        }
    }
    return 0;
}