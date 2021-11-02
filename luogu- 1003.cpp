#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int a[10000][4];
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
    }
    int ans = -1;
    int x,y;
    cin >> x >> y;
    for(int i = 1; i <= n; i++){
        if(x <= a[i][1] + a[i][3] && x >= a[i][1]&& y <= a[i][2] + a[i][4] && y >= a[i][2]){
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}