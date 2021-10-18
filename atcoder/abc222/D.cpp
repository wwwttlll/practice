#include<bits/stdc++.h>
using namespace std;
int n;
int a[3011],b[3011];
int f[3011][3011];
const int p = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    int m = 3000;
    f[1][0] = 1;
    //1 0 1
    //1 1 1 2 1 1 3 1 1
    //1 2 1 2 2 2 3 2 3
    //1 3 1 2 3 1 3 3 4
    //
    for(int i = 1; i <= n + 1; i++){
        for(int j = 0; j <= m; j++){
            f[i][j + 1] += f[i][j]; 
            f[i][j + 1] %= p;
        }
        if(i != n + 1){
            for(int j = a[i]; j <= b[i]; j++){
                f[i + 1][j] += f[i][j];
                f[i + 1][j] %= p;
            }
        }
    }

    cout << f[n + 1][m] % p << endl;
    return 0;
}