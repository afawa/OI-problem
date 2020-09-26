#include <bits/stdc++.h>
using namespace std;
int n,a[200005],leftFirst[200005],rightFirst[200005];
unordered_map<int,int> mp;
bool check(int left,int right){
    if(left >= right)
        return true;
    int leftPoint = left,rightPoint = right;
    while(rightPoint >= leftPoint){
        if(leftFirst[rightPoint]<left && rightFirst[rightPoint]>right){
            if(check(left,rightPoint-1) && check(rightPoint+1,right))
                return true;
        }
        rightPoint--;
        if(leftFirst[leftPoint]<left && rightFirst[leftPoint]>right){
            if(check(left,leftPoint-1) && check(leftPoint+1,right))
                return true;
        }
        leftPoint++;
    }
    return 0;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
            leftFirst[i] = -1;
            rightFirst[i] = n;
        }
        mp.clear();
        for(int i=0;i<n;++i){
            if(mp.count(a[i])){
                leftFirst[i] = mp[a[i]];
                rightFirst[mp[a[i]]] = i;
            }
            mp[a[i]] = i;
        }
        puts(check(0,n-1) ? "non-boring" : "boring");
    }
    return 0;
}