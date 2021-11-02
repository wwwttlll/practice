#include<bits/stdc++.h>
using namespace std;
#define int long long
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
char a,b,c;
signed main(){
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    if(a == b && a == c){
        cout << 1 << endl;
    }
    else if ( a==b || b == c || c == a){
        cout << 3 << endl;
    }
    else{
        cout << 6 << endl;
    }
    return 0;
}