#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define lson x << 1
#define rson x << 1 | 1
const int N = 1e6 + 11;
int n,m;
struct tree{
    ll l,r,add,sum;
    #define l(x) t[x].l
    #define r(x) t[x].r
    #define add(x) t[x].add
    #define sum(x) t[x].sum
}t[N * 4];
ll a[N];
void build(int x,int l,int r){
    l(x) = l;
    r(x) = r;
    add(x) = 0;
    if(l == r){
        sum(x) = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lson,l,mid);
    build(rson,mid + 1,r);
    sum(x) = sum(lson) + sum(rson);
}
void spread(int x){
    sum(lson) += add(x) * (r(lson) - l(lson) + 1);
    sum(rson) += add(x) * (r(rson) - l(rson) + 1);
    add(lson) += add(x);
    add(rson) += add(x);
    add(x) = 0;
}
void change(int x,int l,int r,int k){
    if(l <= l(x) && r(x) <= r){
        add(x) += k;
        sum(x) += k * (r(x) - l(x) + 1);
        return ;
    }
    spread(x);
    int mid = (l(x) + r(x)) >> 1;
    if(l <= mid){
        change(lson , l, r, k);
    }
    if(r > mid){
        change(rson , l , r, k);
    }
    sum(x) = sum(lson) + sum(rson);
}
ll query(int x,int l,int r){
    if(l <= l(x) && r(x) <= r){
        return sum(x);
    }
    spread(x);
    int mid = (l(x) + r(x)) >> 1;
    ll ans = 0;
    if(l <= mid){
        ans += query(lson,l,r);
    }
    if(r > mid){
        ans += query(rson,l,r);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    while(m--){
        int op,x,y,z;
        scanf("%d",&op);
        if(op == 1){
            scanf("%d%d%d",&x,&y,&z);
            change(1,x,y,z);
        }
        if(op == 2){
            scanf("%d%d",&x,&y);
            ll ans = query(1,x,y);
            printf("%lld\n", ans);
        }
    }
    return 0;
}