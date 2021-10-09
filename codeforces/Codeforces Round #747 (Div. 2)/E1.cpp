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
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    unsigned long long sum = 0;
    sum = 2*(pw(2,n) - 1);
    cout << (6*pw(4,sum)%p)<<endl;
    return 0;
}