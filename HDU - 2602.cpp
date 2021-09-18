#include<bits/stdc++.h>
using namespace std;
int t;
int n,v;
int w[2000],vv[2000];
int f[2000];
int main(){
    scanf("%d",&t);
    while(t--){
        memset(f,0,sizeof f);
        scanf("%d%d",&n,&v);
        for(int i = 1; i <= n; i++)scanf("%d",&vv[i]);
        for(int i = 1; i <= n; i++)scanf("%d",&w[i]);
        for(int i = 1; i <= n; ++i){
            for(int j = v; j >= w[i]; j--){
                f[j] = max(f[j], f[j - w[i]] + vv[i]);
            }
        }
        printf("%d\n",f[v]);
    }
}