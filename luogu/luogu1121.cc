#include <bits/stdc++.h>
using namespace std;
int n,a[200006];
struct s{
    int val,left,right;
};
s dp(int left,int right){
    s now;
    if(left > right){
        now.val = 0;now.left=0;now.right=0;
        return now;
    }
    int tmp=0,leftTmp,rightTmp;
    int ans= INT_MIN;
    for(int i=left;i<=right;++i){
        if(i - leftTmp == n)
            break;
        if(tmp<=0){
            tmp=a[i % n];
            leftTmp = i;
        }else{
            tmp += a[i % n];
        }
        if(tmp > ans){
            ans = tmp;
            now.val = ans;
            now.left = leftTmp;
            now.right = i;
        }
    }
    return now;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
    s max1 = dp(0,2*n-1);
    int ans = INT_MIN;
    if(max1.right - max1.right > 1){
        ans = max1.val;
    }
    s max2 = dp(max1.right+1,max1.left-1+n);
    ans = max(ans,max1.val+max2.val);
    for(int i=0;i<n;++i){
        a[i] = -a[i];
    }
    s max3 = dp(max1.left,max1.right);
    if((max1.right - max1.left) - (max3.right - max3.left) >= 2){
        ans = max(ans,max1.val+max3.val);
    }
    printf("%d\n",ans);
    return 0;
}