#include <iostream>
using namespace std;

int funcao (int n1){
	if(n1==1){
		return 1;
	}
	else if(n1>1){
		return 2*funcao(n1-1)+1 ;
	}
	return 0;
}

int main(){
	int A;
	
	cin >> A;
	
	cout << funcao(A);
}
