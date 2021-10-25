#include<bits/stdc++.h>
using namespace std;
int n;
int f[200][200];
int a[200];
char c[200];
int minn[200][200];
int maxn[200][200];
int ans;
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> c[i] >> a[i];
        c[i+n] = c[i];
        a[i + n] = a[i];
    }
    memset(maxn,128,sizeof(maxn));//可能是负的
    memset(minn,0x3f,sizeof(minn));
    for(int i = 1; i <= 2*n; i++){
        maxn[i][i] = minn[i][i] = a[i];
    }

    for(int i = 1; i <= n; i++){
        for(int l = 1;l + i <= 2*n; l++){
            int r = l + i;
            for(int j = l; j < r; j++){
                if(c[j+1] == 't'){
                    maxn[l][r] = max(maxn[l][r],maxn[l][j] + maxn[j+1][r]);
                    minn[l][r] = min(minn[l][r],minn[l][j] + minn[j+1][r]);
                }else{
                    maxn[l][r] = max(maxn[l][r],maxn[l][j] * maxn[j+1][r]);
                    maxn[l][r] = max(maxn[l][r],minn[l][j] * minn[j+1][r]);
                    minn[l][r] = min(minn[l][r],minn[l][j] * minn[j+1][r]);
                    minn[l][r] = min(minn[l][r],maxn[l][j] * minn[j+1][r]);
                    minn[l][r] = min(minn[l][r],minn[l][j] * maxn[j+1][r]);
                } 
            }
        }
    }
    for(int i = 1; i <= n; i++){
        ans = max(ans,maxn[i][i+n-1]);
    }
    cout << ans << endl;
    for(int i = 1; i <= n; i++){
        if(ans == maxn[i][i+n-1]){
            cout << i << " ";
        }
    }
    return 0;
}