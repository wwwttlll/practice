#include<bits/stdc++.h>
using namespace std;
#define int long long
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int t,n,k;
signed main(){
    ios::sync_with_stdio(false);
    t = read();
    while(t--){
        int ans = 0;
        n = read();
        for(int i = 1; i <= n; i++){
            k = read();
            ans = max(ans, k - i);
        }
        cout << ans << endl;
    }
    return 0;
}