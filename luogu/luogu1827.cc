#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
string a,b;
struct node{
    char c;
    node * left,*right;
};
node Tree[100];
int cnt=0;
node * build(int posL,int posR,int pos,int num){
    if(num==0){
        return NULL;
    }
    int res;
    for(res=posL;res<=posR;++res){
        if(a[res] == b[pos]){
            break;
        }
    }
    node * tmp = Tree+cnt;
    ++cnt;
    tmp->c = a[res];
    tmp->left = build(posL,res-1,pos+1,res-posL);
    tmp->right = build(res+1,posR,pos+res-posL+1,posR-res);
    return tmp;
}
void print(node * now){
    if(now==NULL){
        return;
    }
    print(now->left);
    print(now->right);
    printf("%c",now->c);
}
int main(){
    cin>>a>>b;
    node * root = build(0,a.size()-1,0,b.size());
    print(root);
    printf("\n");
    return 0;
}