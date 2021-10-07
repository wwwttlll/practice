#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 +11;
int v[N];
int a[N];
void prime(int n){
    memset(v,0,sizeof v);
    v[1] = 1;
    for(int i = 2; i <= n; i++){
        if(v[i])continue;
        //cout << i << endl;
        for(int j = 2; j <= n / i; j++){
            v[i * j] = 1;
        }
    }
}
int main(){
    //ios::sync_with_stdio(false);
    prime(N);
    int t;
    cin >> t ;
    for(int i = 1; i <= N; i++){
        a[i] = a[i - 1];
        if(v[i] == 0){
            a[i]++ ;
        }
    }
    while(t--){
        int l,r;
        cin >> l >> r;
        cout << a[r] - a[l-1] << endl;
    }
    return 0;
}