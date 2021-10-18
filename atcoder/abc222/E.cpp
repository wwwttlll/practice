#include <bits/stdc++.h>
using namespace std;
int sum=0;
vector <int>a[100020];
int n,m,k;
int dp[100020];
int c[100020];
int num[100020];
const int mod=998244353;
map<pair<int ,int > , int>mp;
bool dfs(int x,int y,int z){
	if(x==z){
		return true;
	}
	for(int i=0;i<a[x].size();i++){
		if(a[x][i]==y){
			continue;
		}
		if(dfs(a[x][i],x,z)){
			num[mp[make_pair(a[x][i],x)]]++;
			return true;
		}
	}
	return false;
}
long long qw(long long x,long long y,long long mod){
	long long re=1;
	for(;y;y/=2){
		if(y%2==1){
			re=re*x%mod;
		}
		x=x*x%mod;
	}
	return re;
}
int main(){
	cin>>n>>m>>k;
	k=abs(k);
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
		mp[make_pair(x,y)]=i;
		mp[make_pair(y,x)]=i;
	}
	for(int i=2;i<=m;i++){
		dfs(c[i-1],c[i-1],c[i]);
	}
	for(int i=1;i<n;i++){
		sum+=num[i];
	}
	dp[sum]=2;
	for(int i=1;i<n;i++){
		for(int j=0;j<=sum;j++){
			if(j+2*num[i]<=sum)
			dp[j]=(dp[j]+dp[j+2*num[i]])%mod;
		}
	}
	dp[k]%=mod;
	cout<<dp[k]*qw(2,mod-2,mod)%mod<<endl;
} 