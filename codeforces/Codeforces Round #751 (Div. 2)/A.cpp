#include<bits/stdc++.h>
using namespace std;
string s;
int t;
int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> s;
        char minn = 'z';
        int id = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] < minn)  {
                minn=s[i];
                id = i;
            }  
        }
        cout << minn <<" ";
        for(int i = 0; i < s.size(); i++){
            if(i == id)continue;
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}