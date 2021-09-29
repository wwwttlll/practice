#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 + 11;
int n, p ;
int a[N];
int cha[N];
int main(){
    ios::sync_with_stdio(false);
    cin >> n >>p;
    for(int  i = 1; i <= n; i++){
        cin >> a[i];
        cha[i] = a[i] - a[i-1];
    }
    while(p--){
        int l,r,c;
        cin >>l >> r >> c;
        cha[l] += c;
        cha[r + 1] -= c;
    }
    int ans = 0x3f3f3f3f;
    for(int i = 1; i <= n; i ++){
        a[i] = cha[i] += a[i - 1];
        ans = min (ans , a[i]);
    }
    cout << ans <<endl;

}