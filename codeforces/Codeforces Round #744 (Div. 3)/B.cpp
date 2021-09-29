#include<bits/stdc++.h>
using namespace std;
queue<pair<int, int> > qq;
int t,n;
int a[100];

void maaa(int l, int r){
	int re = a[l];
	for(int i = l; i < r; ++i){
		a[i] = a[i + 1];
	}
	a[r] = re;
}
void test(){
	cerr << "#";
	for(int i = 1; i <= n; ++i){
		cerr << a[i] << " ";
	}
	cerr << endl;
}
int main(){
	cin >> t;
	while(t--){
		cin >> n;
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; ++i){
            cin >> a[i];
        }
		for(int i = n; i >= 1; --i){
			for(int j = i - 1; j >= 1; --j){
				if(a[i] < a[j]){   
                    qq.push(make_pair(j, i));
					maaa(j, i);
				}
			}
		}
		cout << qq.size() << endl;
		while(qq.size()){
			cout << qq.front().first << " " << qq.front().second <<  " " << 1 << endl;
			qq.pop();
		}
	}
}
