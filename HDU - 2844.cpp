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
int f[N];
int main(){
    while(scanf("%d%d",&n,&m)&&n != 0){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            vv[i] = read();
            f[vv[i]] = 1;
            /*int x,y;
            scanf("%d%d",&x,&y);
            f[x] = 1;
            while(y--){
                v[++cnt] = x;
            }*/
        }
        for(int i = 1; i <= n; i++){
            num[i] = read();
        }
        for(int i = 1; i <= n; i++){
            while(num[i]--){
                v[++cnt] = vv[i];
            }
        }
        /*for(int i = 1; i <= cnt; i ++){
            cout << v[i] <<endl;
        }*/
        for(int i = 1; i <= cnt; i++){
            for(int j = m; j >= v[i] ; j--){
                if(f[j - v[i]]){
                    f[j] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= m; i++){
            if(f[i] == 1){
                ans ++;
            } 
        }
        printf("%d\n",ans);
    }
    return 0;
}