#include <iostream>
#include <string>

using namespace std;

class noh {
friend class pilha;
private:
    int dado; // poderia ser outro tipo de variável
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
    void TROCA();
};


pilha::pilha() {
    tamanho = 0;
    topo = NULL;
}

pilha::~pilha() { // idêntica ?  limpaPilha, mas sem impressão
    while (topo != NULL) {
        desempilha();
    }
}

void pilha::empilha(int d) {
   
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

void pilha :: TROCA(){
         pilha A, B;

			while(!vazia()){
       A.empilha(desempilha());
    }
			while(A.vazia() != true){
        B.empilha(A.desempilha());
    }
			while(B.vazia() != true){
        empilha(B.desempilha());
    }
}

int main() {
    pilha p1;
    int n;
    cin >> n;
    int valor;

    while (n != 0) {
        cin >> valor;
        p1.empilha(valor);
        n--;
    }

    p1.TROCA();

    while (not p1.vazia()) {
        cout << p1.desempilha() << " ";
    }
    cout << endl;

    return 0;
}

