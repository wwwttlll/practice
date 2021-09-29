#include<bits/stdc++.h>
using namespace std;
long long a[100011];
long long f[100011];
int n;
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1 ; i <= n - 1; i++){
        cin >> a[i];
    }
    memset(f,0x80,sizeof f);//负数
    //cout << f[0] << endl;
    f[0] = 0;
    for(int i = 1 ; i <= n - 1; i++){
        for(int j = i ; j <= n -2 ; j++){
            f[j] = max(f[j] , f[j - i] + a[i + 1] - a[1]);
        }
    }
    long long ans = f[n - 2] + n * a[1]; 
    cout << ans << endl;
    return 0;
}