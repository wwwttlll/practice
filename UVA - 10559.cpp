//dp初步区间dp 
//算法竞赛入门经典 
#include<bits/stdc++.h>
using namespace std;
int t,n;
int color[300];
int len[300];
int f[400][400][500];
int dfs(int l,int r,int k){
    if(f[l][r][k]){
        return f[l][r][k];
    }
    if(l == r){
        return (len[r] + k) *(len[r] + k);
    }
    f[l][r][k] = dfs(l,r-1,0) + (len[r] + k) * (len[r] + k);
    for(int i = l; i < r - 1; i++){
        if(color[i] == color[r]){
            f[l][r][k] = max(f[l][r][k], dfs(i + 1,r - 1,0) + dfs(l,i,(len[r] + k)));
        }
    }
    return f[l][r][k];

}
int main(){
    scanf("%d",&t);
    for(int o = 1; o <= t; o++){
        memset(len,0,sizeof len);
        memset(color,0,sizeof color);
        memset(f,0,sizeof f);
        scanf("%d",&n);
        int cnt = 0;
        int last = -1;
        for(int i = 1; i <= n; i++){
            int x;
            scanf("%d",&x);
            if(x == last){
                len[cnt]++;
            }else{
                color[++cnt] = x;
                len[cnt]++;
            }
            last = x; 
        }
        printf("Case %d: %d\n",o,dfs(1,cnt,0));
    }
}