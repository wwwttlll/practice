#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 11;
int t;
int a[N];
int b[N];
int n,k;
int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        memset(b,0,sizeof b);
        cin >> n >> k;
        for(int i = 1; i <= k; i++){
            cin >> a[i];
            b[i] = (n-a[i]);
        }
        sort(a+1,a+1+k);
        reverse(a+1,a+1+k);
        sort(b+1,b+1+k);
        int cat = n;
        int cnt = 0;
        for(int i = 1; i <= k; i++){
            if(cat > b[i]){
                cnt++;
                cat-=b[i];
            }
            
        }
        cout << cnt << endl;
    }
    return 0;
}