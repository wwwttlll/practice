#include<bits/stdc++.h>
using namespace std;
const int N = 2011;
int n;
int a[N],b[N];
int f[N][N];
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int work(){
    for(int i = 1 ; i <= n ; i++){
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for(int i = 1; i <= n; i ++){
        int minn = 1e9;
        for(int j = 1; j <= n; j ++){
            minn = min (minn, f[i - 1][j]);
            f[i][j] = minn + abs(a[i] - b[j]);
        }
    }
    int re = 1e9 + 11;
    for(int i = 1; i <= n; i++){
        re = min (re,f[n][i]);
    }
    return re;
}
int main(){
    n = read();
    for(int i = 1; i <= n; i ++){
        a[i] = read();
    }
    int ans = work();
    reverse(a + 1,a + 1 + n);
    ans = min (ans , work());
    cout << ans << endl;
}