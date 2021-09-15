#include<bits/stdc++.h>
using namespace std;
map <int ,map<int ,int > >mp;
int  x[5000],y[5000];
int n;
int ans;
int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d",&x[i],&y[i]);
        mp[x[i]][y[i]] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(x[i]!=x[j]&&y[i]!=y[j]){
                if(i != j && mp[x[i]][y[j]] == 1 && mp[x[j]][y[i]] == 1){
                    ans ++;
                }
            }
        }
    }
    ans /= 4;
    printf("%d",ans);
    return 0;
}