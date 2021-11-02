#include<bits/stdc++.h>
using namespace std;
#define int long long
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
string s;
char a[100];
char b[100];
int aid[100];
int ans = 0;
int ansall = 0;
string anss;
signed main(){
    ios::sync_with_stdio(false);
    while(getline(cin,s)){
        if(s[0] == '@')break;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A') ){
                a[++cnt] = s[i];
                aid[cnt] = i;
            }
        }
        for(int i = 1; i <= cnt ; i++){
            b[cnt - i + 1] = a[i];
        }/*
        for(int i = 1; i <= cnt ; i++){
            cout << a[i] ;
        }
        cout << endl;
        for(int i = 1; i <= cnt ; i++){
            cout << b[i] ;
        }
        cout << endl;*/
        int f[100][100] = {0};
        int ans = 0;
        int last = 0;
        for(int i = 1; i <= cnt; i++)
            for(int j = 1; j <= cnt; j++){
                if(a[i] == b[j] || (a[i] - 'A' + 'a' == b[j]) || (a[i] - 'a' + 'A' == b[j])){
                    f[i][j] =  f[i-1][j-1] + 1;
                    if(f[i][j] > ans){
                        ans = f[i][j];
                        //cout << a[i] << " " << b[j] << endl;
                        last = i;
                    }
                }
            }
        
        //cout << ans << endl;
        if(ansall < ans){
            ansall = ans;
            anss.clear();
            for(int i = aid[last]; i; i--){
                anss = s[i] + anss ;
                if(isalpha(s[i]))ans--;
                if(ans == 0)break;
            }
        }
    }
    cout << ansall << endl;
    cout << anss << endl;
    return 0;
}
/*
Confucius say : Madam,I'm adam.
abcd eaa aa aaa aedcab
bacdeedcba
@


*/