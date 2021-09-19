#include<bits/stdc++.h>
using namespace std;
int t,n;
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int a[101];
int main(){
    t = read();
    while(t--){
        n = read();
        for(int i = 0; i < n; i++){
            char c = getchar();
            a[i] = c - '0';
            //cout << a[i] << " ";
        }
        int ans = 0;
        for(int i = n - 1; i>=0; i--){
            if(a[i] > 0){
                ans = ans + a[i] + 1;
            }
        }
        if(a[n-1]==0 ) ans +=1;
        cout << ans-1 <<endl;
    }
}   