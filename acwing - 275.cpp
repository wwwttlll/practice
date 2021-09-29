#include<bits/stdc++.h>
using namespace std;
int n,m;
int mp[100][100];
int f[200][100][100];
int main(){
    //ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mp[i][j];
        }
    }
    //i,l - i  <- i-1,l-1||i,l-1  j,l-j <- j-1,l-j j,l-j-1
    for(int k = 2 ; k <= n + m; k++){
        for(int i = 1; i <= n && i < k ; i++){
            for(int j = 1; j <= n && j < k; j++){
                if(i == j)continue;
                f[k][i][j] = max( max(f[k - 1][i - 1][j],f[k - 1][i - 1][j - 1]) , max(f[k - 1][i][j],f[k - 1][i][j - 1]) ) + mp[i][k-i] + mp[j][k-j];
                //cout << i << " " << j << " "<<f[k][i][j]<<endl;
            }
        }
    }
    cout << f[n+m][n][n - 1] << endl;
}