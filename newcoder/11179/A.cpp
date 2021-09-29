#include<bits/stdc++.h>
using namespace std;
unsigned long long two[66];
bool ok[66];
long long n,k;
unsigned long long s;
int main(){
    cin >> n >> k >> s;
    two[1] = 1;
    /*if(k == 0){
        puts("YES");
        return 0;
    }*/
    for(int i = 2; i <= n + 1; i++){
        two[i] = two[i - 1] * 2;
    }
    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        ok[x] = 1;
    }
    for(int i = n + 1; i >= 1; i--){
        if(s >= two[i] && ok[i] == 0){
            s -= two[i];
        }
    }
    if(s != 0){
        puts("NO");
    }else {
        puts("YES");
    }
}