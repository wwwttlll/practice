#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
const int p = 998244353;
int n;
int a[N];
long long f[N][20];
int main(){
    cin >> n;
    for(int i = 1; i <= n ; i++){
        cin >> a[i];
    }
    memset(f,0,sizeof f);
    f[1][a[1]] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 9 ; j++){
            f[i][j] %= p;
            f[i + 1][j * a[i + 1] % 10] += f[i][j];
            f[i + 1][(j + a[i + 1]) % 10] += f[i][j];
            f[i + 1][j * a[i + 1] % 10] %= p ;
            f[i + 1][(j + a[i + 1]) % 10] %= p ;
        }
    }
    for(int i = 0; i <= 9; i++){
        cout << f[n][i] << endl;
    }
}