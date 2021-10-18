#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
const int N = 4e5 + 11;
vector<int>a[N];
int d[N];
int du[N];
void dfs(int x,int fa){
    if(du[x] == 1){
        d[x] = 1;
        return;
    }
    for(int i = 0; i < a[x].size(); i++){
        if(a[x][i] == fa)continue;
        dfs(a[x][i],x);
        d[x] = min(d[a[x][i]] + 1,d[x]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n >> m;
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        memset(d,0x3f,sizeof d);
        memset(du,0,sizeof du);
        for(int i = 1; i < n; i++){
            int x,y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
            du[x] ++ ;
            du[y] ++ ;
        }
        for(int i = 1; i <= n ; i++){
            if(du[i] == 1){
                d[i] = 1;
            }
        }
        for(int i = 1; i <= n; i++){
            if(du[i] != 1){
                dfs(i,0);
                break;
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n ;i++){
            if(d[i] > m){
                cnt++;
            }
            a[i].clear();
        }
        cout << cnt << endl;
    }
    return 0;
}