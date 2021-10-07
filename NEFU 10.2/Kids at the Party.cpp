#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int flag = 1;
        int l = s.length() - 1;
        //cout << s[l] << endl;
        long long sum = 0;
        int end = s[l] - '0';
        if(end % 2 == 0){
            cout << 2 <<" ";
            flag = 0;
        }
        for(int i = 0; i < s.size(); i++){
            int x = s[i] - '0';
            sum += x;
        }
        if(sum % 3 == 0){
            cout << 3 <<" ";
            flag = 0;
        }
        int lasttwo = 10*(s[l-1] - '0')+(s[l] - '0');
        if(lasttwo % 4 == 0){
            cout << 4 << " ";
            flag = 0;
        }
        if(s[l] == '5'||s[l] == '0'){
            cout << 5 << " ";
            flag = 0;
        }
        if(flag == 1){
            cout << -1;
        }
        cout << endl;
    }
}