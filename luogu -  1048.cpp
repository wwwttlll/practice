#include<bits/stdc++.h>
using namespace std;
int t ,m;
int f[1011];
int w[1111],tt[1111];
int main(){
    ios::sync_with_stdio(false);
    cin >> t >> m;
    //cout << t << " " << m <<endl;
    for(int i = 1; i <= m; i++){
        cin >> tt[i] >> w[i];
        //cout << i <<endl;
    }
    for(int i = 1; i <= m; i++){
        for(int j = t; j >= tt[i]; j--){
            f[j] = max(f[j - tt[i]] + w[i], f[j]);
        }
    }
    cout << f[t] <<endl;
}