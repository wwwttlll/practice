#include <bits/stdc++.h>
using namespace std;
int a[200020];

int main() {
	int qt;
	cin >> qt;
	while (qt--) {
		int n;
		cin >> n;
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i]) {
				flag = false;
			}
		}
		if (flag == true) {
			for (int i = 1; i <= n; i++) {
				cout << i ;
				if(i!=n)
				{
					cout<<" ";
				}
			}
			cout << endl;
			continue;
		}
		int ans = 1, tt = 0;
		for (int i = 1; i <= 30; i++) {
			int cnt = 0;
			for (int j = 1; j <= n; j++) {
				//	cout << "a[j]: " << a[j] << endl;
				if (a[j] & 1) {
					cnt++;
				}
				a[j] >>= 1;
			}
			//cout << "cnt: " << cnt << endl;
			if (cnt) {
				tt = 1;
				//	cout << "md";
			}
			if (tt && cnt) {
				ans = cnt;
				//	cout << i << " " << cnt << endl;
			}
			if (cnt) {
				ans = __gcd(ans, cnt);
			}


			//	cout << ans << " ";
		}
		for (int i = 1; i <= ans; i++) {
			if (ans % i == 0) {
				cout << i;	
				if (i != ans) {
				cout << " ";
			    }
			}
		
		}
		puts("");
		//cout << ans << endl;
	}
}/*
1
4
4 4 4 4
*/
