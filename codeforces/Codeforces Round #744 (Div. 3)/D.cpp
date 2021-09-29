#include <bits/stdc++.h>
using namespace std;
long long aa[420000];
long long a[420000];
long long b[420000];
long long cnt[420000];
int t,n;
int main(){
    ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>aa[i];
            cnt[i] = aa[i];
        }
        sort(aa + 1,aa + n + 1);
        long long sum=0;
        for(int i=1;i<n;i++){
            sum+=aa[i];
        }
        long long nnn=aa[n];
        int djk=0;
        
        aa[n]=min(aa[n],sum);
        for(int i=1;i<=n;i++){
            if(cnt[i]==nnn){
                cnt[i]=aa[n];
            }
        }
        cout<<(sum+aa[n])/2<<endl;
        for(int i=1;i<=n;i++){
            if(cnt[i]!=0)
            for(int j=1;j<=cnt[i];j++){
                djk++;
                if(djk<=(sum+aa[n])/2){
                    a[djk]=i;
                }
                else{
                    b[djk - (sum + aa[n]) / 2] = i;
                }
                
            }
        }
        for(int i=1;i<=(sum+aa[n])/2;i++){
            cout<<a[i]<<" "<<b[i]<<endl;
        }
    }
}
