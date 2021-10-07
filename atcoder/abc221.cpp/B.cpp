#include<bits/stdc++.h>
using namespace std;
string a,b;
int id1,id2;
int main(){
    cin >> a >> b;
    int cnt = 0;
    for(int i = 0; i < a.size();i++){
        if(a[i] != b[i]){
            cnt ++;
            if(!id1){
                id1 = i;
            }else{
                id2 = i;
            }
        }
    }
    if(cnt > 2){
        puts("No");
    }
    else if(cnt == 1){
        puts("No");
    }
    else if(cnt == 2){
        swap(a[id1],a[id2]);
        if(a==b){
            puts("Yes");
        }else puts("No");
    }
    else if (cnt == 0){
        puts("Yes");
    }
    return 0;
}