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
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&color[i]);
	for(int i=1;i<=n;i++)
        scanf("%d",&len[i]);
    printf("%d\n",dfs(1,n,0));
}