#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int cnt;
int main(){
    cin >> a >> b >> c;
    while((c * cnt )<= max(a,b)){
        cnt++;
        if((c * cnt) >= min(a,b)&&c * cnt <= max(a,b)){
            cout << c * cnt <<endl;
            return 0;
        }
    }
    cout << "-1" <<endl;
    return 0;
}