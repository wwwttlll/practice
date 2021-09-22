#include<bits/stdc++.h>
using namespace std;
const int N = 3011;
int n;
int a[N], b[N];
int f[N][N];
int main(){ 
    //ios::sync_with_stdio(false);
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    for(int j = 1; j <= n; j++){
        scanf("%d",&b[j]);
    }
    // f[i][j] = max (f[i][j-1],f[j-1][i]) ?a==b:f[i-1][j-1] + 1
    //f[i] >
    for(int i = 1; i <= n; i++){
        int mav = 1;
        for(int j = 1; j <= n; j++){
            f[i][j] = f[i - 1][j];
            //f[i][j] =max(f[i][j],max (f[i][j-1],f[j-1][i]) ) ;
            if(a[i] == b[j]){
                f[i][j] = max(f[i][j],mav);
            }
            if(b[j] < a[i])
                mav = max(mav,f[i - 1][j] + 1);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max (ans,f[n][i]);
    }
    printf("%d\n",ans);
}