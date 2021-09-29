#include<cstdlib>
#include<time.h>
#include<cstdio>
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
    int t = 100;
    for(int i = 1; i <= t ; i++){
        cout << i <<endl;
        system("rand.exe");
        //return 0;
        system("std.exe");
        //puts("2");
        system("aoj.exe");
        //puts("3");
        if(system("fc o.out oo.out")){
            puts("WA");
            break;
        }
        else puts("AC");
        cout <<"yes";
    }
    return 0;
}
