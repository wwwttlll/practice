#include<bits/stdc++.h>
using namespace std;
const int inf = -1e17;
int n,m;
int mp[1010][1010];
int f[1011][1010][4];
int main(){
    //ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mp[i][j];
            for(int k = 1; k <= 3; k ++){
                f[i][j][k] = inf;
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        f[i][1][1] = f[i - 1][1][1] + a[1][i]; 
    }
}