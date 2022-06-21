#include <iostream>
using namespace std;

void percorre(int vetor[],int tamanho){
    for(int i=0;i<tamanho;i++){
        cin >> vetor[i];
    }
}

void imprime(int vetor[], int tamanho){
    for(int i=0;i<tamanho;i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
}

void Selection_Sort(int vetor[], int tamanho){
    int pos_menor;
	if(tamanho%2 == 0){
	for(int i=0; i< (tamanho/2)-1;i++){
       pos_menor = i;
      for(int j= i + 1;j< (tamanho/2);j++){
    if(vetor[j] < vetor[pos_menor]){
       pos_menor = j;
    }
    }
    swap(vetor[i],vetor[pos_menor]);
    }
    
    for(int i= (tamanho/2); i< tamanho-1;i++){
    	pos_menor = i;
    for(int j= i + 1;j< tamanho;j++){
    	if(vetor[j] > vetor[pos_menor]){
            pos_menor = j;
        }
    }
    swap(vetor[i],vetor[pos_menor]);
    }
    }
    
    else{
    for(int i=0; i< (tamanho/2);i++){
    	pos_menor = i;
    for(int j= i + 1;j< (tamanho/2)+1;j++){
        if(vetor[j] < vetor[pos_menor]){
        pos_menor = j;
        }
    }
    swap(vetor[i],vetor[pos_menor]);
    }
    for(int i= (tamanho/2)+1; i< tamanho-1;i++){
        pos_menor = i;
    for(int j= i + 1;j<tamanho;j++){
        if(vetor[j] > vetor[pos_menor]){
        pos_menor = j;
        }
    }
    swap(vetor[i],vetor[pos_menor]);
    }
    }
}

int main(){
    int tamanho;
    cin >> tamanho;
	int vetor[tamanho];

    percorre(vetor,tamanho);
    Selection_Sort(vetor,tamanho);
    imprime(vetor, tamanho);

return 0;
}

