#include<bits/stdc++.h>
using namespace std;
//  ??
int ans = 10000;
string s = "cocacola";
string ss;
void dfs(int id,int cnt){
    if(id == 8){
        return void(ans = min (ans,cnt));
    }
    if(s[id] == ss[id]){
        dfs(id + 1, cnt );
    }else{
        for(int i = id + 1; i <= 7; i++){
            if(ss[i] == s[id]){
                swap(ss[i],ss[id]);
                dfs(id + 1,cnt + 1);
                swap(ss[i],ss[id]);
            }
        }
    }
}
int main(){
    cin >> ss;
    dfs(0,0);
    cout << ans << endl;
}