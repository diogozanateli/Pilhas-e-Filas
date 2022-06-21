#include <iostream>
#include <string>

using namespace std;

// Um Noh guarda um par (chave => valor) em uma tabela
class Noh {
    public:
        string mChave;
        string mValor;
        Noh* mProximo;
        Noh(const string& chave = "", const string& valor = "", Noh* proximo = NULL) :
            mChave(chave), mValor(valor), mProximo(proximo) {
        }
};

// Uma lista guarda todos os Nos cuja chave foi mapeada na mesma posição.
class ListaAux {
    public:
        Noh* mPrimeiro; // primeiro nó da ListaAux
        short int Tamanho() { return mTamanho; } // Consulta do Tamanho
        ListaAux() : mPrimeiro(NULL), mTamanho(0) {} // construtor
        void Inicializar() {
            mPrimeiro = NULL;
            mTamanho = 0;
        }
        // Adiciona um Noh a uma lista.
        void Adicionar(Noh* novoNoh) {
            novoNoh->mProximo = mPrimeiro;
            mPrimeiro = novoNoh;
            ++mTamanho;
        }
        // Remove o Noh com dada chave da lista.
        // Se a chave não existe, escreve uma mensagem de erro.
        void Remover(string chave) {
            Noh* atual = mPrimeiro;
            Noh* anterior = NULL;
            while ((atual != NULL) and (atual->mChave != chave)) {
                anterior = atual;
                atual = atual->mProximo;
            }
            if (atual != NULL) {
                if (anterior == NULL)
                    mPrimeiro = atual->mProximo;
                else
                    anterior->mProximo = atual->mProximo;
                delete atual;
                --mTamanho;
            }
            else
                cerr << "ERRO NA REMOÇÃO!" << endl;
        }
    private:
        short int mTamanho; // quantidade de valores na ListaAux
};

class Hash {
    public:
        // construtor padrão
        Hash(int cap = 100) {
            mElementos = new ListaAux[cap];
            mNroPosicoes = cap;
            for (int i = 0; i < cap; ++i)
                mElementos[i].Inicializar();
        }
        // destrutor
        ~Hash(){
            for (int i = 0; i < mNroPosicoes; ++i) {
                Noh* atual = mElementos[i].mPrimeiro;
                // EscreverEstrutura a lista removendo todos os nós
                while (atual != NULL) {
                    Noh* aux = atual;
                    atual = atual->mProximo;
                    delete aux;
                }
            }
            delete[] mElementos;
        }
        // Insere um nó com dada chave e valor.
        void Inserir(const string& chave, const string& valor) {
            if (Valor(chave) == "NÃO ENCONTRADO!") {
                unsigned int pos = Posicao(chave);
                while (mElementos[pos].Tamanho() > 4) {
                    int novoNroListas  = int(float(mNroPosicoes)*1.05f) + 1;
                    cout << "\n";
                    EscreverEstrutura();
                    cout << "\nÉ necessario redimensionar de " << mNroPosicoes << " para " << novoNroListas << "\n\n";
                    Redimensionar(novoNroListas);
                    EscreverEstrutura();
                    cout << "\n";
                    pos = Posicao(chave); // recalcular a posicao na nova estrutura
                }
                mElementos[pos].Adicionar(new Noh(chave, valor));
                cout << "chave '" << chave << "' inserida na posicao " << pos << endl;
            }
            else
                cout << "ITEM JÁ ESTÁ NA TABELA!" << endl;
        }
        // Retorna um valor associado a uma dada chave.
        // Se a chave não existe, retorna "NÃO ENCONTRADO!".
        string Valor(string chave) {
            Noh* atual = mElementos[Posicao(chave)].mPrimeiro;
            while ((atual != NULL) and (atual->mChave != chave))
                atual = atual->mProximo;
            if (atual == NULL)
                return "NÃO ENCONTRADO!";
            else
                return atual->mValor;
        }
        // Altera o valor associado a uma chave
        void Alterar(string chave, string valor) {
            Noh* atual = mElementos[Posicao(chave)].mPrimeiro;
            while ((atual != NULL) and (atual->mChave != chave))
                atual = atual->mProximo;
            if (atual == NULL)
                cerr << "ERRO NA ALTERAÇÃO!" << endl;
            else
                atual->mValor = valor;
        }
        // Retira do hash um nó com dada chave.
        // Se a chave não existe, escreve uma mensagem de erro.
        void Remover(string chave) {
            mElementos[Posicao(chave)].Remover(chave);
        }
        // Escreve o conteúdo interno do hash (para fins de debug)
        void EscreverEstrutura() {
            Noh* atual = NULL;
            for (int i = 0; i < mNroPosicoes; ++i) {
                cout << i << ": ";
                atual = mElementos[i].mPrimeiro;
                while (atual != NULL) {
                    cout << "[" << atual->mChave << "/"
                         << atual->mValor << "]->";
                    atual = atual->mProximo;
                }
                cout << "NULL" << endl;
            }
        }
    private:
        // vetor de ponteiros para lista
        ListaAux* mElementos;
        // quantidade de posições na tabela hash
        int mNroPosicoes;
        // converte uma chave (string) num endereço da tabela - versão simples
        unsigned int Posicao(const string& s) {
            return Posicao(s, mNroPosicoes);
        }
        // converte uma chave (string) num endereço da tabela - versão para redimensionamento
        unsigned int Posicao(const string& s, int cap) {
            unsigned int pos = 0;
            unsigned int tamanho = unsigned(s.length());
            for (unsigned int i = 0; i < tamanho; ++i)
                pos = (7 * pos + s[i]) % cap;
            return pos;
        }
        // altera a quantidade de endereços da tabela e passa todos os nós para a nova estrutura
        void Redimensionar(int qtdePos) {
            //
            // Coloque aqui o código que faz o redimensionamento!
            //
        }
};

int main( ) {
    Hash tabela(10); // cria uma tabela com 10 endereços
    tabela.Inserir("32", "trinta e dois");
    tabela.Inserir("128", "cento e vinte e oito");
    tabela.Inserir("16", "dezesseis");
    tabela.Inserir("4", "quatro");
    tabela.Inserir("9", "nove");
    tabela.Inserir("11", "onze");
    tabela.Inserir("21", "vinte e um");
    tabela.Inserir("24", "vinte e quatro");
    tabela.Inserir("115", "cento e quinze"); // quinto elemento na posição 7
    tabela.Inserir("2001", "dois mil e um"); // causa redimensionamento porque deixaria 6 elementos na posição 7

    cout << endl;
    tabela.EscreverEstrutura();

    return 0;
}
