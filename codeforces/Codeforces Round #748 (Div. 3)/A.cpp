#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    while(n--){
        long long a,b,c;
        cin >> a >> b >>c;
        long long maxn = max(a,max(b,c));
        if(a == b && a == c){
            cout << 1 <<" " << 1 << " " <<1 <<endl;
            continue;
        }
        if(a==maxn&&b==maxn){
            cout << 1 << " "<<1 << " " << (maxn-c+1) << endl;
            continue;
        }
        if(a==maxn&&c==maxn){
            cout << 1 << " "<<(maxn-b+1) << " " << 1 << endl;
            continue;
        }
        if(c==maxn&&b==maxn){
            cout << (maxn-a+1) << " "<<1 << " " << 1 << endl;
            continue;
        }
        if(a == maxn){
            cout << 0 << " ";
        }else{
            cout << (maxn-a+1) << " ";
        }
        if(b == maxn){
            cout << 0 << " ";
        }else{
            cout << (maxn-b+1) << " ";
        }
        if(c == maxn){
            cout << 0 << endl;
        }else{
            cout << (maxn-c+1) << endl;
        }
    }
    return 0;
}