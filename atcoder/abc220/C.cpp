#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int n;
long long a[N];
long long sum; 
long long x;
int main(){
    scanf ("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%lld",&a[i]);
        sum += a[i];
    }
    scanf ("%lld",&x);
    long long div = x / sum;
    div *= n;
    x %= sum;
    for(int i = 1; i <= n; i++){
        if(x >= 0){
            x -= a[i];
            div++;
        }
    }
    cout << div << endl;
}