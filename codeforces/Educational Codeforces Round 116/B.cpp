#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    ios::sync_with_stdio(false);
    unsigned long long t;
    t = read();
    while(t--){
        long long n ,k;
        n = read(); k = read();
        long long cnt = 0;
        long long sum = 1; 
        while(sum < k && k != 1){
            if(sum >= n)break;
            sum *= 2;
            cnt++;
        }
        //cout << sum  <<" " << cnt <<endl ;
        if(n > sum){
            n -= sum;
        }
        else n = 0;
        if(n % k == 0)cnt += (n/k);
        else cnt += (n/k + 1);
        cout << cnt << endl;
    }
    return 0;
}
// 1 2 4