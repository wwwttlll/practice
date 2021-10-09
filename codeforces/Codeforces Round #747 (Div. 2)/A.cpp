#include<bits/stdc++.h>
using namespace std;
unsigned long long t;
long long n;
int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        cout << -(n-1)<<" " <<n<< endl;
    }
    return 0;
}