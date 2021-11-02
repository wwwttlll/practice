#include<bits/stdc++.h>
using namespace std;
#define int long long
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
const int N = 1e6 + 11;
int n , q;
int f[N];
int son[N];
int ff;
void dfs(int x){
    if(f[x] != x){
       dfs(f[x]);
    }
    else ff = x;
}
int cnt = 0;
void put1(int x){
    cnt ++;
    //cout << x << " ";
    if(son[x]!=x){
        put1(son[x]);
    }
}
void put2(int x){
    //cnt ++;
    cout << x << " ";
    if(son[x]!=x){
        put2(son[x]);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    n = read(); q = read();
    for(int i = 1; i <= n; i++){
        f[i] = i;
        son[i] = i;
    }
    for(int i = 1; i <= q; i++){
        int x,y,z;
        x = read(); 
        if(x == 1){
            y = read(); z = read();
            son[y] = z;
            f[z] = y;
        }
        if(x == 2){
            y = read(); z = read();
            son[y] = y;
            f[z] = z;
        }
        if(x == 3){
            y = read();
            cnt = 0;
            ff = 0;
            dfs(y);
            put1(ff);
            cout << cnt << " ";
            put2(ff);
            cout << endl;
        }
    }
    return 0;
}