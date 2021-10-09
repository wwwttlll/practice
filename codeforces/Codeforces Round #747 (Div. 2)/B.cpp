#include<bits/stdc++.h>
using namespace std;
const int p = 1e9 + 7;
long long pw(long long x,long long y){
  long long re=1%p;
  for(;y ; y >>= 1){
    if(y & 1){
      re = re * x % p;
    }
    x = x * x % p;
  }
  return re;
}
int a[10000];
void nonsence(int l, int r){
	int re = a[l];
	for(int i = l; i < r; ++i){
		a[i] = a[i + 1];
	}
	a[r] = re;
}
int t;
int n,k;

int ans = 0;
int main(){
    ios::sync_with_stdio(false);
    a[0] = 1;
    for(int i = 1; i <= 30; i++){
        a[i] = a[i-1] * 2;
    }
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n >> k;
        while(k){
            int fuck = lower_bound(a,a+30,k) - a;
            if(a[fuck] == k){
                k -= a[fuck];
                ans += pw(n,fuck);
                ans %= p;
            }else{
                fuck--;
                k -= a[fuck];
                ans += pw(n,fuck);
                ans %= p;
            }
        }
        cout << ans << endl;
    }
    return 0;
}