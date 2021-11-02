#include<bits/stdc++.h>
using namespace std;
#define int long long
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int a[20];
int n,k,t;
signed main(){
    ios::sync_with_stdio(false);
    t=read();
    while(t--){
        n = read();k = read();
        k++;
        for(int i = 1; i <= n; i++){
            int x;
            x = read();
            a[i] = 1;
            while(x--){
                a[i] *= 10;
            }
        }
        int ans = 0;
        int p = 0;
        for(int i = 1; i < n; i++){
            int x = a[i + 1] / a[i] - 1;
            if(k >= x){
                k -= x;
                ans += x * a[i];
            }else{
                p = i;
                ans += k * a[i];
                k = 0;
            }
        }
        if(!p){
            ans += k * a[n];
        }
        cout << ans << endl;
    }
    return 0;
}