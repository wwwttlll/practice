#include<bits/stdc++.h>
using namespace std;
int n;
int mp[1000][1000];
void dfs(int x,int y){
    //cout << x <<" "<< y << endl;
    mp[x][y] = 1;
    int l[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
    //cout << x << " " <<  y << endl;
    for (int i = 0; i < 4; i++) {
		int r1 = rand() % 4;
		int r2 = rand() % 4;
		swap(l[r1][0],l[r2][0]);
		swap(l[r1][1],l[r2][1]);
	}
    for(int i = 0; i < 4; i++){
        int dx = x;
        int dy = y;
        //if(dx <= 0 || dy <= 0 || dx > n || dy > n) continue;
        dx += l[i][0];
        dy += l[i][1];
        //cout << dx << " " << dy << " " << x << " " << y <<endl; 
        if(mp[dx][dy] == 1)continue;
        int cnt = 0;
		for (int j = dx - 1; j < dx + 2; j++) {
			for (int k = dy - 1; k < dy + 2; k++) {
				//abs(j - dx) + abs(k - dy) == 1 ???????????????
				if (abs(j - dx) + abs(k - dy) == 1 && mp[j][k] == 1) {
					cnt++;
				}
			}
		}
        if(cnt > 1)continue;  
        //cout << dx << " " << dy << endl;
        mp[dx][dy] = 1;
       	dfs(dx,dy);
    }
}
int main(){
    srand(time(0));
    //freopen("maze.txt","w",stdout);
    puts("�������Թ��߳�n��"); 
    cin >> n;
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
    for(int i = n - 3; i >= 1; i--){
        if(mp[i][n - 3] == 1){
            mp[i][n - 2] = 1;
            break;
        }
    }
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n ; j++){
            if(mp[i][j] == 1){
                cout << " ";
            }
            else cout <<"#";
        }
        cout << endl;
    }
    system("pause");
}
