#include<bits/stdc++.h>
using namespace std;
int t;
int n;
const int p = 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    while(t --){
        cin >> n;
        n *= 2;
        long long ans = 1;
        for(long long  i = 1; i <= n; i++){
            if(i == 2)continue;
            ans = ans * i % p;
        }
        cout << ans << endl;
    }
    return 0;
}