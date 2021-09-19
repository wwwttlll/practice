#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
const int N = 1e5 + 11;
int t,n;
int a[N],b[N];
int aa[N],bb[N];
int main(){
    t = read();
    while(t--){
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(aa,0,sizeof aa);
        n = read();
        aa[0] = 1e9 + 11;
        for(int i = 1; i <= n; i++){
            a[i] = read();
            aa[i] = min(a[i],aa[i-1]);
        }
        /*for(int i = 1; i <= n; i++){
            cout << aa[i] << endl;
        }*/
        for(int i = 1; i <= n; i++){
            b[i] = read();
            bb[i] = max(bb[i - 1], b[i]);
        }
        //cout << "b1" << b[1] << endl;
        if(a[1] < b[1]){
            printf("0\n");
            continue;
        }
        int ans = 1e9;
        for(int i = 1; i <= n; i++){
            if(aa[i] < b[1]){
                ans = i - 1;
                break;
            }
        }
        for(int i = 1; i <= n; i++){
            if(a[1] < bb[i]){
                ans = min(ans, i - 1);
                break;
            }
        }
        //int ans1 = lower_bound(bb + 1,bb + 1 + n, a[1]) - bb;
        //ans = min(ans,ans1);
        cout << ans <<endl;
    }
}