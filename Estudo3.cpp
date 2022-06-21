#include <iostream>
using namespace std;

int binaria(int tam, int vetor[], int elemento){
	int inicio=0;
	int fim = tam-1;
	int meio, posicao=-1;
	while (inicio<= fim){
		meio=(inicio+fim)/2;
		if(elemento == vetor[meio]){
			posicao = meio;
			inicio=fim+1; 
		}
		else{
			if(elemento>vetor[meio]){
				inicio = meio+1;
			}
			else{
				fim = meio-1;
			}
		}
	}
	if(elemento==vetor[posicao]){
		return posicao;
	}
	else{
		return -1;
	}
}

int main(){
	int tamanho;
	cin >> tamanho;
	
	int vet[tamanho];
	for(int i=0; i<tamanho ; i++){
		cin >> vet[i];
	}
	
	int buscado;
	cin >> buscado;
	
	cout << binaria(tamanho, vet, buscado);
}
