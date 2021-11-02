#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long ret=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int n, m1, m2;
struct note {
    int x,y;
}a[100011];
priority_queue<pair <int ,int > >q1; // 存进入栈桥的id first记录离开时间 second 记录栈桥id
int a1[100011];
int a2[100011];
int tag;
priority_queue<int >q2;//空闲栈桥
bool cmp(note a, note b){
    return a.x < b.x;
}
int main(){
    cin >> n >> m1 >> m2;
    for(int i = 1; i <= m1; i++){
        a[i].x = read();a[i].y = read();
    }
    sort(a + 1, a + 1 + m1, cmp);
    for(int i = 1; i <= n; i++){
        q2.push(-i);
    }
    for(int i = 1; i <= m1; i++){
        if(tag ){
            while(tag && a[i].x > -q1.top().first){
                tag --;
                q2.push(-q1.top().second);
                q1.pop();
            }
        }
        if(!q2.empty()){
            int x = - q2.top();
            q2.pop();
            a1[x] ++; 
            q1.push(make_pair(-a[i].y,x));
            tag ++;
        }
    }
    for(int i = 1; i <= n; i++){
        a1[i] += a1[i - 1];
    }
    tag = 0;
    while(q1.size())q1.pop();
    while(q2.size())q2.pop();
    for(int i = 1; i <= m2; i++){
        a[i].x = read();a[i].y = read();
    }
    sort(a + 1, a + 1 + m2 , cmp);
    for(int i = 1; i <= n; i++){
        q2.push(-i);
    }
    for(int i = 1; i <= m2; i++){
        if(tag ){
            while(tag && a[i].x > -q1.top().first){
                tag --;
                q2.push(-q1.top().second);
                q1.pop();
            }
        }
        if(!q2.empty()){
            int x = - q2.top();
            q2.pop();
            a2[x] ++; 
            q1.push(make_pair(-a[i].y,x));
            tag ++ ;
        }
    }
    for(int i = 1; i <= n; i++){
        a2[i] += a2[i - 1];
    }
    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans = max(ans, a1[i] + a2[n - i]);
    }
    cout << ans << endl;
    return 0;
}