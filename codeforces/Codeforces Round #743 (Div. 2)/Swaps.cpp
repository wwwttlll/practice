#include <bits/stdc++.h>
using namespace std;
int T,n;
int a[100020];
int b[100020];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		for(int i=2;i<=n;i++){
			b[i]=max(b[i],b[i-1]);
		}
		int sum=1000020;
		for(int i=1;i<=n;i++){
				int p=lower_bound(b+1,b+n+1,a[i]) - b;
				sum=min(sum,i+p-2);
			}
			cout<<sum<<endl;
		}
}