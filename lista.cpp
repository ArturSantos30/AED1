// Lista Duplamente encadeada

#include <iostream>
using namespace std;

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
class Lista{
public:
    No<T> *prim;    
    No<T> *ult;    
public:
    Lista();
    void inserir(T);
    No<T>* buscar(T);
    void remover(No<T>*);
    void print();
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
No<T>* Lista<T>::buscar(T item){
    No<T>* p = prim->getProx();
    while((p!=NULL)&&(p->getItem() != item)){
        p = p->getProx();
    }
    return p;
}

template <class T>
void Lista<T>::remover(No<T> *r){
    if((r==NULL)&&(r==prim)){
        cout<<"Impossivel remocao"<<endl;
    }
    else{
        No<T> *p = r->getAnt();
        p->setProx(r->getProx());
        if(p==NULL){
            ult = p;
        }
        if((p==prim)&&(p->getProx()==ult)){
            ult = prim;
        }
        delete r;
    }
}

template<class T>
void Lista<T>::print(){
    No<T> *p = prim->getProx();
    while(p!=NULL){
        cout<< p->getItem()<<endl;
        p = p->getProx();
    }
}

int main(){
    Lista<int> lista;
    lista.inserir(1);
    lista.inserir(2);
    lista.inserir(3);
    lista.inserir(4);
    lista.inserir(5);
    lista.print();

    cout<<"Buscando item\n";
    No<int> *r = lista.buscar(3);

    cout<<"Removendo item\n";
    lista.remover(r);
    lista.print();
    
    return 0;
}