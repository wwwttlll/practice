#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    a[0] = 1;
    for(int i = 1; i <= 100;i++){
       a[i] = a[i-1] + 1;
    }
    //int k = 5,a[k];

}   /*
0.1  0.000011......
0
0.2
0
0.4
0
0.8
0
1.6
1
1.2
1

0.2
0
0.4
0
0.8
0
i=0 i=1
0 1 0 2
1 1 1 2
*/
    
