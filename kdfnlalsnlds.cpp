/*
 * Classe lista, uma lista dinamicamente encadeada
 *
 * by Joukim, 2017, Estruturas de Dados
 *
 */

#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Dado; // para facilitar a troca de int para outro tipo

class noh {
friend class lista;
private:
    const Dado dado; // dado é constante para não permitir alteração do valor
    noh* proximo;
public:
    //noh();
    noh(Dado d = 0);
};


// lista dinamicamente encadeada
class lista {
private:
    noh* primeiro;
    noh* ultimo;
    int tamanho;

public:
    lista();
    ~lista();
    void insere(Dado dado);
    void insereNoFim(Dado dado);
    void insereNoInicio(Dado dado);
    void insereNaPosicao(int posicao, Dado dado);
    void insere(lista& L2, int pos);
    inline bool vazia();
    void remove(int posicao);
    int procura(Dado valor);
    int removeInicio(); // retorna a posicao
    void imprime();
    noh* acessaPosicao(int posicao); //
};


// construindo dado chamando seu construtor
noh::noh(Dado d) : dado(d) {
    proximo = NULL;
}

// constrói uma lista inicialmente vazia
lista::lista() {
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

// insere por padrão no final da lista
void lista::insere(Dado dado) {
    insereNoFim(dado);
}

// insere por no final da lista
void lista::insereNoFim(Dado dado) {
  noh* novo = new noh(dado);
  if(!vazia()){
    ultimo -> proximo = novo;
    ultimo = novo;
  }
  else{
    ultimo = novo;
    primeiro = novo;
  }
  tamanho++;
}

// insere no início da lista
void lista::insereNoInicio(Dado dado) {
}

// insere em uma determinada posição da lista
void lista::insereNaPosicao(int posicao, Dado dado){
    // * primeiro criamos o novo nó
    noh* novo = new noh(dado);

    // * agora inserimos o nó na lista
    // verificamos antes se é possível inserir na posição
    if ( (posicao <= tamanho) and (posicao >= 0) ) {
        if ( vazia() ) { // ou (primeiro == NULL) ou (tamanho == 0)
            primeiro = novo;
            ultimo = novo;
        } else if (posicao == 0) { // insere no início
            novo->proximo = primeiro;
            primeiro = novo;
        } else if (posicao == tamanho) { // insere no fim
            ultimo->proximo = novo;
            ultimo = novo;
        } else { // insere no meio da lista
            noh* aux = primeiro;
            int posAux = 0;

            // chegando na posicao da lista
            while ( posAux < (posicao-1) ) {
                aux = aux->proximo;
                posAux++;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        tamanho++;
    } else {
        cerr << "Posição Inexistente!" << endl;
        exit(EXIT_FAILURE);
    }
}


void lista::insere(lista &L2, int pos) {
    lista lista2 = L2;
    int aux = 0;
    int posicao = pos;

for(int i = 0;i < posicao;i++){
   insereNoFim(removeInicio());
}
     while(lista2.vazia() == true){
            insereNoFim(lista2.removeInicio());
            aux++;
    }
int novaPosicao = posicao + aux;    
       for(int i=0; i < tamanho - novaPosicao ; i++){
            insereNoFim(removeInicio());
       }
}


// verifica se a lista está vazia
inline bool lista::vazia() {
    return (primeiro == NULL);
}


// destrutor
lista::~lista( ) {
    noh* aux = primeiro;
    noh* temp;

    while (aux != NULL) {
        temp = aux;
        aux = aux->proximo;
        delete temp;
    }
    // não é necessário, mas evita problemas
    primeiro = NULL;
    ultimo = NULL;
}

void lista::remove(int posicao) {
    if ( (posicao < tamanho) and (posicao >= 0) ) {
        cout << tamanho << endl;
        if (posicao == 0) { // primeiro elemento
            noh* aux = primeiro;
            primeiro = primeiro->proximo;
            delete aux;
        } else { // não é o primeiro, precisa percorrer
            noh* aux = primeiro->proximo;
            noh* ant = primeiro;
            int posAux = 1;
            while ((aux != NULL) and (posAux < posicao)) {
                ant = aux;
                aux = aux->proximo;
                posAux++;
            }
            if (aux == ultimo) {
                ant->proximo = NULL;
                ultimo = ant;
                delete aux;

            } else {
                ant->proximo = aux->proximo;
                delete aux;
            }
        }
        tamanho--;
    } else { // acesso a posição inexistente
        cerr << "Posição Inexistente!" << endl;
        exit(EXIT_FAILURE);
    }
}

int lista::procura(Dado valor) {
    noh* aux = primeiro;
    int posAux = 0;

    while ((aux != NULL) and (aux->dado != valor)) {
        posAux++;
        aux = aux->proximo;
    }

    if (aux == NULL) {
        posAux = -1;
    }
    return posAux;
}

int lista :: removeInicio(){
  if(!vazia()){
    tamanho--;
    noh* aux =  primeiro;
    int removido = primeiro -> dado;
    primeiro = primeiro -> proximo;
    return removido;
    delete aux;
  }
  else{
    cout << "LISTA VAZIA";
  }
return 0;
}

// método básico que percorre uma lista, imprimindo seus elementos
void lista::imprime() {
    noh* aux = primeiro;

    while (aux != NULL) {
        cout << aux->dado << " ";
        aux = aux->proximo;
    }

    cout << endl;
}


int main() {
    lista L1;
    lista L2;

    int valor;
    int pos;
    int num;

    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> valor;
        L1.insere(valor);
    }
    // L1.imprime();

    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> valor;
        L2.insere(valor);
    }
    // L2.imprime();

    cin >> pos;

    L1.insere(L2, pos);

    L1.imprime();

    return 0;
}
