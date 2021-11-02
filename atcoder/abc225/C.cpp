#include<bits/stdc++.h>
using namespace std;
#define int long long
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
const int N = 1e4 + 11;
int n,m;
int mp[N][10];
signed main(){
    ios::sync_with_stdio(false);
    n = read();m=read();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m ; j++){
            mp[i][j] = read();
        }
    }
    int f = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m ; j++){
            if((mp[i][j] + 1 != mp[i][j + 1]&& j != m) || (mp[i][j] + 7 != mp[i+1][j] &&i != n)){
                f = 0;
                break;
            }
            if(mp[i][j] % 7 == 0 && j != m){
                f = 0;
                break;
            }
        }
        if(f == 0)break;
    }
    if(f == 1)puts("Yes");
    else {
        puts("No");
    }
    return 0;
}