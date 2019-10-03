//Equipe:
// Artur da Silva Santos 1615080247
// João Guilherme Silva Gomes 1615080300

#include <iostream>
using namespace std;

class ParIantecoAzuri{
public:
    string ianteco;
    string azuri;
};

class ParFuncaoLinha{
public:
    string funcao;
    int linha;
};

template <class T>
class No{
private:
    T item;
    No *prox;
    No *ant;
public:
    No();
    No(T);
    void setProx(No<T>*);
    void setAnt(No<T>*);
    void setItem(T);
    No<T>* getProx();
    No<T>* getAnt();
    T getItem();
};

template <class T>
No<T>::No(){
    prox = NULL;
    ant = NULL;
}
template <class T>
No<T>::No(T item){
    this->item = item;
    prox = NULL;
    ant = NULL;
}

template <class T>
void No<T>::setProx(No<T> *prox){
    this->prox = prox;
}
template <class T>
void No<T>::setAnt(No<T> *ant){
    this->ant = ant;
}
template <class T>
void No<T>::setItem(T item){
    this->item = item;
}

template <class T>
No<T>* No<T>::getProx(){
    return prox;
}
template <class T>
No<T>* No<T>::getAnt(){
    return ant;
}
template <class T>
T No<T>::getItem(){
    return item;
}

template <class T>
class Fila{
private:
    No<T> *frente;
    No<T> *tras;
public:
    Fila();
    No<T>* getFrente();
    No<T>* getTras();
    void enfileirar(T);
    void desenfileirar();
    void printFila();
};

template <class T>
Fila<T>::Fila(){
    frente = new No<T>();
    tras = frente;
}

template <class T>
No<T>* Fila<T>::getFrente(){
    return frente;
}
template <class T>
No<T>* Fila<T>::getTras(){
    return tras;
}

template <class T>
void Fila<T>::enfileirar(T item){
    tras->setProx(new No<T>());
    tras = tras->getProx();
    tras->setItem(item);
    tras->setProx(NULL);
}

template <class T>
void Fila<T>::desenfileirar(){
    No<T> *aux = frente;
    frente = frente->getProx();
    delete aux;
}

void imprimirFileira(string item){
    cout<<item;
}

template <class T>
void Fila<T>::printFila(){
    No<T> *p = frente->getProx();
    while(p!=NULL){
        imprimirFileira(p->getItem());
        p = p->getProx();
    }
}

template <class T>
class Pilha{
private:
    No<T>* topo;
    No<T>* fundo;
public:
    Pilha();
    No<T>* getTopo();
    No<T>* getFundo();
    void empilhar(T);
    T desempilhar();
    void printPilha();
};

template <class T>
Pilha<T>::Pilha(){
    topo = new No<T>();
    fundo = topo;
}

template <class T>
No<T>* Pilha<T>::getTopo(){
    return topo->getProx();
}
template <class T>
No<T>* Pilha<T>::getFundo(){
    return fundo;
}

template <class T>
void Pilha<T>::empilhar(T item){
    No<T> *aux = new No<T>();
    topo->setItem(item);
    aux->setProx(topo);
    topo = aux;
}

template <class T>
T Pilha<T>::desempilhar(){
    No<T> *aux = topo;
    topo = topo->getProx();
    T itemTopo = topo->getItem();
    delete aux;
    return itemTopo;
}

void imprimirItemDaPilha( string item){
    cout<<"\t"<<item<<endl;
}

template <class T>
void Pilha<T>::printPilha(){
    No<T> *p = topo->getProx();
    while(p!=NULL){
        imprimirItemDaPilha(p->getItem());
        p = p->getProx();
    }
}

template <class T>
class Lista{
public:
    No<T> *prim;    
    No<T> *ult;    
public:
    Lista();
    void inserir(T);
    No<T>* buscar(string);
    No<T>* buscarFuncao(string);
    void remover(No<T>*);
    void print();
    void printFuncao();
};

template<class T>
Lista<T>::Lista(){
    prim = new No<T>();
    ult = prim;
}

template<class T>
void Lista<T>::inserir(T item){
    No<T>* aux = new No<T>(item);
    ult->setProx(aux);
    aux->setAnt(ult);
    ult = aux;
}

template <class T>
No<T>* Lista<T>::buscar(string item){
    No<T>* p = prim->getProx();
    while((p!=NULL)&&(p->getItem().ianteco != item)){
        p = p->getProx();
    }
    return p;
}
template <class T>
No<T>* Lista<T>::buscarFuncao(string item){
    No<T>* p = prim->getProx();
    while((p!=NULL)&&(p->getItem().funcao != item)){
        p = p->getProx();
    }
    return p;
}

template <class T>
void Lista<T>::remover(No<T> *noParaRemover){
    if((noParaRemover==NULL)&&(noParaRemover==prim)){
        cout<<"Impossivel remocao"<<endl;
    }
    else{
        No<T> *p = noParaRemover->getAnt();
        p->setProx(noParaRemover->getProx());
        if(p->getProx()==NULL){
            ult = p;
        }
        if((p==prim)&&(p->getProx()==ult)){
            ult = prim;
        }
        delete noParaRemover;
    }
}

void imprimirParDeLetras(ParIantecoAzuri par){
    cout<<"Ianteco: "<<par.ianteco<<" | ";
    cout<<"Azuri: "<<par.azuri<<endl;
}
template<class T>
void Lista<T>::print(){
    No<T> *p = prim->getProx();
    while(p!=NULL){
        imprimirParDeLetras(p->getItem());
        p = p->getProx();
    }
}

void imprimirFuncaoLinha(ParFuncaoLinha par){
    cout<<"Funcao: "<<par.funcao<<" | ";
    cout<<"Linha: "<<par.linha<<endl;
}
template<class T>
void Lista<T>::printFuncao(){
    No<T> *p = prim->getProx();
    while(p!=NULL){
        imprimirFuncaoLinha(p->getItem());
        p = p->getProx();
    }
}

unsigned long long int pow(int num, int expoente){
    unsigned long long int potencia = 1;
    for(int i = 1;i<=expoente;++i){
        potencia *= num;
    }
    return potencia;
}

unsigned long long int converterChaveStringParaNatural(string chave){
    int tam = chave.size();
    unsigned long long int soma = 0;
    for(int i = 0;i<tam;++i){
        soma += ((int)chave[i])*pow(37,tam-1-i);
    }
    return soma;
}

int funcaoHash( string chave ){
    unsigned long long int k = converterChaveStringParaNatural( chave );
    int valorHash = k%7;
    return valorHash;
}

class TabelaHash{
private:
    Lista<ParIantecoAzuri> *dicionarioIantecoAzuri;
public:
    TabelaHash(int);
    void inserirNaTabela(ParIantecoAzuri);
    ParIantecoAzuri buscarNaTabela(string);
    void printarTabela();
};

TabelaHash::TabelaHash(int TAM){
    dicionarioIantecoAzuri = new Lista<ParIantecoAzuri>[TAM];
}

void TabelaHash::inserirNaTabela(ParIantecoAzuri par){
    int indice = funcaoHash(par.ianteco);
    dicionarioIantecoAzuri[indice].inserir(par);
}

ParIantecoAzuri TabelaHash::buscarNaTabela( string chave ){
    int indice = funcaoHash( chave );
    No<ParIantecoAzuri> *noDaChave = dicionarioIantecoAzuri[indice].buscar( chave );
    return noDaChave->getItem();
}

void TabelaHash::printarTabela(){
    for(int i = 0;i<7;++i){
        cout<<"\tIndice: "<<i<<endl;
        dicionarioIantecoAzuri[i].print();
    }
}

class TabelaFuncoes{
private:
    Lista<ParFuncaoLinha> *tabelaFuncoes;
public:
    TabelaFuncoes(int);
    void inserirFuncaoNaTabela(ParFuncaoLinha);
    ParFuncaoLinha buscarFuncaoNaTabela(string);
    void printarTabelaFuncoes();
};

TabelaFuncoes::TabelaFuncoes(int TAM){
    tabelaFuncoes = new Lista<ParFuncaoLinha>[TAM];
}

void TabelaFuncoes::inserirFuncaoNaTabela(ParFuncaoLinha par){
    int indice = funcaoHash(par.funcao);
    tabelaFuncoes[indice].inserir(par);
}

ParFuncaoLinha TabelaFuncoes::buscarFuncaoNaTabela( string chave ){
    int indice = funcaoHash( chave.substr(0,1) );
    No<ParFuncaoLinha> *noDaChave = tabelaFuncoes[indice].buscarFuncao( chave.substr(0,1) );
    return noDaChave->getItem();
}

void TabelaFuncoes::printarTabelaFuncoes(){
    for(int i = 0;i<7;++i){
        cout<<"\tIndice: "<<i<<endl;
        tabelaFuncoes[i].printFuncao();
    }
}

void carregarDicionario(TabelaHash &dicionario){
    ParIantecoAzuri pares[29] = {{":::","A"}, {".::","B"}, {":.:","C"}, {"::.","D"}, 
                               {":..","E"}, {".:.","F"}, {"..:","G"}, {"...","H"}, 
                               {"|::","I"}, {":|:","J"}, {"::|","K"}, {"|.:","L"}, 
                               {".|:","M"}, {".:|","N"}, {"|:.","O"}, {":|.","P"}, 
                               {":.|","Q"}, {"|..","R"}, {".|.","S"}, {"..|","T"}, 
                               {".||","U"}, {"|.|","V"}, {"||.","W"}, {"-.-","X"}, 
                               {".--","Y"}, {"--.","Z"}, {"---"," "}, {"~","~"}, {":˽˽",":˽˽"}};
  
    for(int i = 0;i<29;++i){
        dicionario.inserirNaTabela(pares[i]);
    }
}

void carregaTabelaFuncoes(TabelaFuncoes &tabelaFuncoes, string *codAzuri ,int tam){
    string linhaAzuri;
    ParFuncaoLinha par;
    for(int i=0;i<tam;++i){
        linhaAzuri = codAzuri[i];
        if( linhaAzuri.size()==3 && linhaAzuri[2]==':'){
            par.funcao = linhaAzuri.substr(0,1);
            par.linha = i;
            tabelaFuncoes.inserirFuncaoNaTabela(par);
        }
    }
}

bool confereSeEhEnfileira(string linhaDeCodigo){
    string enfileira = ":...:|.:.|::|.::..|::|..:::";
    return ( linhaDeCodigo.substr(6,27)==enfileira )?true:false;
}
bool confereSeEhDesenfileira(string linhaDeCodigo){
    string desenfileira = "::.:...|.:...:|.:.|::|.::..|::|..:::";
    return ( linhaDeCodigo.substr(6,36)==desenfileira )?true:false;
}
bool confereSeEhUmaFuncao(string linhaDeCodigo){
    return (linhaDeCodigo.substr(3,4) == "---:" && linhaDeCodigo.substr(0,6) != "------")?true:false;
}

void traduzirParaAzuri( Pilha<string> &codigoIanteco, TabelaHash &dicionario, string *codAzuri, int tam){
	string linhaDeCodigo, letraIanteco, letraAzuri;
	for(int i=tam-1;i>=0;--i){
		linhaDeCodigo = codigoIanteco.desempilhar();
		if(linhaDeCodigo.size()<2){
			codAzuri[i] = linhaDeCodigo;
		}
		else if(linhaDeCodigo.size()>15){
			if( confereSeEhEnfileira(linhaDeCodigo) ){
				letraIanteco = linhaDeCodigo.substr(36,3);
				letraAzuri = dicionario.buscarNaTabela(letraIanteco).azuri;
				codAzuri[i] = "  ENFILEIRA " + letraAzuri;
			}
			if( confereSeEhDesenfileira(linhaDeCodigo) ){
				codAzuri[i] = "  DESENFILEIRA";
			}
		}
		else{
			if( confereSeEhUmaFuncao(linhaDeCodigo)){
				letraIanteco = linhaDeCodigo.substr(0,3);
				letraAzuri = dicionario.buscarNaTabela(letraIanteco).azuri;
				codAzuri[i] = letraAzuri + " :";
			}
			else{
				letraIanteco = linhaDeCodigo.substr(6,3);
				letraAzuri = dicionario.buscarNaTabela(letraIanteco).azuri;
				codAzuri[i] = "  " + letraAzuri;
			}
		}
	}
}

void imprimirTraducao( Fila<string> &traducao){
    traducao.printFila();
    cout<<endl;
}

void processarCodigo( TabelaFuncoes &tabelaFuncoes, string *codAzuri){
    Fila<string> traducao;
    Pilha<int> chamadas;
    string linhaAzuri = "Z :";
    int pos = tabelaFuncoes.buscarFuncaoNaTabela(linhaAzuri).linha;
    chamadas.empilhar(pos);
    while( chamadas.getTopo()!=NULL || linhaAzuri.size()!=1){
        pos++;
        linhaAzuri = codAzuri[pos];
        if( linhaAzuri.size()>10 ){
            if( linhaAzuri.substr(2,9)=="ENFILEIRA"){
                traducao.enfileirar( linhaAzuri.substr(12,1));
            }
            else{
                traducao.desenfileirar();
            }
        }
        else{
            if( linhaAzuri.size()==3){
                chamadas.empilhar(pos);
                string funcao = linhaAzuri.substr(2,1) + " :";
                pos = tabelaFuncoes.buscarFuncaoNaTabela(funcao).linha;
            }
            else{
                pos = chamadas.desempilhar();
            }
        }
    }
    imprimirTraducao(traducao);
}

int main(){

	TabelaHash dicionario(7);
    carregarDicionario(dicionario);

    Pilha<string> codigoIanteco;
    string linhaDeCodigoIanteco;
    int tam = 0;
    do{
      getline(cin,linhaDeCodigoIanteco);
      codigoIanteco.empilhar(linhaDeCodigoIanteco);
      tam++;  
    } while ( linhaDeCodigoIanteco != "~");

    string *codAzuri = new string[tam];
    traduzirParaAzuri(codigoIanteco, dicionario, codAzuri, tam);
    
    TabelaFuncoes tabelaFuncoes(7);
    carregaTabelaFuncoes(tabelaFuncoes, codAzuri, tam);
    processarCodigo(tabelaFuncoes, codAzuri);

    return 0;
}