#include <bits/stdc++.h>
using namespace std;
int n,k,p[50005];
int rightPos[50005],numEle[50005];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d",p+i);
    }
    sort(p,p+n);
    int left=0,right=0;
    while(left<n){   
        while(right<n && p[left] + k >= p[right]){
            ++right;
        }
        rightPos[left] = right;
        left++;
    }
    for(int i=0;i<n;++i){
        numEle[i] = rightPos[i] - i;
    }
    for(int i=n-2;i>=0;--i){
        numEle[i] = max(numEle[i],numEle[i+1]);
    }
    int ans = -1;
    for(int i=0;i<n;++i){
        ans = max(ans,rightPos[i] - i + numEle[rightPos[i]]);
    }
    printf("%d\n",ans);
    return 0;
}