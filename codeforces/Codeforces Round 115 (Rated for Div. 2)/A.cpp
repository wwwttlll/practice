#include<bits/stdc++.h>
using namespace std;
int t;
char a[40][1000];
int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        int n;
        cin >> n;
        for(int i = 1; i <= 2; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }
        if((a[1][1] == '1' )|| (a[2][n] == '1')){
            cout << "NO" << endl;
            continue;
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(a[1][i] == '0' || a[2][i] == '0'){
                cnt ++;
            }
        }
        if(cnt == n){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}