#include<bits/stdc++.h>
using namespace std;
int n;
int f[10];
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    while(n--){
        long long a;
        memset(f,0,sizeof f);
        cin >> a;
        int cnt = 0;
        while(a){
            int x = a%10;
            a/=10;
            
            cnt++;
            //cout << x << cnt << endl;
            if(f[0]&&(x==0||x==5)){
                cout << cnt-2 << endl;
                break;
            }
            if(f[5]&&(x==2||x==7)){
                cout << cnt-2 << endl;
                break;
            }
            if(x==0||x==5){
                f[x] ++;
            }
        }
    }
    return 0;
}