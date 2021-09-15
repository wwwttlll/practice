#include<bits/stdc++.h>
using namespace std;
const int N = 400;
int n;
char s[N][N],t[N][N];
void tran(char s[N][N]){
    int x,y;
    char ss[N][N];
    for(int i = 0; i < n; i++){
        bool flag = 0;
        for(int j = 0; j < n; j++){
            if(s[i][j] == '#'){
                flag = 1;
                x = i;
                break;
            }
        }
        if(flag ) break;
    }
    for(int j = 0; j < n; j++){
        bool flag=0;
        for(int i = 0; i < n; i++){
            if(s[i][j] == '#'){
                flag = 1;
                y = j;
                break;
            }
        }
        if(flag ){
            break;
        }
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ss[i][j] = s[i + x][j + y];
        }
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            s[i][j] = ss[i][j];
        }
    }
}
void turn(){
    char ss[N][N];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ss[j][n - i - 1] = s[i][j];
        }
    }
    memcpy(s , ss, sizeof s);
}
int main(){
    ios::sync_with_stdio(false);
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%s",&s[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%s",&t[i]);
    }
    tran(t);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
        }
    }
}