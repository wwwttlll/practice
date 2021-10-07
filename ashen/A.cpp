#include<cstdio>
#include<iostream>
using namespace std;
long long employee_num = 0;
long long answer; 
int main(){	
	int count = 0;  
	scanf("%d", &employee_num);
	for(int i = 0 ; i < employee_num ; i++ ) { 
		int salary; 
		scanf("%d", &salary);
		if ( count == 0 )  {
			answer = salary;
			count ++;
		}
		else{
			if(answer == salary){
				count ++;
			}
            else{
				count --;
			}
		}	
	} 
	printf("%d\n", answer); 
} 