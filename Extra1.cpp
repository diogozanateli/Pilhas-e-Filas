/* Classe pilha, um pilha (LIFO) implementada usando encadeamento
 *
 * by Joukim, 2017, Estruturas de Dados
 *
 */

#include <iostream>

using namespace std;

class noh {
friend class pilha;
private:
    int dado; // poderia ser outro tipo de variÃ¡vel
    noh* prox;
};

// pilha dinamicamente encadeada
class pilha {
private:
    noh* topo;
    int tamanho;

public:
    pilha();
    ~pilha();
    void push(int d) { empilha(d); }
    void empilha(int d);
    int pop() { return desempilha(); }
    int desempilha(); // retorna o topo da pilha
    int espia(); // espia o topo da pilha
    bool vazia();
    void limpaPilha(); //limpa a pilha
};


pilha::pilha() {
    tamanho = 0;
    topo = NULL;
}

pilha::~pilha() { // idÃªntica Ã  limpaPilha, mas sem impressÃ£o
    while (topo != NULL) {
        desempilha();
    }
}

void pilha::empilha(int d) {
    // primeiro criamos o novo nÃ³
    noh* temp = new noh;
    temp->dado = d;
    temp->prox = topo;
    topo = temp;
    tamanho++;
}

int pilha::desempilha() {
    int removido;
    noh* temp;
    removido = topo->dado;
    temp = topo;
    topo = topo->prox;
    delete temp;
    tamanho--;
    return removido;
}

int pilha::espia(){
    return topo->dado;
}

void pilha::limpaPilha(){
    while (topo != NULL) {
        cout << desempilha() << endl;
    }
}

bool pilha::vazia() {
    return (topo == NULL);
}

int acessaElemento(pilha& p1, int elemento){
int aux=0;
int buscado=elemento;
if(p1.vazia()){
      		 return -1;
    	}
	else{
		while(!p1.vazia()){
 		   aux++;
	if(p1.desempilha()==buscado){
        return aux;
    }
    }
    return -1;
   	}
	return 0;
}

int main() {
    pilha p1;
    int n, numero, elemento;
    cin >> n;

    while (n > 0) {
        cin >> numero;
        p1.empilha(numero);
        n--;
    }

    cin >> elemento;
    cout << acessaElemento(p1,elemento);

    cout << endl;

    return 0;
}
