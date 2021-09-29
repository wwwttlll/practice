#include<bits/stdc++.h>
using namespace std;
int t;
double x[10],y[10];
double cha(int q,int w,int e){
    return  (x[q] - x[w]) * (y[q] - y[e]) - (x[q] - x[e]) * (y[q] - y[w]);
}
int main(){
    //freopen("ooo.in","r",stdin);
    //freopen("o.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        //memset(x,0,sizeof x);
        //memset(y,0,sizeof y);
        for(int i = 1; i <= 4; i++){
            scanf("%lf%lf",&x[i],&y[i]);
        }
        double a,b,c,d;
        a = cha(1,2,3);
        b = cha(1,2,4);
        d = cha(3,4,1);
        c = cha(3,4,2);
        if((a * b <= 0.0) &&(c * d <= 0.0) ){
            puts("1");
        }else{
            puts("0");
        }
    }
}