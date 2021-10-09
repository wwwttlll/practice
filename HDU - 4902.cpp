#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define lson x << 1 
#define rson x << 1 | 1
const int N = 1e7 + 11;
struct tree{
    int l,r,same,lazy,maxn;
    #define l(x) t[x].l
    #define r(x) t[x].r
    #define same(x) t[x].same
    #define lazy(x) t[x].lazy
    #define maxn(x) t[x].maxn
}t[N*4];
inline int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
}
int a[N];
void pushup(int x){
    maxn(x) = max(maxn(lson),maxn(rson));
    if(same(lson) == same(rson)){
        same(x) = same (lson);
    }else{
        same(x) = -1;
    }
}
void pushdown(int x){
    if(lazy(x) != -1){
        maxn(lson) = lazy(x);
        maxn(rson) = lazy(x);
        same(lson) = lazy(x);
        same(rson) = lazy(x);
        lazy(lson) = lazy(x);
        lazy(rson) = lazy(x);
        lazy(x) = -1;
    }
}
void build(int x,int l,int r){
    l(x) = l;
    r(x) = r;
    lazy(x) = -1;
    if(l == r){
        same(x) = a[l];
        maxn(x) = same(x);
        return;
    }
    int mid = (l + r) >> 1;
    build(lson,l,mid);
    build(rson,mid + 1,r);
    pushup(x);
}
void change1(int x,int l,int r,int k){
    //if(l >r(x)|| l(x) >r)return;
    if(l <= l(x) && r(x) <= r){
        same(x) = k;
        lazy(x) = k;
        maxn(x) = k;
        return;
    }
    pushdown(x);
    int mid = (l(x) + r(x)) >> 1;
    if(l <= mid){
        change1(lson,l,r,k);
    } 
    if(r > mid){
        change1(rson,l,r,k);
    }
    pushup(x);
}
void change2(int x,int l,int r,int k){
    if(maxn(x) <= k)return;
    //if(l >r(x)|| l(x) >r)return;
    if(l <= l(x) && r(x) <= r){
        if(same(x) != -1){
            //if(same(x) > k){
                same(x) = gcd(maxn(x),k);
                lazy(x) = gcd(maxn(x),k);
                maxn(x) = gcd(maxn(x),k);
                return;
            //}
        }
    }
    pushdown(x);
    int mid = (l(x) + r(x)) >> 1;
    if(l <= mid){
        change2(lson,l,r,k);
    }
    if(r > mid){
        change2(rson,l,r,k);
    }
    pushup(x);
}
int query(int x,int pos){
    if(l(x) == r(x)){
        return maxn(x);
    }
    pushdown(x);
    int mid = (l(x) + r(x)) >> 1;
    if(pos<=mid)
        return query(lson,pos);
    else{
        return query(rson,pos);
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        build(1,1,n);
        int m;
        cin >> m;
        while(m--){
            int op,x,y,z;
            cin >> op >> x >> y >> z;
            if(op == 1){
                change1(1,x,y,z);
            }
            if(op == 2){
                change2(1,x,y,z);
            }
        }
        for(int i=1;i<=n;i++)
            printf("%d ",query(1,i));
        puts("");
    }
    return 0;
}
