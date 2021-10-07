#include<bits/stdc++.h>
using namespace std;
int mp[411][411];
int n,m;
int ans = 0x3f3f3f3f;
int up[411][411];
int down[411][411];
int inside[411][411];
bool in(int x,int y){
    return 1 <= x&& x <= n&& 1 <= y && y <= m;
}
int main(){
    //ios::sync_with_stdio(false);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d",&mp[i][j]);
        }
    }
    
    int ans = 0x3f;
    for(int a = 3; a <= n - 4; a++){
        for(int b = 2; b <= n - 2; b++){
            memset(up,0x3f,sizeof up);
            memset(down,0x3f,sizeof down);
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    int x = a,y = b;
                    if(!in(i + a + 1,j)||!in(i,j + b + 1)){
                        continue;
                    }
                    int sum = 0;
                    while(x--){
                        if(mp[i + x][j] == 1){
                            sum ++;
                        }
                    }
                    while(y--){
                        if(mp[i][j + y] == 1){
                            sum ++;
                        }
                    }
                    up[i][j] = min(up[i][j],sum);
                }
            }
            for(int i = n; i >= 1 ; i--){
                for(int j = m; j >= 1; j--){
                    int x = a,y = b;
                    if(!in(i - a - 1,j)||!in(i,j - b - 1))continue;
                    int sum = 0;
                    while(x--){
                        if(mp[i - x][j] == 1){
                            sum ++;
                        }
                    }
                    while(y--){
                        mp[i][j - y] == 1;
                        sum ++;
                    }
                    down[i][j] = min(down[i][j],sum);
                }
            }
            for(int i = 2; i <= n-1; i++){
                for(int j = 2; j <= m - 1; j++){
                    int x = a,y = b;
                    while(x -- ){

                    }
                }
            }
        }
    }
    
    return 0;
}