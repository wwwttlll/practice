#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int t;
int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int left = 0, right = s.size()-1;
        while(left < right){
            if(s[left] != s[right]){
                s[left] = s[right];
            }
            while(s[right] == s[right - 1] ){
                right --;
            }
            while(s[left] == s[left + 1]){
                left++;
            }
            left ++;
            right --;
        }
        cout << s << endl;
    }
    return 0;
}