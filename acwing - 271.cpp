#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
long long f[32][32][32][32][32];
int main(){
    ios::sync_with_stdio(false);
    while(cin >> n && n != 0){
        memset(a,0,sizeof a);
        for(int i = 1; i <= n ; i ++){
            cin >> a[i];
        }
        memset(f,0,sizeof f);
        f[0][0][0][0][0] = 1;
        for(int i = 0; i <= a[1]; i ++){
            for(int j = 0 ; j <= min (i,a[2]) ; j++){
                for(int k = 0 ; k <= min(j,a[3]); k ++){
                    for(int l = 0 ; l <= min(k,a[4]) ; l++){
                        for(int m = 0; m <= min (m,a[5]);m++){
                            long long & sum = f[i][j][k][l][m];
                            if(i && i - 1 >= j)sum += f[i - 1][j][k][l][m];
                            if(j && j - 1 >= l)sum += f[i][j - 1][k][l][m];
                            if(k && k - 1 >= l)sum += f[i][j][k - 1][l][m];
                            if(l && l - 1 >= m)sum += f[i][j][k][l - 1][m];
                            if(m) sum += f[i][j][k][l][m - 1];
                        }
                    }
                }
            }
        }
        cout << f[a[1]][a[2]][a[3]][a[4]][a[5]] << endl;
    }
}