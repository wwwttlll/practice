#include<bits/stdc++.h>
using namespace std;
int n ;
int maxn[800][800];
int minn[800][800];
int sum[800];
int a[800];
int x;
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i + n] = a[i];
    }
    for(int i = 1; i <= 2*n; i++){
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 2; i <= n; i++){
        for(int l = 1; l + i - 1 <= 2*n; l++){
            int r = l + i - 1;
            maxn[l][r] = 0;
            minn[l][r] = 1e9;
            for(int j = l; j < r; j++){
                maxn[l][r] = max(maxn[l][r],maxn[l][j] + maxn[j+1][r] + sum[r] - sum[l - 1]);
                minn[l][r] = min(minn[l][r],minn[l][j] + minn[j+1][r] + sum[r] - sum[l - 1]);
            } 
            //cout << minn[l][r] << endl;
        }
    }
    int ans1=1e9;
	int ans2=0;
	for(int i=1;i<=n;i++){
		ans1=min(ans1,minn[i][i+n-1]);
		ans2=max(ans2,maxn[i][i+n-1]);
	}
    cout << ans1 <<endl << ans2 << endl;
    return 0;
}