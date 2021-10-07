#include<bits/stdc++.h>
using namespace std;
long long t;
long long n,m,k;
int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
		if (m >= n - 1 && k > 3){
			puts("YES");
            continue;
		}
        if (n == 1 && m == 0){
			puts("YES");
			continue; 
		}
		if (k > 2 && m == (n * (n - 1)) / 2){
			puts("YES");
            continue;
		}
		if(m > (n * (n - 1)) / 2){
            puts("NO");
            continue;
        }
		puts("NO");
    }
    return 0;
}