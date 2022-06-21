#include <iostream>
using namespace std;

int funcaoF(int n);

int funcaoH(int m){
if(m==0){
	return 0;
}
else{
	return funcaoH(m-1)+funcaoF(m-1);
}
return 0;
}

int funcaoF(int n){
if(n==0){
	return 1;
}
else if((n>0) and (n%2==0)){
	return ((2*funcaoH(n))+funcaoF(n-1));
}
else if((n>0) and (n%2!=0)){
	return ((2*funcaoH(n))-funcaoF(n-1));
}
return 0;
}

int main(){
	
	int num;
	cin >> num;
	cout << funcaoF(num) << endl;
	
	return 0;
}
