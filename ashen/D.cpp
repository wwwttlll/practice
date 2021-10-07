#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
const int N = 1e5 + 11;
int t;
int v[N];
int sum [N];
vector<int>a[N];
set<int>s[N];
int n,m;
void dfs(int root,int id,int step){
    if(step > 1)return ;
    for(int i = 0; i < a[id].size();i++){
        s[root].insert(a[id][i]);
        sum[root] += v[a[id][i]];
        dfs(root,a[id][i],step + 1);
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        for(int i = 1; i <= n ; i++){
            s[i].clear();
            a[i].clear();
        }
        memset(v,0,sizeof v);
        memset(sum,0,sizeof sum);
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i++){
            scanf("%d",&v[i]);
        }
        for(int i = 1; i < n ; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for(int i = 1; i <= n ; i ++){
            dfs(i,i,0);
        }
        /*for(int i = 1; i <= n ; i++){
            set<int >::iterator it =s[i].begin();
                while(it != s[i].end()){
                    cout << *it ;
                    it++;
                }
            cout << endl;
        }*/
        for(int i = 1; i <= n; i ++){
            sum[i] -= v[i];
        }
        for(int i = 1; i <= m; i++){
            int op;
            scanf("%d",&op);
            if(op == 1){
                int x,y;
                scanf("%d%d",&x,&y);
                //sum[x] = sum[x] - v[x] + y;
                set<int >::iterator it =s[x].begin();
                while(it != s[x].end()){
                    //cout << *it;
                    sum[*it] -= v[x];
                    sum[*it] += y;
                    it++;
                }

            }else{
                int x;
                scanf("%d",&x);
                printf("%d\n",sum[x]);
            }
        }
    }
}