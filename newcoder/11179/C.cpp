#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 22;
int n,m;
int flag;
bool mp[10][N];
bool vis[10][N];
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
bool in(int x,int y){
    if(x >= 1 && x <=3 && y >=1 && y <= n){
        return 1;
    }else{
        return 0;
    }
}
void way(int x,int y){
    if(x == 3&& y == n){
        flag ++;
    }
    //cout << x << " " << y <<endl;
    vis [x][y] = 1;
    vis[3][n] = 0;
    if(in (x,y + 1)&&vis[x][y+1] != 1&&mp[x][y + 1] != 1){
        way(x,y + 1);
    }else if(in(x + 1,y)&&!vis[x + 1][y] && !mp[x + 1][y]){
        way(x+1,y);
    }
}
int main(){
    n = read(); m = read();
    for(int i = 1; i <= m; i++){
        int x,y;
        x = read();y = read();
        mp[x][y] = 1;
    }
    if(mp[1][2] == 1 || mp[2][1] == 1){
        puts("NO");
        return 0;
    }
    way(1,2);
    way(2,1);
    if(flag >= 2){
        puts("YES");
    }else{
        puts("NO");
    }
}