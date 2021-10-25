#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;
}a[6011];
int f[6011],s[6011];
bool cmp(node a,node b){
    return a.z < b.z;
}
int F(int x){
    if(x == f[x]) return x;
    return f[x] = F(f[x]);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i < n; i++){
            cin >> a[i].x >> a[i].y >> a[i].z;
        }
        for(int i = 1; i <= n; i++){
            f[i] = i;
            s[i] = 1;
        }
        sort(a + 1, a + n, cmp);
        long long ans = 0;
        for(int i = 1; i < n; i++){
            int u = F(a[i].x);
            int v = F(a[i].y);
            int w = a[i].z;
            if(u!=v){
                f[u] = v;
                ans += (s[v] * s[u] - 1) * (w + 1);
                s[v] += s[u];
            }
        }
        cout << ans << endl;
    }
}