#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

template <class T>
class NoAVL{
private:
  NoAVL<T> *esq;
  NoAVL<T> *dir;
  T item;
  int fb;
public:
  NoAVL();
  NoAVL(T &item);
  NoAVL<T> *&getEsq();
  NoAVL<T> *&getDir();
  T &getItem();
  int getFb();
  void setEsq(NoAVL<T> *&no);
  void setDir(NoAVL<T> *&no);
  void setItem(T &item);
  void setFb(int fb);
};
template <class T>
NoAVL<T>::NoAVL(){
  this->esq = NULL;
  this->dir = NULL;
  this->fb = 0;
}
template <class T>
NoAVL<T>::NoAVL(T &item){
  this->item = item;
  this->esq = NULL;
  this->dir = NULL;
  this->fb = 0;
}
template <class T>
NoAVL<T> *&NoAVL<T>::getEsq(){
  return esq;
}
template <class T>
NoAVL<T> *&NoAVL<T>::getDir(){
  return dir;
}
template <class T>
T &NoAVL<T>::getItem(){
  return item;
}
template <class T>
int NoAVL<T>::getFb(){
  return fb;
}
template <class T>
void NoAVL<T>::setEsq(NoAVL<T> *&no){
  esq = no;
}
template <class T>
void NoAVL<T>::setDir(NoAVL<T> *&no){
  dir = no;
}
template <class T>
void NoAVL<T>::setItem(T &item){
  this->item = item;
}
template <class T>
void NoAVL<T>::setFb(int fb){
  this->fb = fb;
}

template <class T>
class AVL{
private:
  NoAVL<T> *raiz;
  int insere(T &item, NoAVL<T> *&no);
  void RSE(NoAVL<T> *&noDesce);
  void RSD(NoAVL<T> *&noDesce);
  void RDE(NoAVL<T> *&noDesce);
  void RDD(NoAVL<T> *&noDesce);
  void percorrePre(NoAVL<T> *no);
  void percorrePos(NoAVL<T> *no);
  void percorreCentral(NoAVL<T> *no);
  void buscaProfundidade(string chave, NoAVL<T> *&no, int h);
  void busca(T item,NoAVL<T> *no);
public:
  AVL();
  void insere(T &item);
  void busca(T chave);
  void percorrePre();
  void percorrePos();
  void percorreCentral();
  void buscaProfundidade(string chave);

};
template <class T>
AVL<T>::AVL(){
  raiz = NULL;
}
template <class T>
void AVL<T>::insere(T &item){
  insere(item, raiz);
}
template <class T>
int AVL<T>::insere(T &item, NoAVL<T> *&no){
  if(no == NULL){
    no = new NoAVL<T>();
    no->setItem(item);
    return 1;
  }
  if(item.TAM<no->getItem().TAM){
    int conferidor = insere(item, no->getEsq());
    if(conferidor==1){ //inseriu na esquerda
      // cout<<"aqui"<<endl;
      if(no->getFb()==1){
        no->setFb(0);
        return 0;
      }
      else if(no->getFb()==0){
        no->setFb(-1);
      }
      else{
        if(no->getEsq()->getFb()==-1){
          RSD(no);
          no->setFb(0);
          // cout<<"RSD"<<endl;
          return 0;
        }
        else{
          if(no->getEsq()->getFb()!=0){
            // cout<<"RDD"<<endl;
            RDD(no);
            no->setFb(0);
            return 0;
          }
        }
      }
      return 1;
    }
  }
  if(item.TAM>no->getItem().TAM){
    int conferidor = insere(item, no->getDir());
    if(conferidor==1){ //inseriu na direita
      // cout<<"aqui"<<endl;
      if(no->getFb()==-1){
        no->setFb(0);
        return 0;
      }
      else if(no->getFb()==0){
        no->setFb(1);
      }
      else{
        if(no->getDir()->getFb()==1){
          RSE(no);
          no->setFb(0);
          // cout<<"RSE"<<endl;
          return 0;
        }
        else{
          if(no->getDir()->getFb()!=0){
            RDE(no);
            no->setFb(0);
            // cout<<"RDE"<<endl;
            return 0;
          }
        }
      }
      return 1;
    }
  }
  else if(item.TAM==no->getItem().TAM){
    return 0;
  }
  return 0;
}
template <class T>
void AVL<T>::RSE(NoAVL<T> *&noDesce){
  NoAVL<T> *p1= new NoAVL<T>();
  *p1 = *noDesce->getDir();
  noDesce->setDir(p1->getEsq());
  p1->getEsq()=noDesce;
  noDesce->setFb(0);
  noDesce = p1;
}

template <class T>
void AVL<T>::RSD(NoAVL<T> *&noDesce){
  NoAVL<T> *p1= new NoAVL<T>();
  *p1 = *noDesce->getEsq();
  noDesce->setEsq(p1->getDir());
  p1->getDir()=noDesce;
  noDesce->setFb(0);
  noDesce = p1;
}

template <class T>
void AVL<T>::RDE(NoAVL<T> *&noDesce){
  NoAVL<T> *p1= new NoAVL<T>();
  *p1 = *noDesce->getDir();
  NoAVL<T> *p2= new NoAVL<T>();
  *p2 = *p1->getEsq();
  p1->setEsq(p2->getDir());
  p2->setDir(p1);
  noDesce->setDir(p2->getEsq());
  p2->setEsq(noDesce);
  if(p2->getFb()== 1){
    noDesce->setFb(-1);
  }
  else{
    noDesce->setFb(0);
  }
  if(p2->getFb()== -1){
    p1->setFb(1);
  }
  else{
    p1->setFb(0);
  }
  noDesce = p2;
}
template <class T>
void AVL<T>::RDD(NoAVL<T> *&noDesce){
  NoAVL<T> *p1= new NoAVL<T>();
  *p1 = *noDesce->getEsq();
  NoAVL<T> *p2= new NoAVL<T>();
  *p2 = *p1->getDir();
  p1->setDir(p2->getEsq());
  p2->setEsq(p1);
  noDesce->setEsq(p2->getDir());
  p2->setDir(noDesce);
  if(p2->getFb()== -1){
    noDesce->setFb(1);
  }
  else{
    noDesce->setFb(0);
  }
  if(p2->getFb()== 1){
    p1->setFb(-1);
  }
  else{
    p1->setFb(0);
  }
  noDesce = p2;
}
template <class T>
void AVL<T>::percorrePre(){
  percorrePre(raiz);
}
template <class T>
void AVL<T>::percorrePre(NoAVL<T> *no){
  if(no!=NULL){
    no->getItem().print();
    percorrePre(no->getEsq());
    percorrePre(no->getDir());
  }
}

template <class T>
void AVL<T>::buscaProfundidade(string chave, NoAVL<T> *&no, int h){
  int tamChave = chave.size();
  if(no!=NULL){
    if(tamChave==no->getItem().TAM){
      cout<< h<<" ";
    }
    else{
      if(tamChave<no->getItem().TAM){
        buscaProfundidade(chave, no->getEsq(), h+1);
      }
      if(tamChave>no->getItem().TAM){
        buscaProfundidade(chave, no->getDir(), h+1);
      }
    }
  }
  else{
    cout<<"chave nao encontrada"<<endl;
  }
}
template <class T>
void AVL<T>::buscaProfundidade(string chave){
  buscaProfundidade(chave, raiz, 0);
}

template<class T>
void AVL<T>::busca(T item,NoAVL<T> *no){
    if(item.TAM == no->getItem().TAM){
        cout<<no->getItem().loadFactor()<<endl;
    }
    if(item.TAM > no->getItem().TAM){
        busca(item,no->getDir());
    }
    if(item.TAM < no->getItem().TAM){
        busca(item,no->getEsq());
    }
    if(no==NULL){
        cout<<""<<endl;
    }
}
template<class T>
void AVL<T>::busca(T item){
    busca(item,raiz);
}

// --------------------Implementação Nó Lista
template <class T>
class NoLista{
private:
    T item;
    NoLista *prox;
    NoLista *ant;
public:
    NoLista();
    NoLista(T);
    void setProx(NoLista<T>*);
    void setAnt(NoLista<T>*);
    void setItem(T);
    NoLista<T>* getProx();
    NoLista<T>* getAnt();
    T getItem();
};

template <class T>
NoLista<T>::NoLista(){
    prox = NULL;
    ant = NULL;
}
template <class T>
NoLista<T>::NoLista(T item){
    this->item = item;
    prox = NULL;
    ant = NULL;
}

template <class T>
void NoLista<T>::setProx(NoLista<T> *prox){
    this->prox = prox;
}
template <class T>
void NoLista<T>::setAnt(NoLista<T> *ant){
    this->ant = ant;
}
template <class T>
void NoLista<T>::setItem(T item){
    this->item = item;
}

template <class T>
NoLista<T>* NoLista<T>::getProx(){
    return prox;
}
template <class T>
NoLista<T>* NoLista<T>::getAnt(){
    return ant;
}
template <class T>
T NoLista<T>::getItem(){
    return item;
}
//------------------ fim Nó Lista

// ------------------INício LIsta
template <class T>
class Lista{
public:
    NoLista<T> *prim;
    NoLista<T> *ult;
public:
    Lista();
    void insere(T);
    NoLista<T>* busca(string);
    void remover(NoLista<T>*);
    void print();
    int estaVazia();
    int getQuantidade();
};

template<class T>
Lista<T>::Lista(){
    prim = new NoLista<T>();
    ult = prim;
}

template<class T>
void Lista<T>::insere(T item){
    NoLista<T>* aux = new NoLista<T>(item);
    ult->setProx(aux);
    aux->setAnt(ult);
    ult = aux;
}

template <class T>
NoLista<T>* Lista<T>::busca(string item){
    NoLista<T>* p = prim->getProx();
    while((p!=NULL)&&(p->getItem() != item)){
        p = p->getProx();
    }
    return p;
}

template <class T>
void Lista<T>::remover(NoLista<T> *NoListaParaRemover){
    if((NoListaParaRemover==NULL)&&(NoListaParaRemover==prim)){
        cout<<"Impossivel remocao"<<endl;
    }
    else{
        NoLista<T> *p = NoListaParaRemover->getAnt();
        p->setProx(NoListaParaRemover->getProx());
        if(p->getProx()==NULL){
            ult = p;
        }
        if((p==prim)&&(p->getProx()==ult)){
            ult = prim;
        }
        delete NoListaParaRemover;
    }
}

template<class T>
void Lista<T>::print(){
    NoLista<T> *p = prim->getProx();
    while(p!=NULL){
        cout<<p->getItem()<<endl;
        p = p->getProx();
    }
}

template<class T>
int Lista<T>::estaVazia(){
    if(prim==NULL)
        return 1;
    else
        return 0;
}

template<class T>
int Lista<T>::getQuantidade(){
    int cont = 0;
    NoLista<T> *p = prim->getProx();
    while(p!=NULL){
        cont++;
        p = p->getProx();
    }
    return cont;
}
//------------------ fim Lista

//------------------ Início Tabela Hash
class TabHash{
private:
	Lista<string> *tabela;
public:
    int TAM;
	TabHash();
	void insere(string);
	unsigned long long int pow(int, int);
	unsigned long long int converterChaveStringParaNatural(string);
	int funcaoHash(string);
	void print();
    NoLista<string>* busca(string);
    int estaVazia();
    int getQuantidade();
    float loadFactor();
};

TabHash::TabHash(){
    tabela = new Lista<string>[11];
    this->TAM = 0;
}

void TabHash::insere(string chave){
    int indice = funcaoHash(chave);
    tabela[indice].insere(chave);
    this->TAM = chave.size();
}

unsigned long long int TabHash::pow(int num, int expoente){
    unsigned long long int potencia = 1;
    for(int i = 1;i<=expoente;++i){
        potencia *= num;
    }
    return potencia;
}

void TabHash::print(){
	for(int i = 0;i<11;++i){
        if(!tabela[i].estaVazia()){
		  cout<<"\tPosicao "<<i<<" :\n";
		  tabela[i].print();
        }
	}
}

unsigned long long int TabHash::converterChaveStringParaNatural(string chave){
    int tam = chave.size();
    unsigned long long int soma = 0;
    for(int i = 0;i<tam;++i){
        soma += ((int)chave[i])*pow(31,tam-1-i);
    }
    return soma;
}

int TabHash::funcaoHash( string chave ){
    unsigned long long int k = converterChaveStringParaNatural(chave);
    int valorHash = k%11;
    return valorHash;
}

NoLista<string>* TabHash::busca(string chave){
    int indice = funcaoHash(chave);
    NoLista<string> *noDaChave = tabela[indice].busca( chave );
    return noDaChave;
}

int TabHash::estaVazia(){
    int check = 1;
    for(int i = 0;i<11;i++){
        if(!tabela[i].estaVazia()){
            check = 0;
            break;
        }
    }
    return check;
}

int TabHash::getQuantidade(){
    int cont = 0;
    for(int i = 0;i<11;i++){
        cont += tabela[i].getQuantidade();
    }
    return cont;
}

float TabHash::loadFactor(){
    float lf = getQuantidade()/11.0;
    return lf;
}

int main(){
    AVL<TabHash> arvore;
    ifstream arquivo;

    string linha;
    arquivo.open("chaves.txt");
    long unsigned int maiorString = 0;
    while(getline(arquivo,linha)){
        if(maiorString<linha.size())
            maiorString = linha.size();
    }
    arquivo.close();
    TabHash *tables = new TabHash[maiorString+1];

    arquivo.open("chaves.txt");
    while(getline(arquivo,linha)){
        tables[linha.size()].insere(linha);
    }
    arquivo.close();

    for(long unsigned int i = 1;i<=maiorString;i++){
        if(tables[i].TAM!=0)
            arvore.insere(tables[i]);
    }

    // arvore.percorrePre();
    // cin>>linha;

    // TabHash aux;
    // linha = "Peludo";
    // aux.insere(linha);
    // arvore.buscaProfundidade(linha);

    // NoAVL<TabHash> *no = arvore.busca(aux);
    // if(no!=NULL){
    //     // no->getItem().print();
    //     cout<<no->getItem().loadFactor()<<endl;
    // }
    // else{
    //     cout<<"chave nao encontrada \n";
    // }

    while(getline(cin,linha)){
        TabHash aux;

        aux.insere(linha);
        arvore.buscaProfundidade(linha);
        arvore.busca(aux);
    }
	return 0;
}
