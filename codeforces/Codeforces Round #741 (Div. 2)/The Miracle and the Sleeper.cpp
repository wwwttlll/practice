#include<bits/stdc++.h>
using namespace std;
int t;
int l,r;
int main(){
    cin >> t;
    while( t--){
        cin >> l>> r;
        if(l > (r + 1) / 2){
            cout << (r - l) << endl;
        }else{
            cout<<(r + 1)/2 -1 <<endl;
        }
    }
}