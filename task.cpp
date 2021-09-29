#include<iostream>
using namespace std;
int main(){
    int a = 16,b=21,m=0;
    switch (a%3)
    {
    case 0:
        m++;
        cout << 1 <<endl;
        break;
    case 1:
        m++;
        cout << 2 <<endl;
        switch (b%2)
        { 
        default:
            m++;
            cout << 3 <<endl;
        case 0:
            m++;
            cout << 4 <<endl;
            break;
        
       
        }
    }
    cout << m <<endl;
}