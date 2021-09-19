#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
const int N = 1e5 + 11;
int n,m;
int v[200],num[200],vv[200];
int g[N];
int f[N];
int main(){
    while(scanf("%d%d",&n,&m)&&n != 0){
        int cnt = 0;
        memset(f,0,sizeof f);
        for(int i = 1; i <= n; i++){
            v[i] = read();
            //f[vv[i]] = 1;
        }
        for(int i = 1; i <= n; i++){
            num[i] = read();
        }
        /*for(int i = 1; i <= n; i++){
            while(num[i]--){
                v[++cnt] = vv[i];
            }
        }*/
        /*for(int i = 1; i <= cnt; i ++){
            cout << v[i] <<endl;
        }*/
        f[0] = 1;
        for(int i = 1; i <= n; i++){
            memset(g,0,sizeof g);
            for(int j = v[i]; j <= m ; j--){
                if(!f[j] && f[j- v[i]] && g[j - v[i]] < num[i]){
                    f[j] |= f[j - v[i]];
                    g[j] = g[j - v[i]] + 1;    
                }
                
            }
        }
        int ans = 0;
        for(int i = 1; i <= m; i++){
            ans += f[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}