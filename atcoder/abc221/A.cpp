#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
    ios::sync_with_stdio(false);
    cin >> a >> b;
    long long cha = a-b;
    int ans = 1;
    for(int i = 1; i <= cha; i++){
        ans *= 32;
    }
    cout <<ans <<endl;
    return 0;
}