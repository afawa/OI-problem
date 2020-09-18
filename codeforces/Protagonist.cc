#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int p,f,cnts,cntw,s,w;
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&p,&f);
    scanf("%d%d%d%d",&cnts,&cntw,&s,&w);
    if(f>p){
      swap(p,f);
    }
    if(s>w){
      swap(s,w);
      swap(cnts,cntw);
    }
    int ans=0;
    int tmp = min(cnts,p/s);
    cnts -= tmp;
    p -= tmp*s;
    ans += tmp;
    int tmp1 = min(cnts,f/s);
    cnts -= tmp1;
    f -= tmp1*s;
    ans += tmp1;
    if(cnts>0){
      printf("%d\n",ans);
    }else{
      if(tmp == 0){
        printf("0\n");
      }else{
        int tmp0 = min(cntw,p/w);
        cntw -= tmp0;
        p -= tmp0 *w;
        ans+=tmp0;
        int tmp2 = min(cntw,f/w);
        cntw -= tmp2;
        f -= tmp2 * w;
        ans+=tmp2;
        if(cntw==0){
          printf("%d\n",ans);
        }else{
          if(p+f>=w){
            //printf("%d %d %d %d\n",tmp,tmp0,tmp1,tmp2);
            if(w!=s){
              int b = f + min(p/(w-s),min(tmp,tmp2))*(w-s);
              int t1=tmp,t2 = min(tmp0,tmp1),a=p;
              if(s<=(w-s)){
                a += min(t1,f/s)*s;
                f -= min(t1,f/s)*s;
                a += min(t2,f/(w-s))*(w-s);
              }else{
                a += min(t2,f/(w-s))*(w-s);
                f -= min(t2,f/(w-s))*(w-s);
                a += min(t1,f/s)*s;
              }
              int ma = max(a,b);
              printf("%d\n",ans+min(cntw,ma/w));
            }
            else{
              printf("%d\n",ans);
            }
          }else{
            printf("%d\n",ans);
          }
        }
      }
    }
  }
  return 0;
}