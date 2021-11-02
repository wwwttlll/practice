#include<bits/stdc++.h>
using namespace std;
#define int long long
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
const int N = 1e5 + 11;
int n;
vector <int >a[N];
signed main(){
    ios::sync_with_stdio(false);
    n = read();
    for(int i = 1; i < n ; i++){
        int x,y;
        x = read(); y = read();
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int flag = 0;
    for(int i = 1; i <= n; i++){
        if(a[i]. size() == n-1){
            flag = 1;
        }
    }
    if(flag == 1)puts("Yes");
    else {
        puts("No");
    }
    return 0;
}