#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
char mp[20][20];
int vis[20][20];
int flag = 1;
bool in(int x,int y){
    return x >= 1&& x <=n && y >= 1&& y <=m;
}
int left(int x,int y){
    int cnt = 0;
    while(x&&in(x,y)&&mp[x - 1][y - 1] == '*'){
        cnt ++;
        y--;
        x--;
        if(in(x,y)&&mp[x][y] != '*'){
            break;
        }
    }
    return cnt;
}
int right(int x,int y){
    int cnt = 0;
    while(x &&in(x,y)&&mp[x - 1][y + 1] == '*'){
        cnt ++;
        y++;
        x--;
        if(in(x,y)&&mp[x][y] != '*'){
            break;
        }
    }
    return cnt;
}
int main(){
    cin >> t;
    while(t--){
        memset(vis ,0 ,sizeof vis);
        flag = 0;
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
            for(int j = 1 ; j <= m; j++){
                cin >> mp[i][j];
            }
        }
        for(int i = n; i >= 1 ; i--){
            for(int j = m; j >= 1; j--){
                if(mp[i][j] == '*' && vis[i][j] == 0 && i < k + 1){
                    flag = 1;
                    break;
                }
                if(mp[i][j] == '*' && i >= k + 1){
                    
                    //if(in(i-1,j-1))
                    int cnt = left(i,j);
                    //if(in(i-1,j+1));
                    cnt = min (cnt,right(i,j) );
                    if(cnt < k)continue;
                    vis [i][j] = 1;
                    for(int num = 1; num <= cnt ; num++){
                        vis[i - num][j - num] = 1;
                        vis[i - num][j + num] = 1;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(mp[i][j] == '*' &&vis[i][j] == 0){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                break;
            }
        }
        /*for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cout << vis[i][j];
            }
            cout << endl;
        }*/
        if(flag == 1)puts("NO");
        else{
            puts("YES");
        }
    }
}