#include <iostream>

using namespace std;

int selection_sort(int vetor[], int tam){
	int pos_menor;
	
	for(int i=0; i<tam-1 ; i++){
		pos_menor=i;
		for(int j=i+1 ; j<tam; j++ ){
			if(vetor[j]>vetor[pos_menor]){
				pos_menor=j;
			}
		}
		swap(vetor[i], vetor[pos_menor]);
	
		for(int i=0; i<tam ; i++){
		cout << vetor[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

int main(){
	int tamanho;
	
	cin >> tamanho;
	
	int vet[tamanho];
	
	for	(int i=0; i<tamanho ; i++){
		cin >> vet[i];
	}
	
	selection_sort(vet, tamanho);
	
	return 0;
}
