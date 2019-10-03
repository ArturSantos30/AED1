// Fila Dinâmica

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
    void print();
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
void Fila<T>::print(){
    No<T> *p = frente->getProx();
    while(p!=NULL){
        imprimirFileira(p->getItem());
        p = p->getProx();
    }
}

int main(){
    Fila<string> fila;
    fila.enfileirar("A");
    fila.enfileirar("E");
    fila.enfileirar("D");
    fila.enfileirar("1");
    fila.print();
    cout<<endl;
    cout<<"Desenfileirando\n";
    fila.desenfileirar();
    fila.print();
    cout<<endl;
    
    return 0;
}