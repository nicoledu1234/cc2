#include<iostream>
using namespace std;

template<class T>
class nodo {
    public:
    T valor;
   nodo* next;
    nodo(T v, nodo* n = NULL){
        valor = v;
        next =n;
    }
};


template<class T>
class pila {
    public:
    nodo<T>* head;
    nodo<T>* tail;
    pila(){
        head = NULL;
        tail = NULL;
    }

    void push(T valor) {
        if(!head){
            head = new nodo<T>(valor,head);
            tail=head;
        }
        else{
            head=new nodo<T>(valor,head);
            head->next=tail;
            tail=head;
        }

    }

    T pop() {
        if(!head){
            cout<<"vacia"<<endl;
            return 0;
        }
        nodo<T> *temp=head;
        T r=head->valor;
        head=head->next;
        tail =head;
        delete temp;
        return r;

    }

    void print(){
    cout<<endl;
    for(nodo<T> *p=head;p;p=p->next){
        if(p->next)
            cout<<p->valor<<" -> ";
        else
            cout<<p->valor;
    }
    cout<<endl;
    }

};
int main()
{
   pila<int> l;
   l.push(1);
   l.print();
   l.push(5);
  l.print();
   l.push(7);
  l.print();
   l.push(11);
  l.print();
   l.push(16);
  l.print();
   l.push(20);
  l.print();
cout<<"---------------------------------------------"<<endl;
   pila<int> l1;
   l1.push(3);
   l1.print();
   l1.push(8);
  l1.print();
   l1.push(10);
  l1.print();
   l1.push(15);
  l1.print();

    return 0;
}
