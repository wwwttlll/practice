#include<bits/stdc++.h>
using namespace std;
#define int long long
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
const int N = 3e5 + 11;
int t;
int n;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    t = read();
    while(t--){
        n = read();
        int f = 0;
        for(int i = 1; i <= n; i++){
            a[i] = read();
                
        }
        if(n & 1){
            for(int i = 1; i <= n; i++){
                if(a[i] <= a[i - 1]){
                    f = 1;
                    break;
                }
            }
            if(f == 1){
                puts("YES");
            }else{
                puts("NO");
            }
        }
            
        else{
            puts("YES");
        }
    }
    return 0;
}