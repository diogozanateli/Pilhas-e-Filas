#include <iostream>
using namespace std;

int func(int m, int n){
	if(m == 0){
		return n+1;
	}
	else if((m>0) and (n==0)){
		return func(m-1, 1);
	}
	else if((m>0) and (n>0)){
		return func(m-1, func(m, n-1));
	}
	return 0;
}

int main(){
	int A, B;
	
	cin >> A >> B;
	
	cout << func(A, B);
}
