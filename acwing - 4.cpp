#include<bits/stdc++.h>
using namespace std;
int v[10001],w[10001];
int f[10001];
int n,vv;
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> vv;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int x , y, z;
        cin >> x >> y >> z;
        while(z--){
            v[++cnt] = x;
            w[cnt ] = y;
        }
    }
    for(int i = 1; i <= cnt; i++){
        for(int j = vv; j >= v[i]; j--){
            f[j] = max(f[j],f[j - v[i]] + w[i]);
        }
    }
    cout << f[vv] << endl;
    return 0;
}