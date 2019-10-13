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
    void print();
};

template <class T>
Pilha<T>::Pilha(){
    topo = new No<T>();
    fundo = topo;
}

template <class T>
No<T>* Pilha<T>::getTopo(){
    return topo;
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

template <class T>
void Pilha<T>::print(){
    No<T> *p = topo->getProx();
    while(p!=NULL){
        cout<< p->getItem()<<endl;
        p = p->getProx();
    }
}

int main(){
    Pilha<int> pilha;
    pilha.empilhar(1);
    pilha.empilhar(2);
    pilha.empilhar(3);
    pilha.empilhar(4);
    pilha.empilhar(5);
    pilha.print();

    cout<<"Desempilhando:\n";
    pilha.desempilhar();
    pilha.print();
    
    return 0;
}