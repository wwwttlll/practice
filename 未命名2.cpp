#include<bits/stdc++.h>
using namespace std;
static int Rank = 0;
int n = 44;
int mp[1000][1000];
void dfs(int x,int y){
    cout << x <<" "<< y << endl;
    mp[x][y] = 1;
    int l[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
    
    //cout << x << " " <<  y << endl;
    for (int i = 0; i < 4; i++) {
		int r = rand() % 4;
		int temp = l[0][0];
		l[0][0] = l[r][0];
		l[r][0] = temp;
		temp = l[0][1];
		l[0][1] = l[r][1];
		l[r][1] = temp;
	}
    for(int i = 0; i < 4; i++){
        int dx = x;
        int dy = y;
        //if(dx <= 0 || dy <= 0 || dx > n || dy > n) continue;
        int step = 1 + rand( ) % 3;
        while(step){
            dx += l[i][0];
            dy += l[i][1];
            //cout << dx << " " << dy << " " << x << " " << y <<endl; 
            if(mp[dx][dy] == 1)break;
            int cnt = 0;
			for (int j = dx - 1; j < dx + 2; j++) {
				for (int k = dy - 1; k < dy + 2; k++) {
					//abs(j - dx) + abs(k - dy) == 1 ???????????????
					if (abs(j - dx) + abs(k - dy) == 1 && mp[j][k] == 1) {
						cnt++;
					}
				}
			}
            if(cnt > 1)break;  
            //cout << dx << " " << dy << endl;
            step--;
            mp[dx][dy] = 1;
        }
        if(step <= 0)
            dfs(dx,dy);
    }
}
int main(){
    srand((unsigned)time(0));
    //freopen("maze.txt","w",stdout);
    n = 20;
    for (int i = 0; i < n; i++){
		mp[i][0] = 1;
		mp[0][i] = 1;
		mp[i][n - 1] = 1;
		mp[n - 1][i] = 1;
	}
    dfs(2,2);
    mp[2][1] = 1;
    /*for(int i = 0; i <= n; i++){
        for (int j = 0; j <= n ; j++){
            cout << mp[i][j];
        }
        cout << endl;
    }*/
    //cout << char(A1F5);
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n ; j++){
            if(mp[i][j] == 1){
                cout << " ";
            }
            else cout <<"?";
        }
        cout << endl;
    }
}
