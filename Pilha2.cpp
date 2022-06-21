#include <iostream>
using namespace std;




class pilhaDupla {
private:
    int topo1;
    int topo2;
    int tamanho1;
    int tamanho2;
    int dados[50];
public:
    pilhaDupla();
    void empilha(int escolha, int valor);
    int desempilha(int escolha); 
    bool vazia(int escolha); 
};


pilhaDupla::pilhaDupla() {
    tamanho1 = 0;
    tamanho2 = 0;
    topo1 = -1;
    topo2 = 50;
}

void pilhaDupla::empilha(int escolha, int valor) {
	int aux;
	aux= tamanho1+tamanho2;
    if(aux < 50){
    if(escolha == 1){
      dados[topo1 +1] = valor;
      tamanho1++;
      topo1++;
    }
    else if(escolha == 2){
    dados[topo2 -1] = valor;
   		tamanho2++;
        topo2--;
    }
    }
    else{
        cout << "INVALIDO" << endl;
    }
}

int pilhaDupla ::  desempilha(int escolha) {
    if(escolha == 1){
    if (vazia(1) == false){ 
		tamanho1--;
		topo1--;
		return dados[topo1 +1];
	}
	else{
		cout << "VAZIA" << endl;
		return 0;
	}
	}
    else if (escolha == 2){
       if(vazia(2) == false){
        tamanho2--;
        topo2++;
        return dados[topo2-1];
    }
    else{
    cout << "VAZIA" << endl;
    return 0;
    }
    }
	else{
    return 0;
    }
}

bool pilhaDupla::vazia(int escolha) {
    if (escolha == 1)
        return (tamanho1 == 0);
    else if (escolha == 2)
        return (tamanho2 == 0);
    return true;
}


int main() {
    pilhaDupla PP;
    char opcao;
    int escolha;
    int valor;

    do {
        cin >> opcao;
        switch (opcao) {
        case 'E':
            cin >> escolha >> valor;
            PP.empilha(escolha,valor);
            break;
        case 'D':
            cin >> escolha;
            if ( PP.vazia(escolha) ) cout << "VAZIA" << endl;
            else cout << PP.desempilha(escolha) << " ";
            break;
        }
    } while (opcao != 'T');

    return 0;
}
