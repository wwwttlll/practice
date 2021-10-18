#include<bits/stdc++.h>
using namespace std;
int t;
int a[10000];
int b[10000];
inline int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n ;i++){
            cin >> a[i];
            b[i] = a[i] - a[i-1];
            if(b[i] < 0)b[i] = -b[i];
        }
        int flag = 0;
        for(int i = 1; i <= n; i++){
            if(a[i]!=a[1]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << -1 << endl;
            continue;
        }int ans = b[2];
        for(int i = 2; i <= n; i++){
            if(b[i]){
                ans = gcd(ans,b[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}