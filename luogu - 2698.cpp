#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 11;
int n,d;
pair<int,int>a[N];
int q1[N];
int q2[N];
int h1,h2,t1,t2;
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> d;
    for(int i = 1; i <= n ; i++){
        cin >> a[i].first >> a[i].second ;
    }
    sort(a + 1, a + 1 + n);
    h1 = h2 = 1;
    int l = 1,r = 0;
    int ans = 0x3f3f3f3f;
    for(l = 1; l <= n; l++){
        while(h1 <= t1 && q1[h1] < l)h1++;//维护区间 如果队首在左端点左边就右移
        while(h2 <= t2 && q2[h2] < l)h2++;
        while(a[q1[h1]].second - a[q2[h2]].second < d && r < n){
            r++;
            while(h1 <= t1 && a[q1[t1]].second < a[r].second)t1--;//注意是队尾和边界比较
            q1[++t1] = r;
            while(h2 <= t2 && a[q2[t2]].second > a[r].second)t2--;
            q2[++t2] = r;
        }
        if(a[q1[h1]].second - a[q2[h2]].second >= d){
            ans = min(ans,a[r].first - a[l].first);
        }
    }
    if(ans < 0x3f3f3f3f)cout << ans << endl;
    else puts("-1");
    return 0;
}