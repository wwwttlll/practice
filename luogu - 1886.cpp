#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 11;
int n,k;
int a[N];
int qx[N],qn[N];
void getmax(){
    int head = 0,tail = 0;
    for(int i = 1; i <= k; i++){
        while(head <= tail && a[qx[tail]] <= a[i])   tail--;//找到前k个数中的最值 
        qx[++tail] = i;
        //cout <<head<<" "<< tail << " " << qx[tail] <<endl;
    }
    for(int i = k; i <= n; i++){
        while(head <= tail && a[qx[tail]] <= a[i])   tail--;
        qx[++tail] = i;
        //cout <<head<<" "<< tail << " " << qx[tail] <<endl;
        while(qx[head] <= (i - k)){
            head ++;
        }
        cout << a[qx[head]] << " ";
    }
}
void getmin(){
    int head = 0,tail = 0;
    for(int i = 1; i <= k; i++){
        while(head <= tail && a[qn[tail]] >= a[i])   tail--;
        qn[++tail] = i;
    }
    for(int i = k; i <= n; i++){
        while(head <= tail && a[qx[tail]] >= a[i])   tail--;
        qn[++tail] = i;
        while(qn[head] <= (i - k)){
            head ++;
        }
        cout << a[qn[head]] << " ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    getmin();
    cout << endl;
    getmax();
    cout << endl;
    return 0;
}