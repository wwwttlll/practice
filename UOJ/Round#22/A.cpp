#include<bits/stdc++.h>
using namespace std;
#define int long long
long long n,m,t;
long long a[3000050];
signed main(){
    scanf("%lld%lld%lld",&n,&m,&t);
    for(int i = 1; i <= n; i++){
        scanf("%lld",&a[i]);
    }long long ans = 0;
    long long div = pow(2,20);
    for(int i = 1; i <= m; i++){
        long long q;
        
        scanf("%lld",&q);
        q = q ^ (t *(ans / div) );
        ans = 0;
        for(int i = 1; i <= n; i++){
            ans ^= (a[i] + q);
        }
        printf("%lld\n",ans);
    }
    return 0;
}