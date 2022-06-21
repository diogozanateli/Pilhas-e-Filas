#include <iostream>
using namespace std;
void selection(int vet[], int capacidade){
	int pos_menor;
	int aux;
	for(int i=capacidade; i>=0; i--){
		pos_menor=i;
		for(int j=i-1; j>=0; j--){
			if(vet[j] < vet[pos_menor]){
				pos_menor=j;
			}
		}
		swap(vet[i], vet[pos_menor]);
		for(int i=1; i<capacidade+1; i++){
		cout << vet[i] << " ";
	}
	cout << endl;
	}
}
	
int main (){
	int tamanho;
	cin >> tamanho;
	int vetor[tamanho];
	
	for(int i=0; i<tamanho ; i++){
		vetor[i]=0;
	}
	
	for(int i=0; i<tamanho; i++){
		cin >> vetor[i];
	}
	
	selection(vetor, tamanho);

	return 0;
}
