#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[500020];
int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1 ; i <= n; i++){
			cin >> a[i];
		}
		deque<int>q;
		q.push_back(a[1]);
		for(int i = 2; i <= n; i++){
			if(a[i] > q.front()){
				q.push_back(a[i]);
			}else{
				q.push_front(a[i]);
			}
		}
		while(q.size()){
			int x = q.front();
			q.pop_front();
			cout << x << " ";
		}
		cout << endl;
	}
}