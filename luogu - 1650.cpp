#include <bits/stdc++.h>
using namespace std;
int a[2011],b[2011];
long long n;
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
deque<int>aa;
deque<int>bb;
int main(){
    n = read();
    for(int i = 1; i <= n; i++){
        a[i] = read();
    }
    for(int i = 1; i <= n; i++){
        b[i] = read();
    }
    sort(a + 1,a + 1 + n);
    sort(b + 1,b + 1 + n);
    int win = 0;
    for(int i = n; i >= 1; i--){
        aa.push_back(a[i]);
        bb.push_back(b[i]);
    }
    for(int i = 1; i <= n; i++){
        if(aa.front() > bb.front()){
            aa.pop_front();
            bb.pop_front();
            win += 200;
        }
        else if(aa.front() < bb.front()){
            aa.pop_back();
            bb.pop_front();
            win -= 200;
        }
        else if(aa.back() > bb.back()){
            aa.pop_back();
            bb.pop_back();
            win += 200;
        }
        else{
            if(aa.back() < bb.front())win -= 200;
            aa.pop_back();
            bb.pop_front();
            
        }
    }
    cout << win <<endl;
}