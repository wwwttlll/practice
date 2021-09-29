#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("ooo.in","w",stdout);
	srand(time(0));
	int t = rand();
	t%=1000;
	cout <<t<<endl;
	while(t--){
		for(int i = 1; i <= 4; i++){
			double x = rand() + rand() / double(RAND_MAX);
			double y = rand() + rand() / double(RAND_MAX);
			printf("%.2lf %.2lf ",x,y);
		} 
		cout << endl;
	}
} 