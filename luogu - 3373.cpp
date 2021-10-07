#include<bits/stdc++.h>
using namespace std;
#define lson x << 1 
#define rson x << 1 | 1
#define int long long
int p;
const int N = 1e6 + 11;
struct tree{
    int l,r,add,mul,sum;
    #define l(x) t[x].l
    #define r(x) t[x].r
    #define add(x) t[x].add
    #define mul(x) t[x].mul
    #define sum(x) t[x].sum
}t[4 * N];
int a[N];
int n,m;
void build(int x,int l,int r){
    l(x) = l;
    r(x) = r;
    add(x) = 0;
    mul(x) = 1;
    if(l == r){
        sum(x) = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lson,l,mid);
    build(rson,mid + 1,r);
    sum(x) = (sum(lson) + sum(rson)) % p;
}
void spread(int x){
    mul(lson) = mul(lson) * mul(x) % p;
    mul(rson) = mul(rson) * mul(x) % p;
    add(lson) = add(lson) * mul(x) % p;
    add(rson) = add(rson) * mul(x) % p;
    sum(lson) = (sum(lson) * mul(x)) % p;
    sum(rson) = (sum(rson) * mul(x)) % p;
    mul(x) = 1;
    add(lson) = (add(lson) + add(x))%p;
    add(rson) = (add(rson) + add(x))%p;
    sum(lson) = (sum(lson) + add(x) * (r(lson) - l(lson) + 1)) % p;
    //sum(lson) = (sum(lson) + add(x) * (r(lson) - l(lson) + 1)) % p;
    sum(rson) = (sum(rson) + add(x) * (r(rson) - l(rson) + 1)) % p;
    //sum(rson) = (sum(rson) + add(x) * (r(rson) - l(rson) + 1)) % p;
    add(x) = 0;
}
/*
void spread(int x){
	add(lson)=(add(lson)+add(x))%p;
	add(rson)=(add(rson)+add(x))%p;
	
	
	add(x)=0;
}*/

void A(int x,int l,int r,int k){
    if(l <= l(x) && r(x) <= r){
        add(x) += k;
        add(x) %= p;
        sum(x) = (sum(x) + k * (r(x) - l(x) + 1)) % p;
        return;
    }
    spread(x);
    int mid = (l(x) + r(x)) >> 1;
    if(l <= mid){
        A(lson,l,r,k);
    }
    if(r > mid){
        A(rson,l,r,k);
    }
    sum(x) = (sum(lson) + sum(rson))%p;
}
void M(int x,int l,int r,int k){
    if(l <= l(x) && r(x) <= r){
        mul(x) = mul(x) * k % p;
        add(x) = add(x) * k % p;
        sum(x) = sum(x) * k % p;
        return;
    }
    spread(x);
    int mid = (l(x) + r(x)) >> 1;
    if(l <= mid){
        M(lson,l,r,k);
    }
    if(r > mid){
        M(rson,l,r,k);
    }
    sum(x) = (sum(lson) + sum(rson))%p;
}
int query(int x,int l,int r){
    if(l <= l(x) && r(x) <= r){
        return sum(x);
    }
    spread(x);
    int mid = (l(x) + r(x)) >> 1;
    int ans = 0;
    if(l <= mid){
        ans += query(lson,l,r);
    }
    if(r > mid){
        ans += query(rson,l,r);
    }   
    return ans%p;
}
signed main(){
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1,1,n);
    /*for(int i = 1; i <= n; i++){
                cout << query(1,i,i) <<" ";
            }
            cout << endl;*/
    while(m--){
        int op,x,y,z;
        cin >> op;
        //cout << op << endl;
        if(op == 1){
            cin >> x >> y >> z;
            M(1,x,y,z);
        }
        if(op == 2){
            cin >> x >> y >> z;
            A(1,x,y,z);
            /*for(int i = 1; i <= n; i++){
                cout << query(1,i,i) <<" ";
            }
            cout << endl;*/
        }
        if(op == 3){
            cin >> x >> y;
            cout << query(1,x,y) << endl;
        }
    }
    return 0;
}