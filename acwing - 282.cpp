#include<bits/stdc++.h>
using namespace std;
int a[311];
int f[311][311];
int s[311];
int n;
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n ;i++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
        //cout << s[i] << endl;
    }

    for(int i = 2; i <= n; i++){
        for(int l = 1; l + i - 1 <= n; l++){
            int r = l + i - 1;
            f[l][r] = 1e9;
            for(int j = l; j < r; j++){
                f[l][r] = min(f[l][r], f[l][j] + f[j + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}