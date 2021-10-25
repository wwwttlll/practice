#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[1000];
int l;
int id;
int ans;
void dfs(int x){
    while(x){
        a[id] += x % 2;
        id++;
        //cout << x % 2;
        //cout << id << " " << x%2 <<" " << a[id]<<endl;
        x/=2;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        memset(a,0,sizeof a);
        ans = -1;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> l;
            id = 1;
            dfs(l);
        }
        //cout << ans << endl << endl;
        sort(a + 1 , a + 1 + 100);
        reverse(a + 1 , a + 1 + 100);
        for(int i = 1; i <= 1000; i++){
            if(ans == -1 && a[i] > 0){
                ans = a[i];
                continue;
            }
            if(a[i]  > 0){
                ans = __gcd(ans,a[i]);
            }
            else break;
        }
        if(ans == -1){
            for(int i = 1; i <= n; i++){
                cout <<i << " ";
            }cout  << endl;
            continue;
        }else{
            for(int i = 1; i <= ans ; i++){
                if(ans % i == 0){
                    cout << i << " ";
                }
            }cout << endl;
        }
    }
    return 0;
}