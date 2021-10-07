#include<bits/stdc++.h>
using namespace std;
int n,vv;
int v[100011],w[100011];
int f[100011];
int main(){
    ios::sync_with_stdio(0);
    cin >> n >> vv;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int x ,y ,z;
        cin >> x >> y >> z;
        for(int k = 1; k <= z; k*=2){
            z -= k;
            v[++cnt] = x * k;
            w[cnt] = y * k;
        }
        if(z){//注意：减完可能剩余 因为2是从小向大枚举
           v[++cnt] = x * z;
            w[cnt] = y * z; 
        }
    }
    for(int i = 1; i <= cnt; i++){
        for(int j = vv; j >= v[i]; j--){
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[vv] << endl;
}