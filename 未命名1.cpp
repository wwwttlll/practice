#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int a[111][2000]={0};
        map<int,int>m;
        for(int i = 1; i <= n; i++){
            cin >> a[0][i];
            m[a[0][i]] ++;
        }
        int tt = 100;
        for(int i = 1; i <= tt; i++){
            for(int j = 1; j <= n; j++){
                a[i][j] = m[a[i-1][j]];
            }
            m.clear();
            for(int j = 1; j <= n; j++){
                m[a[i][j]]++;
            }
        }
        int q;
        cin >> q;
        while(q--){
            int x,k;
            cin >> x >> k;
            if(k > 100)cout << a[100][x] << endl;
            else cout << a[k][x] << endl;
        }
    }
    return 0;
}
