#include<bits/stdc++.h>
using namespace std;
int l,n;
int c[211][211];
int q[1011];
int f[1011][211][211];
int main(){
    scanf("%d%d",&l,&n);
    for(int i = 1 ; i <= l; i ++){
        for(int j = 1; j <= l; j ++){
            scanf("%d",&c[i][j]);
        }
    }
    for(int i = 1; i <= n; i ++){
        scanf("%d",&q[i]);
    }
    q[0] = 3;
    memset(f,0x3f,sizeof f);
    f[0][1][2] = 0;
    for(int i = 0; i < n; i ++){
        for(int x = 1; x <= l; x++){
            for(int y = 1; y <= l ; y++){
                int z = q[i];
                int v = f[i][x][y];
                int u = q[i + 1];
                if(x == y || y == z|| x == z)continue;
                f[i + 1][x][y] = min(v + c[z][u],f[i + 1][x][y]);
                f[i + 1][y][z] = min(v + c[x][u],f[i + 1][y][z]);
                f[i + 1][z][x] = min(v + c[y][u],f[i + 1][z][x]);
            }
        }
    }
    int ans = 1e9 +7;
    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= l; j++){
            int z = q[n];
            if(i==j||j==z||i==z)continue;
            ans = min(f[n][i][j] ,ans); 
        }
    }
    cout << ans << endl;
    
}