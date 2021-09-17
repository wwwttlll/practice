#include<bits/stdc++.h>
using namespace std;
int num[11];
int main(){
    int t ;
    cin >> t;
    while(t--){
        int l;
        cin >> l;
        char s[100];
        int flag=0;
        for(int i = 1; i <= l; i++){
            cin >> s[i];
        }
        for(int i = 1; i <= l; i++){
            if(s[i] == '4'||s[i] == '6'|| s[i] == '8' || s[i] == '9'||s[i] == '1'){
                cout << 1 <<endl;
                cout <<s[i] <<endl;
                flag = 1;
                break;
            }
        }
        if (flag == 1){
            continue;
        }
        for(int i = 1; i <= l; i++){
            if(i != 1 &&(s[i] == '5' || s[i] == '2')){
                cout << 2 <<endl;
                cout << s[i-1] << s[i] <<endl;
                flag = 1;
                break;
            }
            
            if(s[i]=='0'){
                cout << 2 <<endl;
                cout <<s[i - 1]<<s[i]<<endl;
                flag = 1;
                break;
            }
        }
        if (flag == 1){
            continue;
        }
        memset(num,0,sizeof num);
        for(int i = 1; i <= l; i++){
            if(num[3 - (s[i] - '0')] > 0){
                cout <<2 <<endl;
                cout <<(6 - (s[i] - '0'))<<s[i]<<endl;
                flag = 1;
                break;
            }
            if(num[6 - (s[i] - '0')] > 0){
                cout <<2 <<endl;
                cout <<(6 - (s[i] - '0'))<<s[i]<<endl;
                flag = 1;
                break;
            }
            if(num[9 - (s[i] - '0')] > 0){
                cout <<2 <<endl;
                cout <<(9 - (s[i] - '0'))<<s[i]<<endl;
                flag = 1;
                break;
            }
            if(num[12 - (s[i] - '0')] > 0){
                cout <<2 <<endl;
                cout <<(12 - (s[i] - '0'))<<s[i]<<endl;
                flag = 1;
                break;
            }
            if(num[15 - (s[i] - '0')] > 0){
                cout <<2 <<endl;
                cout <<(15 - (s[i] - '0'))<<s[i]<<endl;
                flag = 1;
                break;
            }
            num[s[i] - '0']++;
        }
        if (flag == 1){
            continue;
        }
        for(int i = 1; i <= 9; i++){
            if(num[i] > 1){
                cout << 2 <<endl;
                cout <<i<<i<<endl;
                flag = 1;
                break;
            }
        }
        
    }
}