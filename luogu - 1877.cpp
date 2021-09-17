#include<bits/stdc++.h>
using namespace std;
int n,b,m;
int c[1011];
int f[101][2011];
int ans = -1;
/*
int dfs(int x,int d){
    int ans = 0;
    if(x > n)return d;
    if(d + c[x] > m){
        ans = max(ans,dfs(x + 1, d - c[x]));
    }
    else if(d < c[x]){
        ans = max(ans,dfs(x + 1,d + c[x]));
    }else{
        ans = max(ans,dfs(x + 1, d - c[x]));
        ans = max(ans,dfs(x + 1,d + c[x]));
    }
    return ans;
}*/
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> b >> m;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    memset(f,0,sizeof f);
    f[0][b] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m ;j++){
            if(f[i - 1][j] && j + c[i] <= m){
                f[i][j + c[i]] = 1;
            }
            if(f[i - 1][j] && j - c[i] >= 0){
                f[i][j - c[i]] = 1;
            }
        }
    }
    for(int j = m; j ; j--){
        if(f[n][j] == 1){
            ans = j;
            break;
        }
    }
    cout << ans <<endl;
}