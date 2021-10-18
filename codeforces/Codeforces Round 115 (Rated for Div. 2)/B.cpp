#include<bits/stdc++.h>
using namespace std;
int t,n;
int mp[6][6];
int num[10];
int a[6];
int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        memset(mp,0,sizeof mp);
        memset(num,0,sizeof num);
        for(int i = 1; i <= n; i++){
            memset(a,0,sizeof a);
            for(int j = 1; j <= 5 ; j++){
                cin >> a[j];
                num[j] += a[j];
            }
            for(int j = 1; j <= 5 ; j++){
                for(int k = 1; k <= 5; k++){
                    if(j == k){
                        continue;
                    }
                    if(a[j] && a[k])
                        mp[j][k]++;
                }
            }

        }
        int flag = 0;
        for(int i = 1 ; i <= 5 ;i++){
            for(int j = 1; j <= 5; j++){
                if(i == j)continue;
                if(mp[i][j]&1){
                    if(max(num[i],num[j]) - (mp[i][j] + 1) / 2 >= (n/2) &&min(num[i],num[j]) - (mp[i][j] ) / 2 >= (n/2) ){
                        flag = 1;
                    //cout << i << " " << j << endl;
                        break;
                    }
                }
                else
                if(num[i] - (mp[i][j] + 1)/2 >= (n/2) && num[j] - (mp[i][j] + 1)/2 >= (n/2)){
                    flag = 1;
                    //cout << i << " " << j << endl;
                    break;
                }
            }
        }
        if(flag == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}