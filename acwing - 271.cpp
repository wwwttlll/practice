#include<bits/stdc++.h>
using namespace std;
int k;
int n[10];
long long f[31][31][31][31][31];
int main(){
    while(scanf("%d",&k)&& k != 0){
        memset(n,0,sizeof n);
        for(int i = 1; i <= k; i++){
            scanf("%d",&n[i]);
        }
        memset(f,0,sizeof f);
        f[0][0][0][0][0] = 1;
        for(int a = 0; a <= n[1]; a++){
            for(int b = 0; b <=min(n[2] , a) ; b++){
                for(int c = 0; c <= min(n[3] , b); c++){
                    for(int d = 0; d <= min(n[4] , c); d++){
                        for(int e = 0; e <= min(n[5] , d); e++){
                            long long &sum = f[a][b][c][d][e];
                            if(a && a - 1 >= b)sum += f[a-1][b][c][d][e];
                            if(b && b - 1 >= c)sum += f[a][b-1][c][d][e];
                            if(c && c - 1 >= d)sum += f[a][b][c-1][d][e];
                            if(d && d - 1 >= e)sum += f[a][b][c][d-1][e];
                            if(e)sum += f[a][b][c][d][e-1];
                        }
                    }
                }

            }
        }
        cout << f[n[1]][n[2]][n[3]][n[4]][n[5]]<<endl;
    }
}