#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int c,m;
set<int > s;
int n , q;
int main(){

    
    n = read(); q = read();
    s.insert(0);
    s.insert(n);
    for(int i = 1; i <= q; i++){
        cin >> c >> m;
        if(c == 1){
            s.insert(m);
        }else{
            set<int >::iterator l ;
            set<int >::iterator r ;
            l = s.lower_bound(m);
            r = l;
            l--;
            cout << *r - *l  << endl;
        }
    }
    return 0;
}