#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[2000],b[2000];
int f[1001][1001];
int main(){
    cin >> n >> m >> a+1>> b + 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            f[i][j] = max (f[i][j - 1], f[i - 1][j]);
            if(a[i] == b[j]){
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    cout << f[n][m]<< endl;
}