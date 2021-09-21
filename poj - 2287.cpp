#include<bits/stdc++.h>
using namespace std;
int n;
int a[3000],b[3000];
int f[3000][3000];

bool cmp(int x,int y){
    return x > y;
}
// t > k win f[i][j] = max(f[i-1][j]+200,f)
//t == k equal
//t < k lose f i j = maxf[i-1][j-1] 
int judge(int x,int y){
    if(x > y){
        return 200;
    }
    else if (x == y){
        return 0;
    }
    else return -200;
}
int main(){
    //ios::sync_with_stdio(false);
    while(cin >> n){
        int ans = -0x3f3f3f3f;
        memset(f,0,sizeof f);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> b[i];
        }
        sort(a + 1, a + 1 + n, cmp);
        sort(b + 1, b + 1 + n, cmp);
        for(int i = 1; i <= n; i++){
            f[i][i] = f[i - 1][i - 1] + judge(a[i],b[i]);
            f[i][0] = f[i - 1][0] + judge(a[i], b[n - i]);
            for(int j = 1; j < i; j++){
                //f[i][j] = max(f[i][] + judge(a[i],b[n - i]), f[i - 1][j] + judge(a[i],b[i]) );
                f[i][j] = max(f[i - 1][j - 1] + judge(a[i],b[j]), f[i - 1][j] + judge(a[i],b[n-i+j+1]));
            }
        }// f[i][j] = max f[i-1][j-1] +judge a[i],b[j] f[i-1][j] + judge a[i],b[n - i + j + 1]
        //10 5 2 3 8
        for(int i = 1; i <= n; i++){
            ans = max(ans,f[n][i]);
        }
        cout << ans <<endl;
    }
    
    
}