#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 755 + 10
using namespace std;
int A[MAXN][MAXN];
int n;
struct Table{
    int x;
    int y;
    int cal; //表示A[i]+B[j]
    bool operator<(const Table &x) const{
        return cal > x.cal;
    }
};
void merge(int A[], int B[]){
    priority_queue<Table> T;
    int C[MAXN];
    for (int i = 0; i < n; i++){
        Table nt = (Table){0, i, A[0] + B[i]};
        T.push(nt);
    }
    int cnt = 0;
    while (cnt < n){
        Table nt = T.top();
        T.pop();
        C[cnt++] = nt.cal;
        if (nt.x + 1 >= n)
            continue;
        nt = (Table){nt.x + 1, nt.y, A[nt.x + 1] + B[nt.y]};
        T.push(nt);
    }
    for (int i = 0; i < n; i++)
        A[i] = C[i];
}
int main(){
    while (cin >> n){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                cin >> A[i][j];
            sort(A[i], A[i] + n);
        }
        for (int i = 1; i < n; i++)
            merge(A[0], A[i]);
        cout << A[0][0];
        for (int i = 1; i < n; i++)
            cout << " " << A[0][i];
        cout << endl;
    }
    return 0;
}