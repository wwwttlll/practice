#include<bits/stdc++.h>
using namespace std;
long long k,a,b;

long long work(long long n){
    long long re = 0;
    long long cnt = 1;
    while(n){
        re += (n % 10) * cnt;
        n /= 10;
        cnt *= k;
    }
    return re;
}
int main(){
    cin >> k >> a >> b;
    cout <<(work(a) * work(b)) << endl;
}