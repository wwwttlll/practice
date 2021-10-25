#include<bits/stdc++.h>
using namespace std;
int n,b;
int a[100];
void dfs(int x,int k){
  if(x){
    dfs(x/k,k);
    int l = x % k;
    if(l >= 10){
        cout << char(l - 10 + 'A');
    }else{
        cout << l ;
    }
  }
}
void dfs2(int x,int k){
    if(x){
        dfs2(x/k,k);
        a[++n] = x % k;
    }
    else return;
}
bool judge(){
    for(int i = 1; i <= n/2; i++){
        if(a[i] != a[n-i+1])return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> b;
    for(int i = 1; i <= 100; i++){//不知道数据范围，先设成100
        n = 0;
        dfs2(i*i,b);
        if(judge()){
            dfs(i,b);
            cout << " ";
            dfs(i*i,b);
            cout << endl;
        }
    }
    return 0;
}