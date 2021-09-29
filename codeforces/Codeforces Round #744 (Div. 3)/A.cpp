#include <bits/stdc++.h>
using namespace std;
int t;
int a,b,c;
int main(){
    cin >> t;
    while(t -- ){
        a = 0;b = 0; c = 0; 
        string s;
        cin >> s;
        for(int i = 0; i < s.size();i++){
            if(s[i] == 'A'){
                a++;
            }
            else if(s[i] == 'B'){
                b++;
            }else{
                c++;
            }
        }
        b -= a;
        b -= c;
        if(b == 0){
            puts("YES");
        }else{
            puts("NO");
        }
    }
}