#include<bits/stdc++.h>
using namespace std;
int t;
string solve(long long x){
    if(x==1){
        return "2";
    }
    string s;
    if(x%2==1){
        s=s+"(2*"+solve(x-1)+")";
        return s;
    }
    else{
        s=s+"("+solve(x/2)+")^2";
        return s;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        long long k;
        cin >> k;
        cout<<solve(k)<<endl;
    }
}