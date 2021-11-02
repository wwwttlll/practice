#include<bits/stdc++.h>
using namespace std;
#define int long long
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int v[100];
string s[100];
int n,m;
string ans;
void dfs(int t,string ss){
    if(t == m){
        ans = min(ans,ss);
        return;
    }
    if(ans < ss)return;
    for(int i = 1; i <= n; i++){
        if(v[i] == 0){
            v[i] = 1;
            string sss = ss + s[i];
            dfs(t+1,sss);
            v[i] = 0;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    n = read(); m = read();
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    int num = 100000;
    while(num--){
        ans += 'z';
    }
    sort(s+1,s+1+n);
    for(int i = 1; i <= n; i++){
        v[i] = 1;
        dfs(1,s[i]);
        v[i] = 0;
    }
    cout << ans << endl;
    /*sort(a + 1, a + 1 + n, cmp);
    string ss;
    for(int i = 1; i <= m; i++){
        ss += a[i].s;
    }
    cout << ss << endl;*/
    return 0;
}